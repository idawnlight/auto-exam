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
    : answerPaper(p), layout(new QGridLayout()), isEditing(isEditing), buttonGroup(new QButtonGroup(this)) {
    QWidget *client = new QWidget;
    client->setLayout(layout);
    layout->setSizeConstraint(QLayout::SetMinAndMaxSize);

    setWidget(client);

    buttons.reserve(300);

    auto size = answerPaper->getPaper()->getProblems().size();
    for (int i = 0; i <= size; i++) {
        auto btn = new QPushButton();

        if (i != size) {
            buttonGroup->addButton(btn);
            btn->setProperty("id", i);
            btn->setText(QString::number(i + 1));
            btn->setCheckable(true);
            btn->setStyleSheet(buttonStyleDefault);
//            switch (i % 3) {
//                case 0:
//                    btn->setStyleSheet(buttonStyleDefault + buttonStyleRight);
//                    break;
//                case 1:
//                    btn->setStyleSheet(buttonStyleDefault + buttonStylePartRight);
//                    break;
//                case 2:
//                    btn->setStyleSheet(buttonStyleDefault + buttonStyleWrong);
//                    break;
//            }
        } else if (isEditing) {
            btn->setText("+");
            btn->setStyleSheet(buttonStyleDefault);
            connect(btn, &QAbstractButton::clicked, this, &ProblemIndicatorWidget::addProblem);
        } else {
            break;
        }

        btn->setFixedSize(btnSize);
        layout->addWidget(btn, i / 4, i % 4);
        buttons.push_back(btn);
//        if (i % 3 == 0) {
//            buttons[i]->setStyleSheet(buttonStyleWrong);
//        } else {
//            buttons[i]->setStyleSheet(buttonStylePartRight);
//        }
//        buttons[i]->setStyleSheet("");
    }

    connect(buttonGroup, &QButtonGroup::buttonClicked, this, &ProblemIndicatorWidget::problemClicked);

    layout->setSpacing(1);
}

void ProblemIndicatorWidget::problemClicked(QAbstractButton *button) {
    auto index = button->property("id").toInt();
    auto navigatorStatus = NavigatorStatus::None;
    if (answerPaper->getPaper()->problemCount() == 1) {
        navigatorStatus = NavigatorStatus::None;
    } else if (index == 0) {
        navigatorStatus = NavigatorStatus::First;
    } else if (index == answerPaper->getPaper()->getProblems().size() - 1) {
        navigatorStatus = NavigatorStatus::Last;
    } else {
        navigatorStatus = NavigatorStatus::Middle;
    }
    qDebug() << button->text();
    emit selectionChanged(answerPaper->getPaper()->getProblem(index), index, navigatorStatus);
}

void ProblemIndicatorWidget::addProblem() {
    QStringList items;
    items << "单选" << "多选" << "判断" << "简答";

    bool ok;
    QString item = QInputDialog::getItem(this, "选择题型", "题型", items, 0, false, &ok);
    if (ok && !item.isEmpty()) {
        auto btn = new QPushButton();
        buttonGroup->addButton(btn);

        int i = answerPaper->getPaper()->getProblems().size();

        btn->setProperty("id", i);
        btn->setText(QString::number(i + 1));
        btn->setCheckable(true);
        btn->setStyleSheet(buttonStyleDefault);
        btn->setChecked(true);
        btn->setFixedSize(btnSize);

        // Must be editing
        buttons.insert(buttons.end() - 1, btn);
        appendButton(btn);

        switch (items.indexOf(item)) {
            case 0:
            {
                auto problem = std::make_shared<SingleChoiceProblem>();
                this->answerPaper->getPaper()->getProblems().push_back(problem);
            }
                break;
            case 1:
//                emit addMultipleChoiceProblem();
                break;
            case 2:
//                emit addJudgeProblem();
                break;
            case 3:
//                emit addShortAnswerProblem();
                break;
        }

        if (i == 0) {
            emit selectionChanged(answerPaper->getPaper()->getProblem(i), i, NavigatorStatus::None);
        } else {
            emit selectionChanged(answerPaper->getPaper()->getProblem(i), i, NavigatorStatus::Last);
        }
        emit paperChanged(answerPaper->getPaper());

        qDebug() << item;
    }
}

void ProblemIndicatorWidget::appendButton(QAbstractButton *button) {
    int i = button->property("id").toInt();

    auto j = i + 1;
    layout->removeWidget(buttons[j]);
    layout->addWidget(buttons[j], j / 4, j % 4);

    layout->addWidget(button, i / 4, i % 4);
}

void ProblemIndicatorWidget::touchPaper() {
    emit paperChanged(answerPaper->getPaper());
}

void ProblemIndicatorWidget::removeProblem(int index) {
    answerPaper->getPaper()->getProblems().erase(answerPaper->getPaper()->getProblems().begin() + index);

    layout->removeWidget(buttons[index]);
    buttons[index]->setChecked(false);
    buttonGroup->removeButton(buttons[index]);

    delete buttons[index];
    buttons.erase(buttons.begin() + index);

    for (int j = index; j < buttons.size(); j++) {
        layout->removeWidget(buttons[j]);

        if (j != buttons.size() - 1) {
            buttons[j]->setProperty("id", j);
            buttons[j]->setText(QString::number(j + 1));
        }

        layout->addWidget(buttons[j], j / 4, j % 4);
    }

    emit selectionChanged(nullptr, -1, NavigatorStatus::None);
    emit paperChanged(answerPaper->getPaper());
}
