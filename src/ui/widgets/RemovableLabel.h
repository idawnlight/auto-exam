/**
 * @project Automatic Examination
 * @file RemovableLabel.h
 * @location src/ui/widgets/problemViewer
 * @brief Removable Label
 * @date 2022/8/19
 */

#ifndef AUTO_EXAM_REMOVABLELABEL_H
#define AUTO_EXAM_REMOVABLELABEL_H

#include <QtWidgets>

class RemovableLabel : public QHBoxLayout
{
    Q_OBJECT

public:
    RemovableLabel(int index, QString content = "");
    ~RemovableLabel();

    void enableRemove();
    void enableRadio(QWidget *parent, bool checked = false);
    void setRadioChecked(bool checked);
    bool isRadioChecked();
    void enableCheckbox(QWidget *parent, bool checked = false);
    bool isCheckBoxChecked();
    void disable();

signals:
    void remove(int index);
    void radio(int index);
    void checked();

protected slots:
    void removeShim();
    void radioShim();

protected:
    QLabel *label;
    QPushButton *removeButton;
    QRadioButton *radioButton;
    QCheckBox *checkBox;
    int index;
};


#endif //AUTO_EXAM_REMOVABLELABEL_H
