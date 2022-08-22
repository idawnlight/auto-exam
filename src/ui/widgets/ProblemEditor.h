/**
 * @project Automatic Examination
 * @file ProblemEditor.h
 * @location src/ui/widgets
 * @brief Problem Editor
 * @date 2022/8/15
 */

#ifndef AUTO_EXAM_PROBLEMEDITOR_H
#define AUTO_EXAM_PROBLEMEDITOR_H

#include <QtWidgets>

#include "models/BaseProblem.h"
#include "problemEditor/SingleChoiceProblemEditor.h"
#include "problemEditor/MultipleChoiceProblemEditor.h"
#include "problemEditor/TrueOrFalseProblemEditor.h"
#include "problemEditor/ShortAnswerProblemEditor.h"
#include "NavigatorWidget.h"

class ProblemEditor : public QVBoxLayout
{
    Q_OBJECT

public:
    ProblemEditor(QWidget *parent = nullptr, std::shared_ptr<BaseProblem> problem = nullptr);

    void refresh();

public slots:
    void setProblem(std::shared_ptr<BaseProblem> problem, int index, NavigatorStatus status);
    void navigateProblemPrevious();
    void navigateProblemNext();

protected slots:
    void removeProblemClicked();

signals:
    void removeProblem(int index);
    void navigateProblem(int index);
    void problemChanged(std::shared_ptr<BaseProblem> problem);

protected:
    int currentIndex;
    std::shared_ptr<BaseProblem> problem;

    QStackedWidget *stackedWidget;
    QWidget *emptyWidget;

    SingleChoiceProblemEditor *singleChoiceProblemEditor;
    MultipleChoiceProblemEditor *multipleChoiceProblemEditor;
    TrueOrFalseProblemEditor *trueOrFalseProblemEditor;
    ShortAnswerProblemEditor *shortAnswerProblemEditor;

    NavigatorWidget *navigatorWidget;
    QPushButton *removeButton;
};


#endif //AUTO_EXAM_PROBLEMEDITOR_H
