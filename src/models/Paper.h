/**
 * @project Automatic Examination
 * @file Paper.h
 * @location src/models
 * @brief Model for a full paper
 * @date 2022/8/12
 */

#ifndef AUTO_EXAM_PAPER_H
#define AUTO_EXAM_PAPER_H

#include "BaseProblem.h"

#include "problems/SingleChoiceProblem.h"
#include "problems/MultipleChoiceProblem.h"
#include "problems/TrueOrFalseProblem.h"
#include "problems/ShortAnswerProblem.h"

#include <vector>

class Paper {
public:
    std::vector<std::shared_ptr<BaseProblem>> problems;
    json toJson() const;
    static Paper fromJson(const json);

public:
    void mock();
};

std::shared_ptr<BaseProblem> problemFromJson(const json j);

#endif //AUTO_EXAM_PAPER_H
