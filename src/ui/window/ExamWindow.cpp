/**
 * @project Automatic Examination
 * @file ExamWindow.cpp
 * @location src/ui/window
 * @brief Window for examination
 * @date 2022/8/12
 */

#include <fstream>
#include "ExamWindow.h"

ExamWindow::ExamWindow(QWidget *parent)
    : QWidget(parent), leftInfoLayout(new ExamInfoLayout()), problemViewer(new ProblemViewer()),
      problemLabel(new ProblemLabel()), paper(std::make_shared<Paper>()) {
    auto mainLayout = new QHBoxLayout();
    setLayout(mainLayout);
    setWindowTitle("答题 - 自动考试系统");
    setFixedSize(1200, 600);

    // Left Part: Overview
    auto leftLayout = new QVBoxLayout();
    auto leftHeader = new QLabel("<h2>总览</h2>");
    leftLayout->addWidget(leftHeader);

    leftLayout->addLayout(leftInfoLayout);

    leftLayout->addStretch();
    auto leftBottomButtonGroup = new QHBoxLayout();
    leftLayout->addLayout(leftBottomButtonGroup);
    submitButton = new QPushButton("交卷");
    leftBottomButtonGroup->addWidget(submitButton);

    connect(submitButton, &QAbstractButton::clicked, this, &ExamWindow::evaluate);

    // Center Part: Main Editor
    auto centerLayout = new QVBoxLayout();
    centerLayout->addWidget(problemLabel);
    centerLayout->addLayout(problemViewer);
    connect(problemViewer, &ProblemViewer::problemChanged, problemLabel, &ProblemLabel::setProblem);
    connect(problemViewer, &ProblemViewer::problemChanged, this, &ExamWindow::paperChangedShim);

    // Right Part: Problem Indicator / Navigator
//    paper = std::make_shared<Paper>();
//    paper->mock();
    problemIndicator = new ProblemIndicatorWidget(paper);
    auto rightLayout = new QVBoxLayout();
    rightLayout->addWidget(problemIndicator);
    connect(problemIndicator, &ProblemIndicatorWidget::selectionChanged, problemViewer, &ProblemViewer::setProblem);
    connect(problemIndicator, &ProblemIndicatorWidget::paperChanged, this, &ExamWindow::paperChanged);
    connect(this, &ExamWindow::paperChanged, leftInfoLayout, &ExamInfoLayout::updateExamInfo);

    connect(problemViewer, &ProblemViewer::answerChanged, problemIndicator, &ProblemIndicatorWidget::setAnswer);
    connect(problemViewer, &ProblemViewer::navigateProblem, problemIndicator, &ProblemIndicatorWidget::navigateProblem);

    // Split layouts
    mainLayout->addLayout(leftLayout, 1);
    mainLayout->setAlignment(leftLayout, Qt::AlignTop);
    mainLayout->addLayout(centerLayout, 2);
    mainLayout->setAlignment(centerLayout, Qt::AlignTop);
    mainLayout->addLayout(rightLayout, 1);
}

void ExamWindow::paperChangedShim() {
    emit paperChanged(paper);
}

void ExamWindow::evaluate() {
    submitButton->setDisabled(true);
    submitButton->setText("已交卷");
    problemViewer->setEvaluated();

    double score = problemIndicator->evaluate();

    leftInfoLayout->setScore(score);

//    qDebug() << "evaluate";
//    qDebug() << score;
}

void ExamWindow::show() {
    QString fileName = QFileDialog::getOpenFileName(this, "打开试卷", "", "JSON Paper (*.json *.paper)");

    if (fileName != "") {
        std::ifstream f(fileName.toStdString());
        json data = json::parse(f);

//        try {
            paper = std::make_shared<Paper>(Paper::fromJson(data));
            problemIndicator->setAnswerPaper(std::make_shared<AnswerPaper>(paper));

            QWidget::show();
//        } catch (std::exception e) {
//            QMessageBox::critical(this, "打开失败", "所选择的试卷无效或存在错误。", QMessageBox::Ok);
//        }
    }
}
