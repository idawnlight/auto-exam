/**
 * @project Automatic Examination
 * @file ProblemEditor.h
 * @location src/ui/widgets
 * @brief This message displayed in Doxygen Files index
 * @date 2022/8/15
 */

#ifndef AUTO_EXAM_PROBLEMEDITOR_H
#define AUTO_EXAM_PROBLEMEDITOR_H

#include "models/BaseProblem.h"
#include "problemEditor/SingleChoiceProblemEditor.h"

#include <QtWidgets>

class ProblemEditor : public QVBoxLayout {
    Q_OBJECT

public:
    ProblemEditor(QWidget *parent = nullptr, std::shared_ptr<BaseProblem> problem = nullptr);
    void refresh();

public slots:
    void setProblem(std::shared_ptr<BaseProblem> problem, int index);

protected:
    int currentIndex;
    std::shared_ptr<BaseProblem> problem;

    QStackedWidget* stackedWidget;
    QWidget* emptyWidget;
    SingleChoiceProblemEditor* singleChoiceProblemEditor;
};


#endif //AUTO_EXAM_PROBLEMEDITOR_H
