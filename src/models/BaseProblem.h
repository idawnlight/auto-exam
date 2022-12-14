/**
 * @project Automatic Examination
 * @file BaseProblem.h
 * @location src/models
 * @brief BaseModel for problems
 * @date 2022/8/12
 */

#ifndef AUTO_EXAM_BASEPROBLEM_H
#define AUTO_EXAM_BASEPROBLEM_H

#include "nlohmann/json.hpp"

using json = nlohmann::json;

enum ProblemType
{
    SingleChoice = 0,
    MultipleChoice = 1,
    TrueOrFalse = 2,
    ShortAnswer = 3,
    Default = -1
};

class BaseProblem
{
protected:
    ProblemType problemType = Default;
    double score;
    std::string content;

public:
    BaseProblem();
    BaseProblem(json);

    ProblemType getProblemType() const;
    void setProblemType(ProblemType type);
    double getScore() const;
    void setScore(int score);
    const std::string &getContent() const;
    void setContent(const std::string &content);

    virtual double evaluate(json ans);
    virtual int checkAnswer(json) const;
    virtual json toJson();
};


#endif //AUTO_EXAM_BASEPROBLEM_H
