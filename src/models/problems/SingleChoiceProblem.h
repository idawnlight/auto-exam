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
    std::vector<std::string> options;

public:
    SingleChoiceProblem();
    SingleChoiceProblem(json);

    int getAnswer() const;
    void setAnswer(int answer);
    std::vector<std::string> &getOptions();
    void setOptions(const std::vector<std::string> &options);

    json toJson() override;
};


#endif //AUTO_EXAM_SINGLECHOICEPROBLEM_H
