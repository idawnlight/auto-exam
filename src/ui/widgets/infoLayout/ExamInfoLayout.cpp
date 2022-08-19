/**
 * @project Automatic Examination
 * @file ExamInfoLayout.cpp
 * @location src/ui/widgets/infoLayout
 * @brief This message displayed in Doxygen Files index
 * @date 2022/8/16
 */

#include "ExamInfoLayout.h"

ExamInfoLayout::ExamInfoLayout(QWidget *parent) : AlignedInfoLayout(parent) {
    addInfo("试卷总分", "0");
    addInfo("题目数", "0");
    addInfo(" ", " ");
    addInfo("单选题数", "0");
    addInfo("多选题数", "0");
    addInfo("判断题数", "0");
    addInfo("简答题数", "0");
}

void ExamInfoLayout::updateExamInfo(std::shared_ptr<Paper> p) {
    updateInfo("试卷总分", QString::number(p->scoreCount()));
    updateInfo("题目数", QString::number(p->problemCount()));

    updateInfo("单选题数", QString::number(p->problemCount(SingleChoice)));
    updateInfo("多选题数", QString::number(p->problemCount(MultipleChoice)));
    updateInfo("判断题数", QString::number(p->problemCount(TrueOrFalse)));
    updateInfo("简答题数", QString::number(p->problemCount(ShortAnswer)));
}

void ExamInfoLayout::setScore(double score) {
    addInfo(" ", " ");
    addInfo("得分", QString::number(score, 'f', 2));
}
