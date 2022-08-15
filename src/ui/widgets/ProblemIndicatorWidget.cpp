/**
 * @project Automatic Examination
 * @file ProblemIndicatorWidget.cpp
 * @location src/ui/widgets
 * @brief Widget for problems indicator
 * @date 2022/8/12
 */

#include "ProblemIndicatorWidget.h"

ProblemIndicatorWidget::ProblemIndicatorWidget(std::shared_ptr<Paper> p)
    : ProblemIndicatorWidget(std::make_shared<AnswerPaper>(p), true) {}

ProblemIndicatorWidget::ProblemIndicatorWidget(std::shared_ptr<AnswerPaper> p, bool isEditing)
    : answerPaper(p), layout(new QGridLayout()), isEditing(isEditing) {
//    setWidgetResizable(true);
//    setMaximumWidth(300);
//    setMinimumHeight(600);

    QWidget *client = new QWidget;
    client->setLayout(layout);
    layout->setSizeConstraint(QLayout::SetMinAndMaxSize);
//
//    auto leftLabel = new QLabel("<h2>选择</h2>");
//    auto leftLabel2 = new QLabel("<h2>选择</h2>");
//    auto leftLabel3 = new QLabel("<h2>选择</h2>");
//    auto leftLabel5 = new QLabel("<h2>选择</h2>");
//
//    layout->addWidget(leftLabel);
//    layout->addWidget(leftLabel2);
//    layout->addWidget(leftLabel3);
//    layout->addWidget(leftLabel5);

    setWidget(client);

    const QSize btnSize = QSize(64, 50);
    buttons.reserve(1000);

    auto size = answerPaper->getPaper()->getProblems().size();
    for (int i = 0; i <= size; i++) {
        auto btn = new QPushButton();

        if (i != size) {
            btn->setText(QString::number(i + 1));
        } else if (isEditing) {
            btn->setText("+");
            btn->setStyleSheet(buttonStyleFocus);
        } else {
            break;
        }

        btn->setFixedSize(btnSize);
        layout->addWidget(btn, i / 4, i % 4);
        buttons.push_back(btn);
//        if (i % 3 == 0) {
//            buttons[i]->setStyleSheet(buttonStyleWrong);
//        } else {
//            buttons[i]->setStyleSheet(buttonStylePartWrong);
//        }
//        buttons[i]->setStyleSheet("");
    }

//    layout->addWidget(buttons[0]);
//    layout->addWidget(buttons[1], 0, 1);
//
//    for (int i = 0; i < 14; i++) {
//        for (int j = 0; j < 4; j++) {
//            layout->addWidget(buttons[j + i * 4], 0 + i, j);
//        }
//    }

    layout->setSpacing(1);
}