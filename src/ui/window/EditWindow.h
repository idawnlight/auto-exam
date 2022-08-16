/**
 * @project Automatic Examination
 * @file EditWindow.h
 * @location src/ui/window
 * @brief Window for setup paper
 * @date 2022/8/12
 */

#ifndef CPP_TERM_PROJECT_SETUPWINDOW_H
#define CPP_TERM_PROJECT_SETUPWINDOW_H

#include <QtWidgets>

#include "models/Paper.h"
#include "../widgets/ProblemIndicatorWidget.h"
#include "../widgets/infoLayout/EditInfoLayout.h"
#include "../widgets/ProblemEditor.h"

class EditWindow : public QWidget {
    Q_OBJECT

protected:
    EditInfoLayout * leftInfoLayout;
    ProblemEditor * problemEditor;
    std::shared_ptr<Paper> paper;

public:
    EditWindow(QWidget *parent = nullptr);

public slots:
    void show();
};


#endif //CPP_TERM_PROJECT_SETUPWINDOW_H
