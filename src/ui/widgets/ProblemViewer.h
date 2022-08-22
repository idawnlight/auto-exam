/**
 * @project Automatic Examination
 * @file ProblemViewer.h
 * @location src/ui/widgets
 * @brief Problem Viewer Layout
 * @date 2022/8/19
 */

#ifndef AUTO_EXAM_PROBLEMVIEWER_H
#define AUTO_EXAM_PROBLEMVIEWER_H

#include <QtWidgets>

#include "models/BaseProblem.h"
#include "problemViewer/SingleChoiceProblemViewer.h"
#include "problemViewer/MultipleChoiceProblemViewer.h"
#include "problemViewer/TrueOrFalseProblemViewer.h"
#include "problemViewer/ShortAnswerProblemViewer.h"
#include "NavigatorWidget.h"

class ProblemViewer : public QVBoxLayout
{
    Q_OBJECT

public:
    ProblemViewer(QWidget *parent = nullptr, std::shared_ptr<BaseProblem> problem = nullptr);
    void refresh();
    void setEvaluated();

public slots:
    void setProblem(std::shared_ptr<BaseProblem> problem, int index, NavigatorStatus status, json answer);
    void answerChangedShim(json answer);
    void navigateProblemPrevious();
    void navigateProblemNext();

signals:
    void navigateProblem(int index);
    void problemChanged(std::shared_ptr<BaseProblem> problem);
    void answerChanged(int index, json answer);

protected:
    int currentIndex;
    std::shared_ptr<BaseProblem> problem;
    json answer;
    bool evaluated = false;

    QStackedWidget *stackedWidget;
    QWidget *emptyWidget;

    SingleChoiceProblemViewer *singleChoiceProblemViewer;
    MultipleChoiceProblemViewer *multipleChoiceProblemViewer;
    TrueOrFalseProblemViewer *trueOrFalseProblemViewer;
    ShortAnswerProblemViewer *shortAnswerProblemViewer;

    NavigatorWidget *navigatorWidget;
};


#endif //AUTO_EXAM_PROBLEMVIEWER_H
