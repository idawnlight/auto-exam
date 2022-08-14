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
protected:
    std::shared_ptr<Paper> paper;
};


#endif //AUTO_EXAM_ANSWERPAPER_H
