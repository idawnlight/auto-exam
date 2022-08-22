/**
 * @project Automatic Examination
 * @file EditInfoLayout.cpp
 * @location src/ui/widgets/infoLayout
 * @brief Aligned Info Layout for editing
 * @date 2022/8/15
 */

#include "EditInfoLayout.h"

EditInfoLayout::EditInfoLayout(QWidget *parent) : AlignedInfoLayout(parent)
{
    addInfo("已出题目数", "0");
    addInfo("已出分值", "0");
    addInfo(" ", " ");
    addInfo("单选题数", "0");
    addInfo("多选题数", "0");
    addInfo("判断题数", "0");
    addInfo("简答题数", "0");
}

void EditInfoLayout::updateEditInfo(std::shared_ptr<Paper> p)
{
    updateInfo("已出题目数", QString::number(p->problemCount()));
    updateInfo("已出分值", QString::number(p->scoreCount()));

    updateInfo("单选题数", QString::number(p->problemCount(SingleChoice)));
    updateInfo("多选题数", QString::number(p->problemCount(MultipleChoice)));
    updateInfo("判断题数", QString::number(p->problemCount(TrueOrFalse)));
    updateInfo("简答题数", QString::number(p->problemCount(ShortAnswer)));
}
