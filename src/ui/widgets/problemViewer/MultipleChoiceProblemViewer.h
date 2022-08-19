/**
 * @project Automatic Examination
 * @file MultipleChoiceProblemViewer.h
 * @location src/ui/widgets/problemViewer
 * @brief This message displayed in Doxygen Files index
 * @date 2022/8/19
 */

#ifndef AUTO_EXAM_MULTIPLECHOICEPROBLEMVIEWER_H
#define AUTO_EXAM_MULTIPLECHOICEPROBLEMVIEWER_H

#include "BaseProblemViewer.h"
#include "models/problems/MultipleChoiceProblem.h"
#include "ui/widgets/RemovableLabel.h"

class MultipleChoiceProblemViewer : public BaseProblemViewer {
    Q_OBJECT

public:
    explicit MultipleChoiceProblemViewer(QWidget * parent = nullptr);

    void setProblem(std::shared_ptr<MultipleChoiceProblem> p, json answer);
    std::shared_ptr<MultipleChoiceProblem> getProblem();

    void refresh() override;
    void setEvaluated() override;

public slots:
    void saveAnswer() override;

signals:
    void problemChanged(std::shared_ptr<MultipleChoiceProblem> problem);

protected:
    std::shared_ptr<MultipleChoiceProblem> problem;
    QVBoxLayout * optionLayout;
    QList<RemovableLabel *> options;

};


#endif //AUTO_EXAM_MULTIPLECHOICEPROBLEMVIEWER_H
