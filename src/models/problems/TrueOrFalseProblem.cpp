/**
 * @project Automatic Examination
 * @file TrueOrFalseProblem.cpp
 * @location src/models/problems
 * @brief Derived class for TrueOrFalseProblem
 * @date 2022/8/12
 */

#include "TrueOrFalseProblem.h"

TrueOrFalseProblem::TrueOrFalseProblem() {
    problemType = TrueOrFalse;
    answer = true;
}

TrueOrFalseProblem::TrueOrFalseProblem(bool ans) : answer(ans) {
    problemType = TrueOrFalse;
}

TrueOrFalseProblem::TrueOrFalseProblem(json j) : BaseProblem(j) {
    j.at("answer").get_to(answer);
}

json TrueOrFalseProblem::toJson() {
    auto j = BaseProblem::toJson();
    j["answer"] = answer;
    return j;
}

bool TrueOrFalseProblem::getAnswer() const {
    return answer;
}

void TrueOrFalseProblem::setAnswer(bool answer) {
    TrueOrFalseProblem::answer = answer;
}

double TrueOrFalseProblem::evaluate(json ans) {
    if (!ans.is_array() || ans.empty() || ans[0] != answer) {
        return 0;
    } else {
        return score;
    }
}
