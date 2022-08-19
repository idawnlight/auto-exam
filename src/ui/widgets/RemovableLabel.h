/**
 * @project Automatic Examination
 * @file RemovableLabel.h
 * @location src/ui/widgets/problemEditor
 * @brief This message displayed in Doxygen Files index
 * @date 2022/8/19
 */

#ifndef AUTO_EXAM_REMOVABLELABEL_H
#define AUTO_EXAM_REMOVABLELABEL_H

#include <QtWidgets>

class RemovableLabel : public QHBoxLayout {
    Q_OBJECT

public:
    RemovableLabel(int index, QString content = "");
    ~RemovableLabel();
    void enableRemove();
    void enableRadio(QWidget * parent, bool checked = false);
    void setChecked(bool checked);

signals:
    void remove(int index);
    void radio(int index);

protected slots:
    void removeShim();
    void radioShim();

protected:
    QLabel * label;
    QPushButton * removeButton;
    QRadioButton * radioButton;
    int index;
};


#endif //AUTO_EXAM_REMOVABLELABEL_H
