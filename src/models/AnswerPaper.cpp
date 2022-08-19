/**
 * @project Automatic Examination
 * @file AnswerPaper.cpp
 * @location src/models
 * @brief User-input answers
 * @date 2022/8/12
 */

#include "AnswerPaper.h"

AnswerPaper::AnswerPaper() {
    paper = std::make_shared<Paper>();
    answers.reserve(1000);
}

AnswerPaper::AnswerPaper(const std::shared_ptr<Paper> &paper) : paper(paper) {
    answers.reserve(1000);
}

std::shared_ptr<Paper> AnswerPaper::getPaper() {
    return paper;
}

void AnswerPaper::setPaper(const std::shared_ptr<Paper> &paper) {
    AnswerPaper::paper = paper;
}

const std::vector<json> &AnswerPaper::getAnswers() const {
    return answers;
}

void AnswerPaper::setAnswers(const std::vector<json> &answers) {
    AnswerPaper::answers = answers;
}

json AnswerPaper::getAnswer(int index) {
    return answers[index];
}

void AnswerPaper::setAnswer(int index, json answer) {
    answers[index] = answer;
}
