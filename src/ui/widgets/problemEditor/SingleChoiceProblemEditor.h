/**
 * @project Automatic Examination
 * @file SingleChoiceProblemEditor.h
 * @location src/ui/widgets/problemEditor
 * @brief This message displayed in Doxygen Files index
 * @date 2022/8/16
 */

#ifndef AUTO_EXAM_SINGLECHOICEPROBLEMEDITOR_H
#define AUTO_EXAM_SINGLECHOICEPROBLEMEDITOR_H

#include <QtWidgets>

#include "models/problems/SingleChoiceProblem.h"
#include "BaseProblemEditor.h"
#include "../RemovableLineEdit.h"

class SingleChoiceProblemEditor : public BaseProblemEditor {
    Q_OBJECT

public:
    explicit SingleChoiceProblemEditor(QWidget *parent = nullptr);

    void setProblem(std::shared_ptr<SingleChoiceProblem> p);
    std::shared_ptr<SingleChoiceProblem> getProblem();

    void refresh() override;

public slots:
    void addOption();
    void removeOption(int index);
    void setAnswer(int index);
    void setScore() override;
    void saveProblem() override;

signals:
    void problemChanged(std::shared_ptr<SingleChoiceProblem> problem);

protected:
    std::shared_ptr<SingleChoiceProblem> problem;
    QVBoxLayout * optionLayout;
    QList<RemovableLineEdit *> options;

};


#endif //AUTO_EXAM_SINGLECHOICEPROBLEMEDITOR_H
