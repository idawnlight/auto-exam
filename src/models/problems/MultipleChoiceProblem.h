/**
 * @project Automatic Examination
 * @file MultipleChoiceProblem.h
 * @location src/models/problems
 * @brief Derived class for MultipleChoiceProblem
 * @date 2022/8/12
 */

#ifndef AUTO_EXAM_MULTIPLECHOICEPROBLEM_H
#define AUTO_EXAM_MULTIPLECHOICEPROBLEM_H

#include <set>

#include "../BaseProblem.h"

class MultipleChoiceProblem : public BaseProblem {
protected:
    std::set<int> answer;
    std::vector<std::string> options;

public:
    MultipleChoiceProblem();
    MultipleChoiceProblem(json);

    const std::set<int> &getAnswer() const;
    void setAnswer(const std::set<int> &answer);
    const std::vector<std::string> &getOptions() const;
    void setOptions(const std::vector<std::string> &options);

    double evaluate(json ans) override;

    json toJson() override;
};


#endif //AUTO_EXAM_MULTIPLECHOICEPROBLEM_H
