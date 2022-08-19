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
    keywords = std::set<std::string>();
}

json ShortAnswerProblem::toJson() {
    auto j = BaseProblem::toJson();
    j["keywords"] = keywords;
    return j;
}

ShortAnswerProblem::ShortAnswerProblem(json j) : BaseProblem(j) {
    j.at("keywords").get_to(keywords);
}

const std::set<std::string> &ShortAnswerProblem::getKeywords() const {
    return keywords;
}

void ShortAnswerProblem::setKeywords(const std::set<std::string> &keywords) {
    ShortAnswerProblem::keywords = keywords;
}
