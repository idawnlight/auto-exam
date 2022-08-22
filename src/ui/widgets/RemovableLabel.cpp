/**
 * @project Automatic Examination
 * @file RemovableLabel.cpp
 * @location src/ui/widgets/problemViewer
 * @brief Removable Label
 * @date 2022/8/19
 */

#include "RemovableLabel.h"

RemovableLabel::RemovableLabel(int index, QString content)
        : QHBoxLayout(), index(index), label(new QLabel(content)), removeButton(new QPushButton("删除")),
          radioButton(new QRadioButton), checkBox(new QCheckBox)
{

    setAlignment(Qt::AlignLeft);

    label->setWordWrap(true);

    addWidget(radioButton, 0);
    addWidget(checkBox, 0);
    addWidget(label, 0);
    addWidget(removeButton, 0);

    radioButton->setVisible(false);
    checkBox->setVisible(false);
    removeButton->setVisible(false);

    connect(radioButton, &QRadioButton::clicked, this, &RemovableLabel::radioShim);
    connect(checkBox, &QRadioButton::clicked, this, &RemovableLabel::checked);
    connect(removeButton, &QAbstractButton::clicked, this, &RemovableLabel::removeShim);
}

RemovableLabel::~RemovableLabel()
{
    delete label;
    delete removeButton;
    delete radioButton;
    delete checkBox;
}

void RemovableLabel::enableRemove()
{
    removeButton->setVisible(true);
}

void RemovableLabel::enableRadio(QWidget *parent, bool checked)
{
    radioButton->setParent(parent);
    radioButton->setVisible(true);

    if (checked)
    {
        radioButton->setChecked(true);
    }
}

void RemovableLabel::removeShim()
{
    emit remove(index);
}

void RemovableLabel::radioShim()
{
    emit radio(index);
}

void RemovableLabel::setRadioChecked(bool checked)
{
    radioButton->setChecked(checked);
}

bool RemovableLabel::isRadioChecked()
{
    return radioButton->isChecked();
}

void RemovableLabel::disable()
{
    radioButton->setDisabled(true);
    checkBox->setDisabled(true);
}

void RemovableLabel::enableCheckbox(QWidget *parent, bool checked)
{
    checkBox->setParent(parent);
    checkBox->setVisible(true);

    if (checked)
    {
        checkBox->setChecked(true);
    }
}

bool RemovableLabel::isCheckBoxChecked()
{
    return checkBox->isChecked();
}

