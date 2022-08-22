/**
 * @project Automatic Examination
 * @file ShortAnswerProblemViewer.cpp
 * @location src/ui/widgets/problemViewer
 * @brief This message displayed in Doxygen Files index
 * @date 2022/8/19
 */

#include "ShortAnswerProblemViewer.h"

ShortAnswerProblemViewer::ShortAnswerProblemViewer(QWidget *parent)
        : BaseProblemViewer(parent), answerEdit(new QPlainTextEdit)
{
    layout->addWidget(answerEdit);
}

void ShortAnswerProblemViewer::setProblem(std::shared_ptr<ShortAnswerProblem> p, json answer)
{
    this->problem = p;
    this->userAnswer = answer;

    noSaving = true;
    refresh();
    noSaving = false;
}

std::shared_ptr<ShortAnswerProblem> ShortAnswerProblemViewer::getProblem()
{
    return this->problem;
}

void ShortAnswerProblemViewer::refresh()
{
    if (this->problem == nullptr)
    {
        return;
    }

    problemContent->setText(QString::fromStdString(this->problem->getContent()));
    problemAnswer->setText(QString("参考答案关键词：") + QString::fromStdString(this->problem->getKeywordsString()));

    if (evaluated) problemAnswer->setVisible(true);

    std::string userAnswerStr;
    if (userAnswer.is_array() && !userAnswer.empty())
    {
        userAnswerStr = userAnswer[0];
    }

    answerEdit->setPlainText(QString::fromStdString(userAnswerStr));
    connect(answerEdit, &QPlainTextEdit::textChanged, this, &ShortAnswerProblemViewer::saveAnswer);
}

void ShortAnswerProblemViewer::setEvaluated()
{
    BaseProblemViewer::setEvaluated();
    problemAnswer->setVisible(true);

    answerEdit->setReadOnly(true);
}

void ShortAnswerProblemViewer::saveAnswer()
{
    if (this->problem == nullptr || noSaving)
    {
        return;
    }

    json answer = json::array();
    answer.push_back(answerEdit->toPlainText().toStdString());
    emit answerChanged(answer);
}
