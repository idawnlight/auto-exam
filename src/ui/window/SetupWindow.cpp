/**
 * @project Automatic Examination
 * @file SetupWindow.cpp
 * @location src/ui/window
 * @brief Window for setup paper
 * @date 2022/8/12
 */

#include "SetupWindow.h"

SetupWindow::SetupWindow(QWidget *parent) {
    auto mainLayout = new QGridLayout();
    setLayout(mainLayout);
    setWindowTitle("制卷 - 自动考试系统");
    setFixedSize(1200, 600);

    // Split layouts
    auto leftLayout = new QVBoxLayout();
    auto centerLayout = new QVBoxLayout();
    auto rightLayout = new QVBoxLayout();
    mainLayout->addLayout(leftLayout, 0, 0, 1, 1, Qt::AlignTop);
    mainLayout->addLayout(centerLayout, 0, 1, 1, 2, Qt::AlignTop);
    mainLayout->addLayout(rightLayout, 0, 3, 1, 1, Qt::AlignTop);

    auto leftLabel = new QLabel("<h2>选择</h2>");
    auto centerLabel = new QLabel("<h2>选择</h2>");
    auto rightLabel = new QLabel("<h2>选择</h2>");

    leftLayout->addWidget(leftLabel);
    centerLayout->addWidget(centerLabel);
    rightLayout->addWidget(rightLabel);

}

void SetupWindow::show() {
    QWidget::show();
}
