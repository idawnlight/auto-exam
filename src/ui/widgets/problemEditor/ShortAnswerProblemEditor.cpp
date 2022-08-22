/**
 * @project Automatic Examination
 * @file ShortAnswerProblemEditor.cpp
 * @location src/ui/widgets/problemViewer
 * @date 2022/8/16
 */

#include "ShortAnswerProblemEditor.h"

ShortAnswerProblemEditor::ShortAnswerProblemEditor(QWidget *parent)
        : BaseProblemEditor(parent), keywordsLayout(new QVBoxLayout)
{

    layout->addLayout(keywordsLayout);

    auto addButton = new QPushButton("添加关键词");
    buttonLayout->addWidget(addButton);
    connect(addButton, &QAbstractButton::clicked, this, &ShortAnswerProblemEditor::addKeyword);

    layout->addLayout(buttonLayout);
}

void ShortAnswerProblemEditor::setProblem(std::shared_ptr<ShortAnswerProblem> p)
{
    this->problem = p;
    noSaving = true;
    refresh();
    noSaving = false;
}

std::shared_ptr<ShortAnswerProblem> ShortAnswerProblemEditor::getProblem()
{
    return this->problem;
}

void ShortAnswerProblemEditor::refresh()
{
    if (this->problem == nullptr)
    {
        return;
    }

    contentEdit->setPlainText(QString::fromStdString(this->problem->getContent()));

    for (auto keyword: this->keywords)
    {
        delete keyword;
    }

    this->keywords.clear();

    for (const auto &i: this->problem->getKeywords())
    {
        auto keyword = new RemovableLineEdit(0, QString::fromStdString(i));
        connect(keyword, &RemovableLineEdit::remove, this, &ShortAnswerProblemEditor::removeKeyword);
        connect(keyword, &RemovableLineEdit::editingFinished, this, &ShortAnswerProblemEditor::saveProblem);
        this->keywords.push_back(keyword);
        this->keywordsLayout->addLayout(keyword);
    }
}

void ShortAnswerProblemEditor::addKeyword()
{
    auto keyword = new RemovableLineEdit(keywords.count());

    connect(keyword, &RemovableLineEdit::remove, this, &ShortAnswerProblemEditor::removeKeyword);
    connect(keyword, &RemovableLineEdit::editingFinished, this, &ShortAnswerProblemEditor::saveProblem);

    keywords.push_back(keyword);
    keywordsLayout->addLayout(keyword);
}

void ShortAnswerProblemEditor::removeKeyword(int index)
{
    delete this->keywords[index];
    this->keywords.erase(this->keywords.begin() + index);

    saveProblem();
}

void ShortAnswerProblemEditor::setScore()
{
    bool ok;
    double d = QInputDialog::getDouble(this, "设定分值",
                                       "分值", this->problem->getScore(), 0, 100, 2, &ok,
                                       Qt::WindowFlags(), 1);
    if (ok)
    {
        this->problem->setScore(d);

        emit problemChanged(this->problem);
    }
}

void ShortAnswerProblemEditor::saveProblem()
{
    if (this->problem == nullptr || noSaving)
    {
        return;
    }

    this->problem->setContent(contentEdit->toPlainText().toStdString());

    std::set<std::string> problemKeywords;

    for (int i = 0; i < keywords.count(); i++)
    {
        problemKeywords.insert(keywords[i]->getContent().toStdString());
    }

    this->problem->setKeywords(problemKeywords);
}