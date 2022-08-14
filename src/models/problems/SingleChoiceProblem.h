/**
 * @project Automatic Examination
 * @file SingleChoiceProblem.h
 * @location src/models/problems
 * @brief Derived class for SingleChoiceProblem
 * @date 2022/8/12
 */

#ifndef AUTO_EXAM_SINGLECHOICEPROBLEM_H
#define AUTO_EXAM_SINGLECHOICEPROBLEM_H

#include "../BaseProblem.h"

class SingleChoiceProblem : public BaseProblem {
protected:
    int answer;

public:
    SingleChoiceProblem();
    SingleChoiceProblem(json);

    json toJson() override;
};


#endif //AUTO_EXAM_SINGLECHOICEPROBLEM_H
