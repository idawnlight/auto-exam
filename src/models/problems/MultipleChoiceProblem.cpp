/**
 * @project Automatic Examination
 * @file MultipleChoiceProblem.cpp
 * @location src/models/problems
 * @brief Derived class for MultipleChoiceProblem
 * @date 2022/8/12
 */

#include "MultipleChoiceProblem.h"

MultipleChoiceProblem::MultipleChoiceProblem() {
    problemType = MultipleChoice;
//    answer.push_back(0);
}

MultipleChoiceProblem::MultipleChoiceProblem(json j) : BaseProblem(j) {
    j.at("answer").get_to(answer);
}

json MultipleChoiceProblem::toJson() {
    auto j = BaseProblem::toJson();
    j["answer"] = answer;
    return j;
}
