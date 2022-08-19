/**
 * @project Automatic Examination
 * @file ShortAnswerProblemEditor.h
 * @location src/ui/widgets/problemEditor
 * @brief This message displayed in Doxygen Files index
 * @date 2022/8/16
 */

#ifndef AUTO_EXAM_SHORTANSWERPROBLEMEDITOR_H
#define AUTO_EXAM_SHORTANSWERPROBLEMEDITOR_H

#include "models/problems/ShortAnswerProblem.h"
#include "BaseProblemEditor.h"
#include "../RemovableLineEdit.h"

class ShortAnswerProblemEditor : public BaseProblemEditor {
    Q_OBJECT

public:
    explicit ShortAnswerProblemEditor(QWidget *parent = nullptr);

    void setProblem(std::shared_ptr<ShortAnswerProblem> p);
    std::shared_ptr<ShortAnswerProblem> getProblem();

    void refresh() override;

public slots:
    void addKeyword();
    void removeKeyword(int index);
    void setScore() override;
    void saveProblem() override;

signals:
    void problemChanged(std::shared_ptr<ShortAnswerProblem> problem);

protected:
    std::shared_ptr<ShortAnswerProblem> problem;
    QVBoxLayout * keywordsLayout;
    QList<RemovableLineEdit *> keywords;

};


#endif //AUTO_EXAM_SHORTANSWERPROBLEMEDITOR_H
