/**
 * @project Automatic Examination
 * @file MultipleChoiceProblemEditor.cpp
 * @location src/ui/widgets/problemEditor
 * @brief This message displayed in Doxygen Files index
 * @date 2022/8/16
 */

#include "MultipleChoiceProblemEditor.h"

MultipleChoiceProblemEditor::MultipleChoiceProblemEditor(QWidget *parent)
    : BaseProblemEditor(parent), optionLayout(new QVBoxLayout) {

    layout->addLayout(optionLayout, 1);

    auto addButton = new QPushButton("添加选项");
    buttonLayout->addWidget(addButton, 0);
    connect(addButton, &QAbstractButton::clicked, this, &MultipleChoiceProblemEditor::addOption);

    layout->addLayout(buttonLayout, 0);
}

void MultipleChoiceProblemEditor::setProblem(std::shared_ptr<MultipleChoiceProblem> p) {
    this->problem = p;
    noSaving = true;
    refresh();
    noSaving = false;
}

std::shared_ptr<MultipleChoiceProblem> MultipleChoiceProblemEditor::getProblem() {
    return this->problem;
}

void MultipleChoiceProblemEditor::refresh() {
    if (this->problem == nullptr) {
        return;
    }

    contentEdit->setPlainText(QString::fromStdString(this->problem->getContent()));

    for (auto option : this->options) {
        delete option;
    }

    this->options.clear();

    for (int i = 0; i < this->problem->getOptions().size(); i++) {
        auto option = new RemovableLineEdit(i, QString::fromStdString(this->problem->getOptions()[i]));
        auto answers = this->problem->getAnswer();
        option->enableCheckbox(contentEdit, answers.find(i) != answers.end());
        connect(option, &RemovableLineEdit::checked, this, &MultipleChoiceProblemEditor::setAnswer);
        connect(option, &RemovableLineEdit::remove, this, &MultipleChoiceProblemEditor::removeOption);
        connect(option, &RemovableLineEdit::editingFinished, this, &MultipleChoiceProblemEditor::saveProblem);
        this->options.push_back(option);
        this->optionLayout->addLayout(option);
    }
}

void MultipleChoiceProblemEditor::addOption() {
    auto option = new RemovableLineEdit(options.count());

    option->enableCheckbox(contentEdit);

    connect(option, &RemovableLineEdit::checked, this, &MultipleChoiceProblemEditor::setAnswer);
    connect(option, &RemovableLineEdit::remove, this, &MultipleChoiceProblemEditor::removeOption);
    connect(option, &RemovableLineEdit::editingFinished, this, &MultipleChoiceProblemEditor::saveProblem);

    options.push_back(option);
    optionLayout->addLayout(option);
}

void MultipleChoiceProblemEditor::removeOption(int index) {
    delete this->options[index];
    this->options.erase(this->options.begin() + index);

    saveProblem();
}

void MultipleChoiceProblemEditor::setAnswer() {
    std::set<int> answers;

    for (int i = 0; i < options.count(); i++) {
        if (options[i]->isChecked()) {
            answers.insert(i);
        }
    }

    this->problem->setAnswer(answers);
}

void MultipleChoiceProblemEditor::setScore() {
    bool ok;
    double d = QInputDialog::getDouble(this, "设定分值",
                                       "分值", this->problem->getScore(), 0, 100, 2, &ok,
                                       Qt::WindowFlags(), 1);
    if (ok) {
        this->problem->setScore(d);

        emit problemChanged(this->problem);
    }
}

void MultipleChoiceProblemEditor::saveProblem() {
    if (this->problem == nullptr || noSaving) {
        return;
    }

    this->problem->setContent(contentEdit->toPlainText().toStdString());

    std::vector<std::string> problemOptions;

    for (int i = 0; i < options.count(); i++) {
        problemOptions.push_back(options[i]->getContent().toStdString());
    }

    this->problem->setOptions(problemOptions);
}


