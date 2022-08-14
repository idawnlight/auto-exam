/**
 * @project Automatic Examination
 * @file ShortAnswerProblem.cpp
 * @location src/models/problems
 * @brief Derived class for ShortAnswerProblem
 * @date 2022/8/12
 */

#include "ShortAnswerProblem.h"

ShortAnswerProblem::ShortAnswerProblem() {
    problemType = ShortAnswer;
    answer = std::vector<std::string>();
}

json ShortAnswerProblem::toJson() {
    auto j = BaseProblem::toJson();
    j["answer"] = answer;
    return j;
}

ShortAnswerProblem::ShortAnswerProblem(json j) : BaseProblem(j) {
    j.at("answer").get_to(answer);
}
