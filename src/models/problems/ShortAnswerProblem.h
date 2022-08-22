/**
 * @project Automatic Examination
 * @file ShortAnswerProblem.h
 * @location src/models/problems
 * @brief Derived class for ShortAnswerProblem
 * @date 2022/8/12
 */

#ifndef AUTO_EXAM_SHORTANSWERPROBLEM_H
#define AUTO_EXAM_SHORTANSWERPROBLEM_H

#include <set>

#include "../BaseProblem.h"

class ShortAnswerProblem : public BaseProblem
{
protected:
    std::set<std::string> keywords;

public:
    ShortAnswerProblem();
    ShortAnswerProblem(json);

    const std::set<std::string> &getKeywords() const;
    void setKeywords(const std::set<std::string> &keywords);
    std::string getKeywordsString();
    double evaluate(json ans) override;
    json toJson() override;
};


#endif //AUTO_EXAM_SHORTANSWERPROBLEM_H
