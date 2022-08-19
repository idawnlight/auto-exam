/**
 * @project Automatic Examination
 * @file BaseProblemViewer.cpp
 * @location src/ui/widgets/problemViewer
 * @brief This message displayed in Doxygen Files index
 * @date 2022/8/19
 */

#include "BaseProblemViewer.h"

BaseProblemViewer::BaseProblemViewer(QWidget *parent)
    : QWidget(parent), layout(new QVBoxLayout(this)), problemContent(new QLabel()), problemAnswer(new QLabel()) {
//    problemContent->setFixedHeight(92);
    layout->setAlignment(Qt::AlignTop);

    layout->addWidget(problemContent);
    layout->addWidget(problemAnswer);

    problemAnswer->setVisible(false);
}

void BaseProblemViewer::setEvaluated() {
    evaluated = true;
}
