/**
 * @project Automatic Examination
 * @file BaseProblem.cpp
 * @location src/models
 * @brief BaseModel for problems
 * @date 2022/8/12
 */

#include "BaseProblem.h"

BaseProblem::BaseProblem() : problemType(Default), score(1)
{

}

BaseProblem::BaseProblem(json j)
{
    j.at("problemType").get_to(problemType);
    j.at("score").get_to(score);
    j.at("content").get_to(content);
}

ProblemType BaseProblem::getProblemType() const
{
    return this->problemType;
}

void BaseProblem::setProblemType(ProblemType type)
{
    this->problemType = type;
}

double BaseProblem::getScore() const
{
    return this->score;
}

void BaseProblem::setScore(int score)
{
    this->score = score;
}

int BaseProblem::checkAnswer(json) const
{
    return score;
}

json BaseProblem::toJson()
{
    return json{
            {"problemType", problemType},
            {"score",       score},
            {"content",     content}
    };
}

const std::string &BaseProblem::getContent() const
{
    return content;
}

void BaseProblem::setContent(const std::string &content)
{
    BaseProblem::content = content;
}

double BaseProblem::evaluate(json ans)
{
    return score;
}
