/**
 * @project Automatic Examination
 * @file SingleChoiceProblemViewer.h
 * @location src/ui/widgets/problemViewer
 * @brief This message displayed in Doxygen Files index
 * @date 2022/8/19
 */

#ifndef AUTO_EXAM_SINGLECHOICEPROBLEMVIEWER_H
#define AUTO_EXAM_SINGLECHOICEPROBLEMVIEWER_H

#include "BaseProblemViewer.h"
#include "models/problems/SingleChoiceProblem.h"
#include "ui/widgets/RemovableLabel.h"

class SingleChoiceProblemViewer : public BaseProblemViewer
{
    Q_OBJECT

public:
    explicit SingleChoiceProblemViewer(QWidget *parent = nullptr);

    void setProblem(std::shared_ptr<SingleChoiceProblem> p, json answer);
    std::shared_ptr<SingleChoiceProblem> getProblem();
    void refresh() override;
    void setEvaluated() override;

public slots:
    void saveAnswer() override;

signals:
    void problemChanged(std::shared_ptr<SingleChoiceProblem> problem);

protected:
    std::shared_ptr<SingleChoiceProblem> problem;
    QWidget *optionWidget;
    QVBoxLayout *optionLayout;
    QList<RemovableLabel *> options;
};


#endif //AUTO_EXAM_SINGLECHOICEPROBLEMVIEWER_H
