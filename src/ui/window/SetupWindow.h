/**
 * @project Automatic Examination
 * @file SetupWindow.h
 * @location src/ui/window
 * @brief Window for setup paper
 * @date 2022/8/12
 */

#ifndef CPP_TERM_PROJECT_SETUPWINDOW_H
#define CPP_TERM_PROJECT_SETUPWINDOW_H

#include <QtWidgets>

#include "models/Paper.h"
#include "../widgets/ProblemIndicatorWidget.h"

class SetupWindow : public QWidget {
    Q_OBJECT

public:
    SetupWindow(QWidget *parent = nullptr);

public slots:
    void show();
};


#endif //CPP_TERM_PROJECT_SETUPWINDOW_H
