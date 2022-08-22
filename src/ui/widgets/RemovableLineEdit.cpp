/**
 * @project Automatic Examination
 * @file RemovableLineEdit.cpp
 * @location src/ui/widgets
 * @brief Removable Line Edit
 * @date 2022/8/18
 */

#include "RemovableLineEdit.h"

RemovableLineEdit::RemovableLineEdit(int index, QString content)
        : QHBoxLayout(), index(index), lineEdit(new QLineEdit(content)), removeButton(new QPushButton("删除")),
          radioButton(new QRadioButton), checkBox(new QCheckBox)
{
    addWidget(radioButton, 0);
    addWidget(checkBox, 0);
    addWidget(lineEdit, 0);
    addWidget(removeButton, 0);

    radioButton->setVisible(false);
    checkBox->setVisible(false);

    connect(radioButton, &QRadioButton::clicked, this, &RemovableLineEdit::radioShim);
    connect(checkBox, &QCheckBox::stateChanged, this, &RemovableLineEdit::checked);
    connect(lineEdit, &QLineEdit::editingFinished, this, &RemovableLineEdit::editingFinished);
    connect(removeButton, &QAbstractButton::clicked, this, &RemovableLineEdit::removeShim);
}

void RemovableLineEdit::removeShim()
{
    emit remove(index);
}

QString RemovableLineEdit::getContent()
{
    return lineEdit->text();
}

RemovableLineEdit::~RemovableLineEdit()
{
    delete lineEdit;
    delete removeButton;
    delete radioButton;
    delete checkBox;
}

void RemovableLineEdit::enableRadio(QWidget *parent, bool checked)
{
    radioButton->setParent(parent);
    radioButton->setVisible(true);

    if (checked)
    {
        radioButton->setChecked(true);
    }
}

void RemovableLineEdit::enableCheckbox(QWidget *parent, bool checked)
{
    checkBox->setParent(parent);
    checkBox->setVisible(true);

    if (checked)
    {
        checkBox->setChecked(true);
    }
}

void RemovableLineEdit::radioShim()
{
    emit radio(index);
}

bool RemovableLineEdit::isCheckBoxChecked()
{
    return checkBox->isChecked();
}
