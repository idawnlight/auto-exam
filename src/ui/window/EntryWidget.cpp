/**
 * @project Automatic Examination
 * @file EntryWidget.cpp
 * @location src/ui/window
 * @brief EntryWidget for selection
 * @date 2022/8/12
 */

#include "EntryWidget.h"

EntryWidget::EntryWidget(QWidget *parent)
{
    auto mainLayout = new QVBoxLayout();
    setLayout(mainLayout);
    setWindowTitle("选择 - 自动考试系统");
    setMinimumWidth(300);

    // Selections
    auto editButton = new QPushButton("制卷");
    mainLayout->addWidget(editButton);

    auto examButton = new QPushButton("答题");
    mainLayout->addWidget(examButton);

    // Connect signals
    connect(editButton, &QPushButton::clicked, this, &EntryWidget::editPaper);
    connect(examButton, &QPushButton::clicked, this, &EntryWidget::startExam);

    // Close window on click
    connect(editButton, &QPushButton::clicked, this, &EntryWidget::close);
    connect(examButton, &QPushButton::clicked, this, &EntryWidget::close);
}
