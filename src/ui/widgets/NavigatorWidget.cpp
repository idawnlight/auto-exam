/**
 * @project Automatic Examination
 * @file NavigatorWidget.cpp
 * @location src/ui/widgets
 * @brief This message displayed in Doxygen Files index
 * @date 2022/8/17
 */

#include "NavigatorWidget.h"

NavigatorWidget::NavigatorWidget(QWidget *parent) : QWidget(parent) {
    auto layout = new QHBoxLayout(this);

    previousButton = new QPushButton("上一题");
    nextButton = new QPushButton("下一题");

    layout->addWidget(previousButton, 0);
    layout->addWidget(nextButton, 0);

    previousButton->setDisabled(true);
    nextButton->setDisabled(true);

    connect(previousButton, &QPushButton::clicked, this, &NavigatorWidget::previous);
    connect(nextButton, &QPushButton::clicked, this, &NavigatorWidget::next);

    setLayout(layout);
}

void NavigatorWidget::setStatus(NavigatorStatus status) {
    switch (status) {
        case NavigatorStatus::None:
            previousButton->setDisabled(true);
            nextButton->setDisabled(true);
            break;
        case NavigatorStatus::Middle:
            previousButton->setDisabled(false);
            nextButton->setDisabled(false);
            break;
        case NavigatorStatus::First:
            previousButton->setDisabled(true);
            nextButton->setDisabled(false);
            break;
        case NavigatorStatus::Last:
            previousButton->setDisabled(false);
            nextButton->setDisabled(true);
            break;
    }
}
