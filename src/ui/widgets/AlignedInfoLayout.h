/**
 * @project Automatic Examination
 * @file AlignedInfoLayout.h
 * @location src/ui/widgets
 * @brief Aligned Info Layout based on QGridLayout
 * @date 2022/8/15
 */

#ifndef AUTO_EXAM_ALIGNEDINFOLAYOUT_H
#define AUTO_EXAM_ALIGNEDINFOLAYOUT_H

#include <QtWidgets>

class AlignedInfoLayout : public QGridLayout
{
    Q_OBJECT

protected:
    QList <QPair<QLabel *, QLabel *>> labels;

public:
    AlignedInfoLayout(QWidget *parent = nullptr);

    // Note that repeated key can be added, but will cause problem (unable to update)
    void addInfo(QString key, QString value);
    void updateInfo(QString key, QString value);
};


#endif //AUTO_EXAM_ALIGNEDINFOLAYOUT_H
