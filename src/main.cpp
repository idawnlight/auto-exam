/**
 * @project Automatic Examination
 * @file main.cpp
 * @location src
 * @brief Main function
 * @date 2022/8/12
 */

#include "ui/window/EntryWidget.h"
#include "ui/window/EditWindow.h"
#include "ui/window/ExamWindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    EntryWidget entry;
    EditWindow editWindow;
    ExamWindow examWindow;

    QObject::connect(&entry, &EntryWidget::editPaper, &editWindow, &EditWindow::show);
    QObject::connect(&entry, &EntryWidget::startExam, &examWindow, &ExamWindow::show);

    entry.show();
    return a.exec();
}
