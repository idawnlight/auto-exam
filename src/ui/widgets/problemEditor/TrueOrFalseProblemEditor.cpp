/**
 * @project Automatic Examination
 * @file TrueOrFalseProblemEditor.cpp
 * @location src/ui/widgets/problemViewer
 * @brief This message displayed in Doxygen Files index
 * @date 2022/8/16
 */

#include "TrueOrFalseProblemEditor.h"

TrueOrFalseProblemEditor::TrueOrFalseProblemEditor(QWidget *parent)
    : BaseProblemEditor(parent), optionLayout(new QVBoxLayout) {

    auto optionRight = new RemovableLabel(1, QString("正确"));
    optionRight->enableRadio(contentEdit);
    optionLayout->addLayout(optionRight);

    auto optionWrong = new RemovableLabel(0, QString("错误"));
    optionWrong->enableRadio(contentEdit);
    optionLayout->addLayout(optionWrong);

    options.push_back(optionWrong);
    options.push_back(optionRight);

    connect(optionRight, &RemovableLabel::radio, this, &TrueOrFalseProblemEditor::setAnswer);
    connect(optionWrong, &RemovableLabel::radio, this, &TrueOrFalseProblemEditor::setAnswer);

    layout->addLayout(optionLayout);

    layout->addLayout(buttonLayout);

    layout->addStretch();
}

void TrueOrFalseProblemEditor::setProblem(std::shared_ptr<TrueOrFalseProblem> p) {
    this->problem = p;
    noSaving = true;
    refresh();
    noSaving = false;
}

std::shared_ptr<TrueOrFalseProblem> TrueOrFalseProblemEditor::getProblem() {
    return this->problem;
}

void TrueOrFalseProblemEditor::refresh() {
    if (this->problem == nullptr) {
        return;
    }

    contentEdit->setPlainText(QString::fromStdString(this->problem->getContent()));

    options[0]->setRadioChecked(!this->problem->getAnswer());
    options[1]->setRadioChecked(this->problem->getAnswer());
}

void TrueOrFalseProblemEditor::setAnswer(int index) {
    this->problem->setAnswer(index);
}

void TrueOrFalseProblemEditor::setScore() {
    bool ok;
    double d = QInputDialog::getDouble(this, "设定分值",
                                       "分值", this->problem->getScore(), 0, 100, 2, &ok,
                                       Qt::WindowFlags(), 1);
    if (ok) {
        this->problem->setScore(d);

        emit problemChanged(this->problem);
    }
}

void TrueOrFalseProblemEditor::saveProblem() {
    if (this->problem == nullptr || noSaving) {
        return;
    }

    this->problem->setContent(contentEdit->toPlainText().toStdString());
}
