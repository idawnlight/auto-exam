/**
 * @project Automatic Examination
 * @file Paper.cpp
 * @location src/models
 * @brief Model for a full paper
 * @date 2022/8/12
 */

#include "Paper.h"

json Paper::toJson() const
{
    auto j = json();
    for (auto i: problems)
    {
        j.push_back(i->toJson());
    }
    return j;
}

Paper Paper::fromJson(const json j)
{
    Paper p;
    for (auto i: j)
    {
        p.problems.push_back(problemFromJson(i));
    }
    return p;
}

std::shared_ptr<BaseProblem> Paper::getProblem(int index)
{
    return problems[index];
}

int Paper::problemCount()
{
    return problems.size();
}

int Paper::problemCount(ProblemType t)
{
    int count = 0;
    for (auto i: problems)
    {
        if (i->getProblemType() == t)
        {
            count++;
        }
    }
    return count;
}

double Paper::scoreCount()
{
    double score = 0;
    for (auto i: problems)
    {
        score += i->getScore();
    }
    return score;
}

std::vector<std::shared_ptr<BaseProblem>> &Paper::getProblems()
{
    return problems;
}

std::shared_ptr<BaseProblem> problemFromJson(const json j)
{
    switch (j.at("problemType").get<ProblemType>())
    {
        case SingleChoice:
            return std::make_shared<SingleChoiceProblem>(j);
        case MultipleChoice:
            return std::make_shared<MultipleChoiceProblem>(j);
        case TrueOrFalse:
            return std::make_shared<TrueOrFalseProblem>(j);
        case ShortAnswer:
            return std::make_shared<ShortAnswerProblem>(j);
        default:
            return std::make_shared<BaseProblem>(j);
    }
}
