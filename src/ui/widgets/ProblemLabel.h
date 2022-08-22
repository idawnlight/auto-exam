/**
 * @project Automatic Examination
 * @file ProblemLabel.h
 * @location src/ui/widgets
 * @brief Problem Label for problem info
 * @date 2022/8/17
 */

#ifndef AUTO_EXAM_PROBLEMLABEL_H
#define AUTO_EXAM_PROBLEMLABEL_H

#include <QtWidgets>

#include "models/BaseProblem.h"

class ProblemLabel : public QLabel
{
    Q_OBJECT

public:
    ProblemLabel(QWidget *parent = nullptr);

public slots:
    void setProblem(std::shared_ptr<BaseProblem>);

};


#endif //AUTO_EXAM_PROBLEMLABEL_H
