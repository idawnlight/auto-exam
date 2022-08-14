/**
 * @project Automatic Examination
 * @file BaseProblem.cpp
 * @location src/models
 * @brief BaseModel for problems
 * @date 2022/8/12
 */

#include "BaseProblem.h"

BaseProblem::BaseProblem() : problemType(Unknown), score(1) {

}

BaseProblem::BaseProblem(json j) {
    j.at("problemType").get_to(problemType);
    j.at("score").get_to(score);
}

ProblemType BaseProblem::getProblemType() const {
    return this->problemType;
}

void BaseProblem::setProblemType(ProblemType type) {
    this->problemType = type;
}

int BaseProblem::getScore() const {
    return this->score;
}

void BaseProblem::setScore(int score) {
    this->score = score;
}

int BaseProblem::checkAnswer(json) const {
    return score;
}

json BaseProblem::toJson() {
    return json{
        {"problemType",  problemType},
        {"score", score}
    };
}
