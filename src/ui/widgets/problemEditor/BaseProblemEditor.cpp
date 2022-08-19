/**
 * @project Automatic Examination
 * @file BaseProblemEditor.cpp
 * @location src/ui/widgets/problemViewer
 * @brief This message displayed in Doxygen Files index
 * @date 2022/8/18
 */

#include "BaseProblemEditor.h"

BaseProblemEditor::BaseProblemEditor(QWidget *parent)
    : QWidget(parent), layout(new QVBoxLayout(this)), contentEdit(new QPlainTextEdit()), buttonLayout(new QHBoxLayout()) {
    contentEdit->setFixedHeight(92);
    layout->addWidget(contentEdit);
    connect(contentEdit, &QPlainTextEdit::textChanged, this, &BaseProblemEditor::saveProblem);

    auto scoreButton = new QPushButton("设置分值");
    connect(scoreButton, &QPushButton::clicked, this, &BaseProblemEditor::setScore);

    buttonLayout->addWidget(scoreButton);
    buttonLayout->setAlignment(Qt::AlignLeft | Qt::AlignTop);
}
