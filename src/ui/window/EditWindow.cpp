/**
 * @project Automatic Examination
 * @file EditWindow.cpp
 * @location src/ui/window
 * @brief Window for setup paper
 * @date 2022/8/12
 */

#include "EditWindow.h"

EditWindow::EditWindow(QWidget *parent)
    : QWidget(parent), leftInfoLayout(new EditInfoLayout()), problemEditor(new ProblemEditor()) {
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

    // Center Part: Main Editor
    auto centerLayout = new QVBoxLayout();
    auto centerLabel = new QLabel("<h2>当前题目</h2>");
    centerLayout->addWidget(centerLabel);
    centerLayout->addLayout(problemEditor);

    // Right Part: Problem Indicator / Navigator
    paper = std::make_shared<Paper>();
    paper->mock();
    auto problemIndicator = new ProblemIndicatorWidget(paper);
    auto rightLayout = new QVBoxLayout();
    rightLayout->addWidget(problemIndicator);
    connect(problemIndicator, &ProblemIndicatorWidget::problemChanged, problemEditor, &ProblemEditor::setProblem);

    // Split layouts
    mainLayout->addLayout(leftLayout, 1);
    mainLayout->setAlignment(leftLayout, Qt::AlignTop);
    mainLayout->addLayout(centerLayout, 2);
    mainLayout->setAlignment(centerLayout, Qt::AlignTop);
    mainLayout->addLayout(rightLayout, 1);

//    auto rightLabel = new QLabel("<h2>选择</h2>");

//    rightLayout->addWidget(rightLabel);

}

void EditWindow::show() {
    QWidget::show();
}
