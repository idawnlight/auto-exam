/**
 * @project Automatic Examination
 * @file TrueOrFalseProblemViewer.cpp
 * @location src/ui/widgets/problemViewer
 * @brief This message displayed in Doxygen Files index
 * @date 2022/8/19
 */

#include "TrueOrFalseProblemViewer.h"

TrueOrFalseProblemViewer::TrueOrFalseProblemViewer(QWidget *parent)
        : BaseProblemViewer(parent), optionLayout(new QVBoxLayout)
{
    layout->addLayout(optionLayout);
}

void TrueOrFalseProblemViewer::setProblem(std::shared_ptr<TrueOrFalseProblem> p, json answer)
{
    this->problem = p;
    this->userAnswer = answer;

    noSaving = true;
    refresh();
    noSaving = false;
}

std::shared_ptr<TrueOrFalseProblem> TrueOrFalseProblemViewer::getProblem()
{
    return this->problem;
}

void TrueOrFalseProblemViewer::refresh()
{
    if (this->problem == nullptr)
    {
        return;
    }

    problemContent->setText(QString::fromStdString(this->problem->getContent()));
    problemContent->adjustSize();
    problemAnswer->setText(QString("参考答案：") + (this->problem->getAnswer() ? "正确" : "错误"));

    if (evaluated) problemAnswer->setVisible(true);

    for (auto option: this->options)
    {
        delete option;
    }

    this->options.clear();

    auto optionRight = new RemovableLabel(1, QString("正确"));
    optionRight->enableRadio(problemContent);
    optionLayout->addLayout(optionRight);

    auto optionWrong = new RemovableLabel(0, QString("错误"));
    optionWrong->enableRadio(problemContent);
    optionLayout->addLayout(optionWrong);

    connect(optionRight, &RemovableLabel::radio, this, &TrueOrFalseProblemViewer::saveAnswer);
    connect(optionWrong, &RemovableLabel::radio, this, &TrueOrFalseProblemViewer::saveAnswer);

    options.push_back(optionWrong);
    options.push_back(optionRight);

    bool flag = false;
    if (userAnswer.is_array() && !userAnswer.empty())
    {
        flag = true;
    }

    options[0]->setRadioChecked(flag && !userAnswer[0]);
    options[1]->setRadioChecked(flag && userAnswer[0]);
}

void TrueOrFalseProblemViewer::setEvaluated()
{
    BaseProblemViewer::setEvaluated();
    problemAnswer->setVisible(true);

    for (auto i: options)
    {
        i->disable();
    }
}

void TrueOrFalseProblemViewer::saveAnswer()
{
    if (this->problem == nullptr || noSaving)
    {
        return;
    }

    json answer = json::array();

    answer.push_back(options[1]->isRadioChecked());

    emit answerChanged(answer);
}

