/**
 * @project Automatic Examination
 * @file MultipleChoiceProblemViewer.cpp
 * @location src/ui/widgets/problemViewer
 * @brief This message displayed in Doxygen Files index
 * @date 2022/8/19
 */

#include "MultipleChoiceProblemViewer.h"

MultipleChoiceProblemViewer::MultipleChoiceProblemViewer(QWidget *parent)
        : BaseProblemViewer(parent), optionLayout(new QVBoxLayout)
{
    layout->addLayout(optionLayout);
}

void MultipleChoiceProblemViewer::setProblem(std::shared_ptr<MultipleChoiceProblem> p, json answer)
{
    this->problem = p;
    this->userAnswer = answer;

    noSaving = true;
    refresh();
    noSaving = false;
}

std::shared_ptr<MultipleChoiceProblem> MultipleChoiceProblemViewer::getProblem()
{
    return this->problem;
}

void MultipleChoiceProblemViewer::refresh()
{
    if (this->problem == nullptr)
    {
        return;
    }

    problemContent->setText(QString::fromStdString(this->problem->getContent()));
    problemAnswer->setText(QString("参考答案：") + QString::fromStdString(this->problem->getAnswerString()));

    if (evaluated) problemAnswer->setVisible(true);

    for (auto option: this->options)
    {
        delete option;
    }

    this->options.clear();

    std::set<int> userAnswerSet;

    if (!userAnswer.empty() && userAnswer.is_array())
    {
        userAnswer.get_to(userAnswerSet);
    }

    for (int i = 0; i < this->problem->getOptions().size(); i++)
    {
        auto option = new RemovableLabel(i, QString::fromStdString(this->problem->getOptions()[i]));
        option->enableCheckbox(problemContent, userAnswerSet.find(i) != userAnswerSet.end());
        if (evaluated) option->disable();
        connect(option, &RemovableLabel::checked, this, &MultipleChoiceProblemViewer::saveAnswer);
        this->options.push_back(option);
        this->optionLayout->addLayout(option);
    }
}

void MultipleChoiceProblemViewer::setEvaluated()
{
    BaseProblemViewer::setEvaluated();
    problemAnswer->setVisible(true);

    for (auto i: options)
    {
        i->disable();
    }
}

void MultipleChoiceProblemViewer::saveAnswer()
{
    if (this->problem == nullptr || noSaving)
    {
        return;
    }

    json answer = json::array();

    for (int i = 0; i < options.count(); i++)
    {
        if (options[i]->isCheckBoxChecked())
        {
            answer.push_back(i);
        }
    }

    emit answerChanged(answer);
}


