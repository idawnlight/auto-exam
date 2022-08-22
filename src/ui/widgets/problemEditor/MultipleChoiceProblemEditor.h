/**
 * @project Automatic Examination
 * @file MultipleChoiceProblemEditor.h
 * @location src/ui/widgets/problemViewer
 * @date 2022/8/16
 */

#ifndef AUTO_EXAM_MULTIPLECHOICEPROBLEMEDITOR_H
#define AUTO_EXAM_MULTIPLECHOICEPROBLEMEDITOR_H

#include "models/problems/MultipleChoiceProblem.h"
#include "BaseProblemEditor.h"
#include "ui/widgets/RemovableLineEdit.h"

class MultipleChoiceProblemEditor : public BaseProblemEditor
{
    Q_OBJECT

public:
    explicit MultipleChoiceProblemEditor(QWidget *parent = nullptr);

    void setProblem(std::shared_ptr<MultipleChoiceProblem> p);
    std::shared_ptr<MultipleChoiceProblem> getProblem();
    void refresh() override;

public slots:
    void addOption();
    void removeOption(int index);
    void setAnswer();
    void setScore() override;
    void saveProblem() override;

signals:
    void problemChanged(std::shared_ptr<MultipleChoiceProblem> problem);

protected:
    std::shared_ptr<MultipleChoiceProblem> problem;
    QVBoxLayout *optionLayout;
    QList<RemovableLineEdit *> options;
};


#endif //AUTO_EXAM_MULTIPLECHOICEPROBLEMEDITOR_H
