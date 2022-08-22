/**
 * @project Automatic Examination
 * @file ProblemLabel.cpp
 * @location src/ui/widgets
 * @brief Problem Label for problem info
 * @date 2022/8/17
 */

#include "ProblemLabel.h"

ProblemLabel::ProblemLabel(QWidget *parent) : QLabel("<h2>当前题目</h2>", parent)
{

}

void ProblemLabel::setProblem(std::shared_ptr<BaseProblem> p)
{
    if (!p)
    {
        setText("<h2>当前题目</h2>");
    } else
    {
        QString problemType;

        switch (p->getProblemType())
        {
            case ProblemType::SingleChoice:
                problemType = "单选题";
                break;
            case ProblemType::MultipleChoice:
                problemType = "多选题";
                break;
            case ProblemType::TrueOrFalse:
                problemType = "判断题";
                break;
            case ProblemType::ShortAnswer:
                problemType = "简答题";
                break;
            default:
                problemType = "未知题目类型";
                break;
        }

        setText(QString("<h2>当前题目（%1，本题 %2 分）</h2>").arg(problemType).arg(p->getScore()));
    }
}
