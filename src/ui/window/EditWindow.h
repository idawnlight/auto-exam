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
#include "../widgets/ProblemLabel.h"

class EditWindow : public QWidget
{
    Q_OBJECT

public slots:
    void paperChangedShim();
    void exportPaper();
    void importPaper();

signals:
    void paperChanged(std::shared_ptr<Paper>);

public:
    EditWindow(QWidget *parent = nullptr);

protected:
    EditInfoLayout *leftInfoLayout;
    ProblemEditor *problemEditor;
    ProblemLabel *problemLabel;
    ProblemIndicatorWidget *problemIndicator;

    std::shared_ptr<Paper> paper;

};


#endif //CPP_TERM_PROJECT_SETUPWINDOW_H
