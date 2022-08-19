/**
 * @project Automatic Examination
 * @file ExamWindow.h
 * @location src/ui/window
 * @brief Window for examination
 * @date 2022/8/12
 */

#ifndef CPP_TERM_PROJECT_EXAMWINDOW_H
#define CPP_TERM_PROJECT_EXAMWINDOW_H

#include <QtWidgets>

#include "models/Paper.h"
#include "../widgets/ProblemIndicatorWidget.h"
#include "../widgets/infoLayout/ExamInfoLayout.h"
#include "../widgets/ProblemViewer.h"
#include "../widgets/ProblemLabel.h"

class ExamWindow : public QWidget {
    Q_OBJECT

public:
    ExamWindow(QWidget *parent = nullptr);

public slots:
    void paperChangedShim();
    void evaluate();
    void show();

signals:
    void paperChanged(std::shared_ptr<Paper>);

protected:
    ExamInfoLayout * leftInfoLayout;
    QPushButton * submitButton;
    ProblemViewer * problemViewer;
    ProblemLabel * problemLabel;
    ProblemIndicatorWidget * problemIndicator;

    std::shared_ptr<Paper> paper;
};


#endif //CPP_TERM_PROJECT_EXAMWINDOW_H
