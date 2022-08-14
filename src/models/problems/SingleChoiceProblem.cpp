/**
 * @project Automatic Examination
 * @file SingleChoiceProblem.cpp
 * @location src/models/problems
 * @brief Derived class for SingleChoiceProblem
 * @date 2022/8/12
 */

#include "SingleChoiceProblem.h"

SingleChoiceProblem::SingleChoiceProblem() {
    problemType = SingleChoice;
    answer = 0;
}

SingleChoiceProblem::SingleChoiceProblem(json j) : BaseProblem(j) {
    j.at("answer").get_to(answer);
}

json SingleChoiceProblem::toJson() {
    auto j = BaseProblem::toJson();
    j["answer"] = answer;
    return j;
}
