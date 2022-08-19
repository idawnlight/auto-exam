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
    j.at("options").get_to(options);
}

json MultipleChoiceProblem::toJson() {
    auto j = BaseProblem::toJson();
    j["answer"] = answer;
    j["options"] = options;
    return j;
}

const std::set<int> &MultipleChoiceProblem::getAnswer() const {
    return answer;
}

void MultipleChoiceProblem::setAnswer(const std::set<int> &answer) {
    MultipleChoiceProblem::answer = answer;
}

const std::vector<std::string> &MultipleChoiceProblem::getOptions() const {
    return options;
}

void MultipleChoiceProblem::setOptions(const std::vector<std::string> &options) {
    MultipleChoiceProblem::options = options;
}

double MultipleChoiceProblem::evaluate(json ans) {
    if (!ans.is_array() || ans.empty() || ans.size() > answer.size()) {
        return 0;
    } else if (answer.empty()) {
        return score;
    } else {
        for (const auto& userAns : ans) {
            if (!ans.contains(userAns)) return 0;
        }

        return (ans.size() == answer.size()) ? score : score / 2;
    }
}
