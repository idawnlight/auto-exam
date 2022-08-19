/**
 * @project Automatic Examination
 * @file TrueOrFalseProblem.h
 * @location src/models/problems
 * @brief Derived class for TrueOrFalseProblem
 * @date 2022/8/12
 */

#ifndef AUTO_EXAM_TRUEORFALSEPROBLEM_H
#define AUTO_EXAM_TRUEORFALSEPROBLEM_H

#include "../BaseProblem.h"

class TrueOrFalseProblem : public BaseProblem {
protected:
    bool answer;

public:
    TrueOrFalseProblem();
    TrueOrFalseProblem(bool answer);
    TrueOrFalseProblem(json);

    bool getAnswer() const;
    void setAnswer(bool answer);

    json toJson() override;
};


#endif //AUTO_EXAM_TRUEORFALSEPROBLEM_H
