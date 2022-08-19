/**
 * @project Automatic Examination
 * @file TrueOrFalseProblemViewer.h
 * @location src/ui/widgets/problemViewer
 * @brief This message displayed in Doxygen Files index
 * @date 2022/8/19
 */

#ifndef AUTO_EXAM_TRUEORFALSEPROBLEMVIEWER_H
#define AUTO_EXAM_TRUEORFALSEPROBLEMVIEWER_H

#include "BaseProblemViewer.h"
#include "models/problems/TrueOrFalseProblem.h"
#include "ui/widgets/RemovableLabel.h"

class TrueOrFalseProblemViewer : public BaseProblemViewer {
    Q_OBJECT

public:
    explicit TrueOrFalseProblemViewer(QWidget * parent = nullptr);

    void setProblem(std::shared_ptr<TrueOrFalseProblem> p, json answer);
    std::shared_ptr<TrueOrFalseProblem> getProblem();

    void refresh() override;
    void setEvaluated() override;

public slots:
    void saveAnswer() override;

signals:
    void problemChanged(std::shared_ptr<TrueOrFalseProblem> problem);

protected:
    std::shared_ptr<TrueOrFalseProblem> problem;
    QVBoxLayout * optionLayout;
    QList<RemovableLabel *> options;

};


#endif //AUTO_EXAM_TRUEORFALSEPROBLEMVIEWER_H
