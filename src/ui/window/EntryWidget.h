/**
 * @project Automatic Examination
 * @file EntryWidget.h
 * @location src/ui/window
 * @brief EntryWidget for selection
 * @date 2022/8/12
 */

#ifndef CPP_TERM_PROJECT_ENTRYWIDGET_H
#define CPP_TERM_PROJECT_ENTRYWIDGET_H

#include <QtWidgets>

class EntryWidget : public QWidget
{
    Q_OBJECT

public:
    EntryWidget(QWidget *parent = nullptr);

signals:
    void editPaper();
    void startExam();
};


#endif //CPP_TERM_PROJECT_ENTRYWIDGET_H
