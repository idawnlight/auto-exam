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

class SingleChoiceProblemEditor : public QWidget {
    Q_OBJECT

public:
    explicit SingleChoiceProblemEditor(QWidget *parent = nullptr);

    void setProblem(std::shared_ptr<SingleChoiceProblem> problem);
    std::shared_ptr<SingleChoiceProblem> getProblem();

    void refresh();

public slots:
    void addOption();
    void removeOption(int index);

protected:
    std::shared_ptr<SingleChoiceProblem> problem;
    QPlainTextEdit * contentEdit;

};


#endif //AUTO_EXAM_SINGLECHOICEPROBLEMEDITOR_H
