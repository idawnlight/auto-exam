/**
 * @project Automatic Examination
 * @file RemovableLabel.cpp
 * @location src/ui/widgets/problemEditor
 * @brief This message displayed in Doxygen Files index
 * @date 2022/8/19
 */

#include "RemovableLabel.h"

RemovableLabel::RemovableLabel(int index, QString content)
    : QHBoxLayout(), index(index), label(new QLabel(content)), removeButton(new QPushButton("删除")),
      radioButton(new QRadioButton) {

    setAlignment(Qt::AlignLeft);
    label->setFixedHeight(16);

    addWidget(radioButton, 0);
    addWidget(label, 0);
    addWidget(removeButton, 0);

    radioButton->setVisible(false);
    removeButton->setVisible(false);

    connect(radioButton, &QRadioButton::clicked, this, &RemovableLabel::radioShim);
    connect(removeButton, &QAbstractButton::clicked, this, &RemovableLabel::removeShim);
}

RemovableLabel::~RemovableLabel() {
    delete label;
    delete removeButton;
    delete radioButton;
}

void RemovableLabel::enableRemove() {
    removeButton->setVisible(true);
}

void RemovableLabel::enableRadio(QWidget *parent, bool checked) {
    radioButton->setParent(parent);
    radioButton->setVisible(true);

    if (checked) {
        radioButton->setChecked(true);
    }
}

void RemovableLabel::removeShim() {
    emit remove(index);
}

void RemovableLabel::radioShim() {
    emit radio(index);
}

void RemovableLabel::setChecked(bool checked) {
    radioButton->setChecked(checked);
}

