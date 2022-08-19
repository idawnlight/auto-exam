/**
 * @project Automatic Examination
 * @file ProblemEditor.cpp
 * @location src/ui/widgets
 * @brief This message displayed in Doxygen Files index
 * @date 2022/8/15
 */

#include "ProblemEditor.h"

ProblemEditor::ProblemEditor(QWidget *parent, std::shared_ptr<BaseProblem> problem)
    : QVBoxLayout(parent),
      stackedWidget(new QStackedWidget()),
      problem(problem),
      emptyWidget(new QWidget),
      singleChoiceProblemEditor(new SingleChoiceProblemEditor),
      multipleChoiceProblemEditor(new MultipleChoiceProblemEditor),
      trueOrFalseProblemEditor(new TrueOrFalseProblemEditor),
      shortAnswerProblemEditor(new ShortAnswerProblemEditor),
      navigatorWidget(new NavigatorWidget) {
    addWidget(stackedWidget);

    stackedWidget->addWidget(singleChoiceProblemEditor);
    stackedWidget->addWidget(multipleChoiceProblemEditor);
    stackedWidget->addWidget(trueOrFalseProblemEditor);
    stackedWidget->addWidget(shortAnswerProblemEditor);

    connect(singleChoiceProblemEditor, &SingleChoiceProblemEditor::problemChanged, this,
            &ProblemEditor::problemChanged);
    connect(multipleChoiceProblemEditor, &MultipleChoiceProblemEditor::problemChanged, this,
            &ProblemEditor::problemChanged);
    connect(trueOrFalseProblemEditor, &TrueOrFalseProblemEditor::problemChanged, this,
            &ProblemEditor::problemChanged);
    connect(shortAnswerProblemEditor, &ShortAnswerProblemEditor::problemChanged, this,
            &ProblemEditor::problemChanged);

    stackedWidget->addWidget(emptyWidget);

    auto bottomLayout = new QHBoxLayout();

    removeButton = new QPushButton("删除问题");
    removeButton->setEnabled(false);
    bottomLayout->addWidget(removeButton);
    connect(removeButton, &QAbstractButton::clicked, this, &ProblemEditor::removeProblemClicked);

    bottomLayout->addStretch();

    bottomLayout->addWidget(navigatorWidget);
    connect(navigatorWidget, &NavigatorWidget::previous, this, &ProblemEditor::navigateProblemPrevious);
    connect(navigatorWidget, &NavigatorWidget::next, this, &ProblemEditor::navigateProblemNext);

    addLayout(bottomLayout, 0);

    if (problem != nullptr) {
        refresh();
    } else {
        stackedWidget->setCurrentWidget(emptyWidget);
    }
}

void ProblemEditor::refresh() {
    if (this->problem == nullptr) {
        removeButton->setEnabled(false);
        navigatorWidget->setStatus(NavigatorStatus::None);
        stackedWidget->setCurrentWidget(emptyWidget);
        return;
    }

    removeButton->setEnabled(true);

    switch (problem->getProblemType()) {
        case SingleChoice:
        {
            auto tmp = std::static_pointer_cast<SingleChoiceProblem>(this->problem);
            singleChoiceProblemEditor->setProblem(tmp);
        }
            break;
        case MultipleChoice:
        {
            auto tmp = std::static_pointer_cast<MultipleChoiceProblem>(this->problem);
            multipleChoiceProblemEditor->setProblem(tmp);
        }
            break;
        case TrueOrFalse:
        {
            auto tmp = std::static_pointer_cast<TrueOrFalseProblem>(this->problem);
            trueOrFalseProblemEditor->setProblem(tmp);
        }
            break;
        case ShortAnswer:
        {
            auto tmp = std::static_pointer_cast<ShortAnswerProblem>(this->problem);
            shortAnswerProblemEditor->setProblem(tmp);
        }
            break;
        default:
            qDebug() << "Default";
            break;
    }

    stackedWidget->setCurrentIndex(problem->getProblemType());
}

void ProblemEditor::setProblem(std::shared_ptr<BaseProblem> problem, int index, NavigatorStatus status) {
    currentIndex = index;
    this->problem = problem;
    navigatorWidget->setStatus(status);
    refresh();

    emit problemChanged(problem);
}

void ProblemEditor::removeProblemClicked() {
    int ret = QMessageBox::question(nullptr, "删除问题", "确定删除该问题吗？");

    if (ret == QMessageBox::Yes) {
        emit removeProblem(currentIndex);
    }
}

void ProblemEditor::navigateProblemPrevious() {
    emit navigateProblem(currentIndex - 1);
}

void ProblemEditor::navigateProblemNext() {
    emit navigateProblem(currentIndex + 1);
}
