/**
 * @project Automatic Examination
 * @file ShortAnswerProblemViewer.h
 * @location src/ui/widgets/problemViewer
 * @brief This message displayed in Doxygen Files index
 * @date 2022/8/19
 */

#ifndef AUTO_EXAM_SHORTANSWERPROBLEMVIEWER_H
#define AUTO_EXAM_SHORTANSWERPROBLEMVIEWER_H

#include "BaseProblemViewer.h"
#include "models/problems/ShortAnswerProblem.h"

class ShortAnswerProblemViewer : public BaseProblemViewer
{
    Q_OBJECT

public:
    explicit ShortAnswerProblemViewer(QWidget *parent = nullptr);

    void setProblem(std::shared_ptr<ShortAnswerProblem> p, json answer);
    std::shared_ptr<ShortAnswerProblem> getProblem();
    void refresh() override;
    void setEvaluated() override;

public slots:
    void saveAnswer() override;

signals:
    void problemChanged(std::shared_ptr<ShortAnswerProblem> problem);

protected:
    std::shared_ptr<ShortAnswerProblem> problem;
    QPlainTextEdit *answerEdit;
};


#endif //AUTO_EXAM_SHORTANSWERPROBLEMVIEWER_H
