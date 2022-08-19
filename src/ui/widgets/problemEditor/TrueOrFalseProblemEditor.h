/**
 * @project Automatic Examination
 * @file TrueOrFalseProblemEditor.h
 * @location src/ui/widgets/problemEditor
 * @brief This message displayed in Doxygen Files index
 * @date 2022/8/16
 */

#ifndef AUTO_EXAM_TRUEORFALSEPROBLEMEDITOR_H
#define AUTO_EXAM_TRUEORFALSEPROBLEMEDITOR_H

#include "models/problems/TrueOrFalseProblem.h"
#include "BaseProblemEditor.h"
#include "../RemovableLabel.h"

class TrueOrFalseProblemEditor : public BaseProblemEditor {
    Q_OBJECT

public:
    explicit TrueOrFalseProblemEditor(QWidget *parent = nullptr);

    void setProblem(std::shared_ptr<TrueOrFalseProblem> p);
    std::shared_ptr<TrueOrFalseProblem> getProblem();

    void refresh() override;

public slots:
    void setAnswer(int index);
    void setScore() override;
    void saveProblem() override;

signals:
    void problemChanged(std::shared_ptr<TrueOrFalseProblem> problem);

protected:
    std::shared_ptr<TrueOrFalseProblem> problem;
    QVBoxLayout * optionLayout;
    QList<RemovableLabel *> options;

};


#endif //AUTO_EXAM_TRUEORFALSEPROBLEMEDITOR_H
