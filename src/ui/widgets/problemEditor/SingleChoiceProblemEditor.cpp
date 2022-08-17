/**
 * @project Automatic Examination
 * @file SingleChoiceProblemEditor.cpp
 * @location src/ui/widgets/problemEditor
 * @brief This message displayed in Doxygen Files index
 * @date 2022/8/16
 */

#include "SingleChoiceProblemEditor.h"

SingleChoiceProblemEditor::SingleChoiceProblemEditor(QWidget *parent)
    : QWidget(parent), contentEdit(new QPlainTextEdit(this)) {
    auto layout = new QVBoxLayout(this);

    contentEdit->setFixedHeight(92);
    layout->addWidget(contentEdit, 0);

    auto buttonLayout = new QHBoxLayout();
    auto addButton = new QPushButton("添加选项");
    buttonLayout->addWidget(addButton, 0);

    auto scoreButton = new QPushButton("设置分值");
    buttonLayout->addWidget(scoreButton, 0);
    buttonLayout->setAlignment(Qt::AlignLeft | Qt::AlignTop);

    layout->addLayout(buttonLayout, 0);

    setLayout(layout);
}

void SingleChoiceProblemEditor::setProblem(std::shared_ptr<SingleChoiceProblem> p) {
    this->problem = p;
    refresh();
}

std::shared_ptr<SingleChoiceProblem> SingleChoiceProblemEditor::getProblem() {
    return this->problem;
}

void SingleChoiceProblemEditor::refresh() {
    if (this->problem == nullptr) {
        return;
    }

    contentEdit->setPlainText(QString::fromStdString(this->problem->getContent()));
}

void SingleChoiceProblemEditor::addOption() {

}

void SingleChoiceProblemEditor::removeOption(int index) {

}
