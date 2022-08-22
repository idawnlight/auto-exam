/**
 * @project Automatic Examination
 * @file BaseProblemViewer.h
 * @location src/ui/widgets/problemViewer
 * @brief This message displayed in Doxygen Files index
 * @date 2022/8/19
 */

#ifndef AUTO_EXAM_BASEPROBLEMVIEWER_H
#define AUTO_EXAM_BASEPROBLEMVIEWER_H

#include <QtWidgets>
#include "models/BaseProblem.h"

class BaseProblemViewer : public QWidget
{
    Q_OBJECT

public:
    explicit BaseProblemViewer(QWidget *parent = nullptr);

    virtual void refresh() = 0;
    virtual void setEvaluated();

public slots:
    virtual void saveAnswer() = 0;

signals:
    void answerChanged(json answer);

protected:
    QVBoxLayout *layout;
    json userAnswer;
    QLabel *problemContent;
    QLabel *problemAnswer;
    bool noSaving = false;
    bool evaluated = false;
};


#endif //AUTO_EXAM_BASEPROBLEMVIEWER_H
