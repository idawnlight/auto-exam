/**
 * @project Automatic Examination
 * @file RemovableLineEdit.h
 * @location src/ui/widgets
 * @brief This message displayed in Doxygen Files index
 * @date 2022/8/18
 */

#ifndef AUTO_EXAM_REMOVABLELINEEDIT_H
#define AUTO_EXAM_REMOVABLELINEEDIT_H

#include <QtWidgets>

class RemovableLineEdit : public QHBoxLayout {
    Q_OBJECT

public:
    RemovableLineEdit(int index, QString content = "");
    ~RemovableLineEdit();
    QString getContent();
    bool isCheckBoxChecked();
    void enableRadio(QWidget * parent, bool checked = false);
    void enableCheckbox(QWidget * parent, bool checked = false);

signals:
    void remove(int index);
    void editingFinished();
    void radio(int index);
    void checked();

protected slots:
    void removeShim();
    void radioShim();

protected:
    QLineEdit * lineEdit;
    QPushButton * removeButton;
    QRadioButton * radioButton;
    QCheckBox * checkBox;
    int index;
};


#endif //AUTO_EXAM_REMOVABLELINEEDIT_H
