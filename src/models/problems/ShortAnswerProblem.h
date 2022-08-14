/**
 * @project Automatic Examination
 * @file ShortAnswerProblem.h
 * @location src/models/problems
 * @brief Derived class for ShortAnswerProblem
 * @date 2022/8/12
 */

#ifndef AUTO_EXAM_SHORTANSWERPROBLEM_H
#define AUTO_EXAM_SHORTANSWERPROBLEM_H

#include "../BaseProblem.h"

class ShortAnswerProblem : public BaseProblem {
protected:
    std::vector<std::string> answer;

public:
    ShortAnswerProblem();
    ShortAnswerProblem(json);

    json toJson() override;
};


#endif //AUTO_EXAM_SHORTANSWERPROBLEM_H
