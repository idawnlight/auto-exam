/**
 * @project Automatic Examination
 * @file SetupWindow.cpp
 * @location src/ui/window
 * @brief Window for setup paper
 * @date 2022/8/12
 */

#include "SetupWindow.h"

SetupWindow::SetupWindow(QWidget *parent) {
    auto mainLayout = new QHBoxLayout();
    setLayout(mainLayout);
    setWindowTitle("制卷 - 自动考试系统");
    setFixedSize(1200, 600);

    // Problem Indicator
    auto answerPaper = std::make_shared<AnswerPaper>();
    auto problemIndicator = new ProblemIndicatorWidget(answerPaper);
    auto rightLayout = new QVBoxLayout();
    rightLayout->addWidget(problemIndicator);

    // Split layouts
    auto leftLayout = new QVBoxLayout();
    auto centerLayout = new QVBoxLayout();

    mainLayout->addLayout(leftLayout, 1);
    mainLayout->setAlignment(leftLayout, Qt::AlignTop);
    mainLayout->addLayout(centerLayout, 2);
    mainLayout->setAlignment(centerLayout, Qt::AlignTop);
    mainLayout->addLayout(rightLayout, 1);

    auto leftLabel = new QLabel("<h2>选择</h2>");
    auto centerLabel = new QLabel("<h2>选择</h2>");
//    auto rightLabel = new QLabel("<h2>选择</h2>");

    leftLayout->addWidget(leftLabel);
    centerLayout->addWidget(centerLabel);
//    rightLayout->addWidget(rightLabel);

}

void SetupWindow::show() {
    QWidget::show();
}
