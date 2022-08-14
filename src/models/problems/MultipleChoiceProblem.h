/**
 * @project Automatic Examination
 * @file MultipleChoiceProblem.h
 * @location src/models/problems
 * @brief Derived class for MultipleChoiceProblem
 * @date 2022/8/12
 */

#ifndef AUTO_EXAM_MULTIPLECHOICEPROBLEM_H
#define AUTO_EXAM_MULTIPLECHOICEPROBLEM_H

#include "../BaseProblem.h"

class MultipleChoiceProblem : public BaseProblem {
protected:
    std::vector<int> answer;

public:
    MultipleChoiceProblem();
    MultipleChoiceProblem(json);

    json toJson() override;
};


#endif //AUTO_EXAM_MULTIPLECHOICEPROBLEM_H
