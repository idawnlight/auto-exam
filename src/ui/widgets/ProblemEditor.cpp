/**
 * @project Automatic Examination
 * @file ProblemEditor.cpp
 * @location src/ui/widgets
 * @brief This message displayed in Doxygen Files index
 * @date 2022/8/15
 */

#include "ProblemEditor.h"

ProblemEditor::ProblemEditor(QWidget *parent, std::shared_ptr<BaseProblem> problem)
    : QVBoxLayout(parent), stackedWidget(new QStackedWidget()), problem(problem),
      emptyWidget(new QWidget), singleChoiceProblemEditor(new SingleChoiceProblemEditor) {
    addWidget(stackedWidget);

    stackedWidget->addWidget(singleChoiceProblemEditor);
    stackedWidget->addWidget(emptyWidget);

    if (problem != nullptr) {
        refresh();
    } else {
        stackedWidget->setCurrentIndex(1);
    }
}

void ProblemEditor::refresh() {
    if (this->problem == nullptr) {
        stackedWidget->setCurrentIndex(1);
        return;
    }

    switch (problem->getProblemType()) {
        case SingleChoice:
        {
            auto tmp = std::static_pointer_cast<SingleChoiceProblem>(this->problem);
            singleChoiceProblemEditor->setProblem(tmp);
        }
            break;
//        case MultipleChoice:
//        {
//            auto tmp = std::static_pointer_cast<MultipleChoiceProblem>(i);
//            std::cout << "MultipleChoice" << std::endl;
//        }
//            break;
//        case TrueOrFalse:
//        {
//            auto tmp = std::static_pointer_cast<TrueOrFalseProblem>(i);
//            std::cout << "TrueOrFalse" << std::endl;
//        }
//            break;
//        case ShortAnswer:
//        {
//            auto tmp = std::static_pointer_cast<ShortAnswerProblem>(i);
//            std::cout << "ShortAnswer" << std::endl;
//        }
//            break;
        default:
            qDebug() << "Default";
            break;
    }

    stackedWidget->setCurrentIndex(problem->getProblemType());
//    stackedWidget->setCurrentIndex(0);
}

void ProblemEditor::setProblem(std::shared_ptr<BaseProblem> problem, int index) {
    currentIndex = index;
    this->problem = problem;
    refresh();
}
