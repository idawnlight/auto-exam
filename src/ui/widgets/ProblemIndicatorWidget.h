/**
 * @project Automatic Examination
 * @file ProblemIndicatorWidget.h
 * @location src/ui/widgets
 * @brief Widget for problems indicator
 * @date 2022/8/12
 */

#ifndef AUTO_EXAM_PROBLEMINDICATORWIDGET_H
#define AUTO_EXAM_PROBLEMINDICATORWIDGET_H

#include <QtWidgets>

#include "models/AnswerPaper.h"

class ProblemIndicatorWidget : public QScrollArea {
    Q_OBJECT
public:
    ProblemIndicatorWidget(std::shared_ptr<Paper>);
    ProblemIndicatorWidget(std::shared_ptr<AnswerPaper>, bool isEditing = false);

protected:
    bool isEditing = false;
    QGridLayout * layout;
    std::vector<QPushButton *> buttons;
    std::shared_ptr<AnswerPaper> answerPaper;

    const QString buttonStyleWrong = "border: 2px solid red;";
    const QString buttonStyleRight = "border: 2px solid green;";
    const QString buttonStylePartWrong = "border: 2px solid orange;";
    const QString buttonStyleFocus = "border: 2px solid white;";
};


#endif //AUTO_EXAM_PROBLEMINDICATORWIDGET_H
