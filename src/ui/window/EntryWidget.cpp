/**
 * @project Automatic Examination
 * @file EntryWidget.cpp
 * @location src/ui/window
 * @brief EntryWidget for selection
 * @date 2022/8/12
 */

#include "EntryWidget.h"

EntryWidget::EntryWidget(QWidget *parent) {
    auto mainLayout = new QVBoxLayout();
    setLayout(mainLayout);
    setWindowTitle("选择 - 自动考试系统");
    setMinimumWidth(300);

    // Title
//    auto titleLabel = new QLabel("<h2>选择</h2>");
//    mainLayout->addWidget(titleLabel);

    // Selections
    auto setupButton = new QPushButton("制卷");
    mainLayout->addWidget(setupButton);

    auto examButton = new QPushButton("答题");
    mainLayout->addWidget(examButton);

    // Connect signals
    connect(setupButton, &QPushButton::clicked, this, &EntryWidget::setupPaper);
    connect(examButton, &QPushButton::clicked, this, &EntryWidget::startExam);

    // Close window on click
    connect(setupButton, &QPushButton::clicked, this, &EntryWidget::close);
    connect(examButton, &QPushButton::clicked, this, &EntryWidget::close);
}
