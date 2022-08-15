/**
 * @project Automatic Examination
 * @file AlignedInfoLayout.cpp
 * @location src/ui/widgets
 * @brief This message displayed in Doxygen Files index
 * @date 2022/8/15
 */

#include "AlignedInfoLayout.h"

AlignedInfoLayout::AlignedInfoLayout(QWidget *parent) : QGridLayout(parent) {
    setSizeConstraint(QLayout::SetMinAndMaxSize);
}

void AlignedInfoLayout::addInfo(QString key, QString value) {
    if (key == " ") {
        labels.append(QPair<QLabel *, QLabel *>(new QLabel(" "), new QLabel(" ")));
    } else {
        kv.append(QPair<QString, QString>(key, value));
        labels.append(QPair<QLabel *, QLabel *>(new QLabel(key + " :"), new QLabel(value)));
    }
    addWidget(labels.last().first, labels.size() - 1, 0, 1, 1);
    addWidget(labels.last().second, labels.size() - 1, 1, 1, 2);
}

void AlignedInfoLayout::updateInfo(QString key, QString value) {
    for (int i = 0; i < kv.size(); i++) {
        if (kv[i].first == key) {
            kv[i].second = value;
            labels[i].second->setText(value);
            return;
        }
    }
}
