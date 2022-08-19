/**
 * @project Automatic Examination
 * @file SingleChoiceProblemViewer.cpp
 * @location src/ui/widgets/problemViewer
 * @brief This message displayed in Doxygen Files index
 * @date 2022/8/19
 */

#include "SingleChoiceProblemViewer.h"

SingleChoiceProblemViewer::SingleChoiceProblemViewer(QWidget *parent)
    : BaseProblemViewer(parent), optionLayout(new QVBoxLayout) {
    layout->addLayout(optionLayout);
}

void SingleChoiceProblemViewer::setProblem(std::shared_ptr<SingleChoiceProblem> p, json answer) {
    this->problem = p;
    this->userAnswer = answer;

    noSaving = true;
    refresh();
    noSaving = false;
}

std::shared_ptr<SingleChoiceProblem> SingleChoiceProblemViewer::getProblem() {
    return this->problem;
}

void SingleChoiceProblemViewer::refresh() {
    if (this->problem == nullptr) {
        return;
    }

    problemContent->setText(QString::fromStdString(this->problem->getContent()));
    problemAnswer->setText(QString("参考答案：") + QChar(this->problem->getAnswer() + 'A'));

    if (evaluated) problemAnswer->setVisible(true);

    for (auto option : this->options) {
        delete option;
    }

    this->options.clear();

    int answerIndex = -1;
    if (userAnswer.is_array() && !userAnswer.empty()) {
        answerIndex = userAnswer[0];
    }

    for (int i = 0; i < this->problem->getOptions().size(); i++) {
        auto option = new RemovableLabel(i, QString::fromStdString(this->problem->getOptions()[i]));
        option->enableRadio(problemContent, i == answerIndex);
        if (evaluated) option->disable();
        connect(option, &RemovableLabel::radio, this, &SingleChoiceProblemViewer::saveAnswer);
        this->options.push_back(option);
        this->optionLayout->addLayout(option);
    }
}

void SingleChoiceProblemViewer::setEvaluated() {
    BaseProblemViewer::setEvaluated();
    problemAnswer->setVisible(true);

    for (auto i : options) {
        i->disable();
    }
}

void SingleChoiceProblemViewer::saveAnswer() {
    if (this->problem == nullptr || noSaving) {
        return;
    }

    json answer = json::array();

    for (int i = 0; i < options.count(); i++) {
        if (options[i]->isRadioChecked()) {
            answer.push_back(i);
            emit answerChanged(answer);
            return;
        }
    }
}
