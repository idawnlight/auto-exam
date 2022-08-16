/**
 * @project Automatic Examination
 * @file SingleChoiceProblemEditor.cpp
 * @location src/ui/widgets/problemEditor
 * @brief This message displayed in Doxygen Files index
 * @date 2022/8/16
 */

#include "SingleChoiceProblemEditor.h"

SingleChoiceProblemEditor::SingleChoiceProblemEditor(QWidget *parent) : QWidget(parent) {
    auto layout = new QVBoxLayout(this);

    auto contentEdit = new QTextEdit();
    auto addButton = new QPushButton("添加选项");
    layout->addWidget(addButton, 0, Qt::AlignLeft | Qt::AlignTop);

    setLayout(layout);
}

void SingleChoiceProblemEditor::setProblem(std::shared_ptr<SingleChoiceProblem> p) {
    this->problem = p;
}

std::shared_ptr<SingleChoiceProblem> SingleChoiceProblemEditor::getProblem() {
    return this->problem;
}

void SingleChoiceProblemEditor::refresh() {

}

void SingleChoiceProblemEditor::addOption() {

}

void SingleChoiceProblemEditor::removeOption(int index) {

}
