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
    j.at("options").get_to(options);
}

json SingleChoiceProblem::toJson() {
    auto j = BaseProblem::toJson();
    j["answer"] = answer;
    j["options"] = options;
    return j;
}

int SingleChoiceProblem::getAnswer() const {
    return answer;
}

void SingleChoiceProblem::setAnswer(int answer) {
    this->answer = answer;
}

std::vector<std::string> &SingleChoiceProblem::getOptions() {
    return options;
}

void SingleChoiceProblem::setOptions(const std::vector<std::string> &options) {
    this->options = options;
}
