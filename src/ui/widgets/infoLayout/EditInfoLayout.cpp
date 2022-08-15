/**
 * @project Automatic Examination
 * @file EditInfoLayout.cpp
 * @location src/ui/widgets/infoLayout
 * @brief This message displayed in Doxygen Files index
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
