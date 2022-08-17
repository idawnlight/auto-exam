/**
 * @project Automatic Examination
 * @file ProblemLabel.cpp
 * @location src/ui/widgets
 * @brief This message displayed in Doxygen Files index
 * @date 2022/8/17
 */

#include "ProblemLabel.h"

ProblemLabel::ProblemLabel() : QLabel("<h2>当前题目</h2>") {

}

void ProblemLabel::setProblem(std::shared_ptr<BaseProblem> p, int index) {
    if (!p) {
        setText("<h2>当前题目</h2>");
    } else {
        setText(QString("<h2>当前题目（第 %1 题，本题 %2 分）</h2>").arg(index + 1).arg(p->getScore()));
    }
}
