/**
 * @project Automatic Examination
 * @file ShortAnswerProblem.cpp
 * @location src/models/problems
 * @brief Derived class for ShortAnswerProblem
 * @date 2022/8/12
 */

#include "ShortAnswerProblem.h"

ShortAnswerProblem::ShortAnswerProblem()
{
    problemType = ShortAnswer;
    keywords = std::set<std::string>();
}

json ShortAnswerProblem::toJson()
{
    auto j = BaseProblem::toJson();
    j["keywords"] = keywords;
    return j;
}

ShortAnswerProblem::ShortAnswerProblem(json j) : BaseProblem(j)
{
    j.at("keywords").get_to(keywords);
}

const std::set<std::string> &ShortAnswerProblem::getKeywords() const
{
    return keywords;
}

void ShortAnswerProblem::setKeywords(const std::set<std::string> &keywords)
{
    ShortAnswerProblem::keywords = keywords;
}

double ShortAnswerProblem::evaluate(json ans)
{
    if (!ans.is_array() || ans.empty())
    {
        return 0;
    } else if (keywords.empty())
    {
        return score;
    } else
    {
        std::string sAns = ans[0];
        int part = 0;

        for (auto keyword: keywords)
        {
            if (sAns.find(keyword) != std::string::npos)
            {
                part++;
            }
        }

        return score * ((double) part / keywords.size());
    }
}

std::string ShortAnswerProblem::getKeywordsString()
{
    if (keywords.empty())
    {
        return "";
    }

    std::string keywordsString = "";
    bool first = true;

    for (auto i: keywords)
    {
        if (!first)
        {
            keywordsString += "，";
        } else
        {
            first = false;
        }
        keywordsString += i;
    }

    return keywordsString;
}
