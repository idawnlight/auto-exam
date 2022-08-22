/**
 * @project Automatic Examination
 * @file BaseProblemEditor.h
 * @location src/ui/widgets/problemViewer
 * @date 2022/8/18
 */

#ifndef AUTO_EXAM_BASEPROBLEMEDITOR_H
#define AUTO_EXAM_BASEPROBLEMEDITOR_H

#include <QtWidgets>

class BaseProblemEditor : public QWidget
{
    Q_OBJECT

public:
    explicit BaseProblemEditor(QWidget *parent = nullptr);

    virtual void refresh() = 0;

public slots:
    virtual void setScore() = 0;
    virtual void saveProblem() = 0;

protected:
    QVBoxLayout *layout;
    QPlainTextEdit *contentEdit;
    QHBoxLayout *buttonLayout;
    bool noSaving = false;
};


#endif //AUTO_EXAM_BASEPROBLEMEDITOR_H
