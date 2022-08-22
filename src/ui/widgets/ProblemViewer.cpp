/**
 * @project Automatic Examination
 * @file ProblemViewer.cpp
 * @location src/ui/widgets
 * @brief Problem Viewer Layout
 * @date 2022/8/19
 */

#include "ProblemViewer.h"

ProblemViewer::ProblemViewer(QWidget *parent, std::shared_ptr<BaseProblem> problem)
        : QVBoxLayout(parent),
          stackedWidget(new QStackedWidget()),
          problem(problem),
          emptyWidget(new QWidget),
          singleChoiceProblemViewer(new SingleChoiceProblemViewer),
          multipleChoiceProblemViewer(new MultipleChoiceProblemViewer),
          trueOrFalseProblemViewer(new TrueOrFalseProblemViewer),
          shortAnswerProblemViewer(new ShortAnswerProblemViewer),
          navigatorWidget(new NavigatorWidget)
{
    addWidget(stackedWidget);

    stackedWidget->addWidget(singleChoiceProblemViewer);
    stackedWidget->addWidget(multipleChoiceProblemViewer);
    stackedWidget->addWidget(trueOrFalseProblemViewer);
    stackedWidget->addWidget(shortAnswerProblemViewer);

    connect(singleChoiceProblemViewer, &SingleChoiceProblemViewer::answerChanged, this,
            &ProblemViewer::answerChangedShim);
    connect(multipleChoiceProblemViewer, &MultipleChoiceProblemViewer::answerChanged, this,
            &ProblemViewer::answerChangedShim);
    connect(trueOrFalseProblemViewer, &TrueOrFalseProblemViewer::answerChanged, this,
            &ProblemViewer::answerChangedShim);
    connect(shortAnswerProblemViewer, &ShortAnswerProblemViewer::answerChanged, this,
            &ProblemViewer::answerChangedShim);

    stackedWidget->addWidget(emptyWidget);

    auto bottomLayout = new QHBoxLayout();

    bottomLayout->addStretch();

    bottomLayout->addWidget(navigatorWidget);
    connect(navigatorWidget, &NavigatorWidget::previous, this, &ProblemViewer::navigateProblemPrevious);
    connect(navigatorWidget, &NavigatorWidget::next, this, &ProblemViewer::navigateProblemNext);

    addLayout(bottomLayout, 0);

    if (problem != nullptr)
    {
        refresh();
    } else
    {
        stackedWidget->setCurrentWidget(emptyWidget);
    }
}

void ProblemViewer::refresh()
{
    if (this->problem == nullptr)
    {
        navigatorWidget->setStatus(NavigatorStatus::None);
        stackedWidget->setCurrentWidget(emptyWidget);
        return;
    }

    switch (problem->getProblemType())
    {
        case SingleChoice:
        {
            auto tmp = std::static_pointer_cast<SingleChoiceProblem>(this->problem);
            singleChoiceProblemViewer->setProblem(tmp, answer);
        }
            break;
        case MultipleChoice:
        {
            auto tmp = std::static_pointer_cast<MultipleChoiceProblem>(this->problem);
            multipleChoiceProblemViewer->setProblem(tmp, answer);
        }
            break;
        case TrueOrFalse:
        {
            auto tmp = std::static_pointer_cast<TrueOrFalseProblem>(this->problem);
            trueOrFalseProblemViewer->setProblem(tmp, answer);
        }
            break;
        case ShortAnswer:
        {
            auto tmp = std::static_pointer_cast<ShortAnswerProblem>(this->problem);
            shortAnswerProblemViewer->setProblem(tmp, answer);
        }
            break;
        default:
            qDebug() << "Default";
            break;
    }

    stackedWidget->setCurrentIndex(problem->getProblemType());
}

void ProblemViewer::setProblem(std::shared_ptr<BaseProblem> problem, int index, NavigatorStatus status, json answer)
{
    currentIndex = index;
    this->problem = problem;
    this->answer = answer;
    navigatorWidget->setStatus(status);
    refresh();

    emit problemChanged(problem);
}

void ProblemViewer::navigateProblemPrevious()
{
    emit navigateProblem(currentIndex - 1);
}

void ProblemViewer::navigateProblemNext()
{
    emit navigateProblem(currentIndex + 1);
}

void ProblemViewer::answerChangedShim(json answer)
{
    emit answerChanged(currentIndex, answer);
}

void ProblemViewer::setEvaluated()
{
    evaluated = true;

    singleChoiceProblemViewer->setEvaluated();
    multipleChoiceProblemViewer->setEvaluated();
    trueOrFalseProblemViewer->setEvaluated();
    shortAnswerProblemViewer->setEvaluated();
}
