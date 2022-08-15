/**
 * @project Automatic Examination
 * @file AnswerPaper.h
 * @location src/models
 * @brief User-input answers
 * @date 2022/8/12
 */

#ifndef AUTO_EXAM_ANSWERPAPER_H
#define AUTO_EXAM_ANSWERPAPER_H

#include "Paper.h"

class AnswerPaper {
public:
    explicit AnswerPaper();
    explicit AnswerPaper(const std::shared_ptr<Paper> &paper);

    const std::shared_ptr<Paper> &getPaper() const;
    void setPaper(const std::shared_ptr<Paper> &paper);
    const std::vector<json> &getAnswers() const;
    void setAnswers(const std::vector<json> &answers);

protected:
    std::shared_ptr<Paper> paper;
    std::vector<json> answers;
};


#endif //AUTO_EXAM_ANSWERPAPER_H
