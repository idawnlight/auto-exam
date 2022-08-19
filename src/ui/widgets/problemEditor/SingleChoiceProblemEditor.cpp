/**
 * @project Automatic Examination
 * @file SingleChoiceProblemEditor.cpp
 * @location src/ui/widgets/problemEditor
 * @brief This message displayed in Doxygen Files index
 * @date 2022/8/16
 */

#include "SingleChoiceProblemEditor.h"

SingleChoiceProblemEditor::SingleChoiceProblemEditor(QWidget *parent)
    : BaseProblemEditor(parent), optionLayout(new QVBoxLayout) {

    layout->addLayout(optionLayout, 1);

    auto addButton = new QPushButton("添加选项");
    buttonLayout->addWidget(addButton, 0);
    connect(addButton, &QAbstractButton::clicked, this, &SingleChoiceProblemEditor::addOption);

    layout->addLayout(buttonLayout, 0);
}

void SingleChoiceProblemEditor::setProblem(std::shared_ptr<SingleChoiceProblem> p) {
    this->problem = p;
    noSaving = true;
    refresh();
    noSaving = false;
}

std::shared_ptr<SingleChoiceProblem> SingleChoiceProblemEditor::getProblem() {
    return this->problem;
}

void SingleChoiceProblemEditor::refresh() {
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
        option->enableRadio(contentEdit, i == this->problem->getAnswer());
        connect(option, &RemovableLineEdit::radio, this, &SingleChoiceProblemEditor::setAnswer);
        connect(option, &RemovableLineEdit::remove, this, &SingleChoiceProblemEditor::removeOption);
        connect(option, &RemovableLineEdit::editingFinished, this, &SingleChoiceProblemEditor::saveProblem);
        this->options.push_back(option);
        this->optionLayout->addLayout(option);
    }
}

void SingleChoiceProblemEditor::addOption() {
    auto option = new RemovableLineEdit(options.count());

    option->enableRadio(contentEdit);

    connect(option, &RemovableLineEdit::radio, this, &SingleChoiceProblemEditor::setAnswer);
    connect(option, &RemovableLineEdit::remove, this, &SingleChoiceProblemEditor::removeOption);
    connect(option, &RemovableLineEdit::editingFinished, this, &SingleChoiceProblemEditor::saveProblem);

    options.push_back(option);
    optionLayout->addLayout(option);
}

void SingleChoiceProblemEditor::removeOption(int index) {
    delete this->options[index];
    this->options.erase(this->options.begin() + index);

    saveProblem();
}

void SingleChoiceProblemEditor::setAnswer(int index) {
    this->problem->setAnswer(index);
}

void SingleChoiceProblemEditor::setScore() {
    bool ok;
    double d = QInputDialog::getDouble(this, "设定分值",
                                       "分值", this->problem->getScore(), 0, 100, 2, &ok,
                                       Qt::WindowFlags(), 1);
    if (ok) {
        this->problem->setScore(d);

        emit problemChanged(this->problem);
    }
}

void SingleChoiceProblemEditor::saveProblem() {
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
