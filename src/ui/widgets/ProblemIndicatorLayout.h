/**
 * @project Automatic Examination
 * @file ProblemIndicatorLayout.h
 * @location src/ui/widgets
 * @brief Widget for problems indicator
 * @date 2022/8/12
 */

#ifndef AUTO_EXAM_PROBLEMINDICATORLAYOUT_H
#define AUTO_EXAM_PROBLEMINDICATORLAYOUT_H

#include <QtWidgets>

#include "models/AnswerPaper.h"

class ProblemIndicatorLayout : public QGridLayout {
    Q_OBJECT
public:
    ProblemIndicatorLayout(std::shared_ptr<AnswerPaper>);

protected:
    std::vector<std::unique_ptr<QPushButton>> buttons;
    std::shared_ptr<AnswerPaper> answerPaper;
};


#endif //AUTO_EXAM_PROBLEMINDICATORLAYOUT_H
