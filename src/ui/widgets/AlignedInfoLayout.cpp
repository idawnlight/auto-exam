/**
 * @project Automatic Examination
 * @file AlignedInfoLayout.cpp
 * @location src/ui/widgets
 * @brief Aligned Info Layout based on QGridLayout
 * @date 2022/8/15
 */

#include "AlignedInfoLayout.h"

AlignedInfoLayout::AlignedInfoLayout(QWidget *parent) : QGridLayout(parent)
{
    setSizeConstraint(QLayout::SetMinAndMaxSize);
}

void AlignedInfoLayout::addInfo(QString key, QString value)
{
    auto keyLabel = new QLabel(key + " :");
    keyLabel->setProperty("key", key);
    if (key == " ")
    {
        keyLabel->setText(" ");
    }
    labels.append(QPair<QLabel *, QLabel *>(keyLabel, new QLabel(value)));
    addWidget(labels.last().first, labels.size() - 1, 0, 1, 1);
    addWidget(labels.last().second, labels.size() - 1, 1, 1, 2);
}

void AlignedInfoLayout::updateInfo(QString key, QString value)
{
    for (int i = 0; i < labels.size(); i++)
    {
        auto x = labels[i].first->text();
        if (labels[i].first->property("key") == key)
        {
            labels[i].second->setText(value);
            return;
        }
    }
}
