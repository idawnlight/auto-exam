/**
 * @project Automatic Examination
 * @file EditWindow.cpp
 * @location src/ui/window
 * @brief Window for setup paper
 * @date 2022/8/12
 */

#include <fstream>
#include "EditWindow.h"

EditWindow::EditWindow(QWidget *parent)
    : QWidget(parent), leftInfoLayout(new EditInfoLayout()), problemEditor(new ProblemEditor()),
      problemLabel(new ProblemLabel()), paper(std::make_shared<Paper>()) {
    auto mainLayout = new QHBoxLayout();
    setLayout(mainLayout);
    setWindowTitle("制卷 - 自动考试系统");
    setFixedSize(1200, 600);

    // Left Part: Overview
    auto leftLayout = new QVBoxLayout();
    auto leftHeader = new QLabel("<h2>总览</h2>");
    leftLayout->addWidget(leftHeader);

    leftLayout->addLayout(leftInfoLayout);

    leftLayout->addStretch();
    auto leftBottomButtonGroup = new QHBoxLayout();
    leftLayout->addLayout(leftBottomButtonGroup);
    auto importButton = new QPushButton("导入");
    auto exportButton = new QPushButton("导出");
    leftBottomButtonGroup->addWidget(importButton);
    leftBottomButtonGroup->addWidget(exportButton);

    connect(importButton, &QAbstractButton::clicked, this, &EditWindow::importPaper);
    connect(exportButton, &QAbstractButton::clicked, this, &EditWindow::exportPaper);

    // Center Part: Main Editor
    auto centerLayout = new QVBoxLayout();
    centerLayout->addWidget(problemLabel);
    centerLayout->addLayout(problemEditor);
    connect(problemEditor, &ProblemEditor::problemChanged, problemLabel, &ProblemLabel::setProblem);
    connect(problemEditor, &ProblemEditor::problemChanged, this, &EditWindow::paperChangedShim);

    // Right Part: Problem Indicator / Navigator
//    paper = std::make_shared<Paper>();
//    paper->mock();
    problemIndicator = new ProblemIndicatorWidget(paper);
    auto rightLayout = new QVBoxLayout();
    rightLayout->addWidget(problemIndicator);
    connect(problemIndicator, &ProblemIndicatorWidget::selectionChanged, problemEditor, &ProblemEditor::setProblem);
    connect(problemIndicator, &ProblemIndicatorWidget::paperChanged, this, &EditWindow::paperChanged);
    connect(this, &EditWindow::paperChanged, leftInfoLayout, &EditInfoLayout::updateEditInfo);
    problemIndicator->touchPaper();

    connect(problemEditor, &ProblemEditor::removeProblem, problemIndicator, &ProblemIndicatorWidget::removeProblem);
    connect(problemEditor, &ProblemEditor::navigateProblem, problemIndicator, &ProblemIndicatorWidget::navigateProblem);

    // Split layouts
    mainLayout->addLayout(leftLayout, 1);
    mainLayout->setAlignment(leftLayout, Qt::AlignTop);
    mainLayout->addLayout(centerLayout, 2);
    mainLayout->setAlignment(centerLayout, Qt::AlignTop);
    mainLayout->addLayout(rightLayout, 1);

//    auto rightLabel = new QLabel("<h2>选择</h2>");

//    rightLayout->addWidget(rightLabel);

}

void EditWindow::paperChangedShim() {
    emit paperChanged(paper);
}

void EditWindow::exportPaper() {
    QString fileName = QFileDialog::getSaveFileName(this, "保存试卷", "paper.json", "JSON Paper (*.json *.paper)");

    if (fileName != "") {
        QFile file(fileName);
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
            return;

        QTextStream out(&file);
        out << QString::fromStdString(this->paper->toJson().dump(4));
    }
}

void EditWindow::importPaper() {
    QString fileName = QFileDialog::getOpenFileName(this, tr("导入试卷"), "", "JSON Paper (*.json *.paper)");

    if (fileName != "") {
        std::ifstream f(fileName.toStdString());
        json data = json::parse(f);

        try {
            paper = std::make_shared<Paper>(Paper::fromJson(data));
            problemIndicator->setAnswerPaper(std::make_shared<AnswerPaper>(paper));
        } catch (std::exception e) {
            QMessageBox::critical(this, "导入失败", "所选择的试卷无效或存在错误。", QMessageBox::Ok);
        }
    }
}
