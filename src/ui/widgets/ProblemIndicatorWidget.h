/**
 * @project Automatic Examination
 * @file ProblemIndicatorWidget.h
 * @location src/ui/widgets
 * @brief Widget for problems indicator
 * @date 2022/8/12
 */

#ifndef AUTO_EXAM_PROBLEMINDICATORWIDGET_H
#define AUTO_EXAM_PROBLEMINDICATORWIDGET_H

#include <QtWidgets>

#include "models/AnswerPaper.h"
#include "NavigatorWidget.h"

class ProblemIndicatorWidget : public QScrollArea {
    Q_OBJECT
public:
    ProblemIndicatorWidget(std::shared_ptr<Paper>, bool isEditing = false);
    ProblemIndicatorWidget(std::shared_ptr<AnswerPaper>, bool isEditing = false);

    void setAnswerPaper(std::shared_ptr<AnswerPaper>);

    void touchPaper();
    double evaluate();

public slots:
    void problemClicked(QAbstractButton *button);
    void addProblem();
    void navigateProblem(int index);
    void removeProblem(int index);
    void setAnswer(int index, json answer);

signals:
    void selectionChanged(std::shared_ptr<BaseProblem>, int index, NavigatorStatus status, json answer = json::array());
    void paperChanged(std::shared_ptr<Paper>);

protected:
    bool isEditing = false;
    const QSize btnSize = QSize(64, 50);
    QGridLayout* layout;
    QButtonGroup* buttonGroup;
    QList<QPushButton *> buttons;
    std::shared_ptr<AnswerPaper> answerPaper;

    void appendButton(QAbstractButton *button);

    const QString buttonStyleDefault = "QPushButton {\n"
                                       "    border: 2px solid #b6b6b6;\n"
                                       "}\n"
                                       "QPushButton:hover {\n"
                                       "    background-color: #ffffff;\n"
                                       "}\n"
                                       "QPushButton:pressed, QPushButton:checked {\n"
                                       "    border: 2px solid #2d2d2d;\n"
                                       "}";
    const QString buttonStyleWrong = "QPushButton {\n"
                                     "    border: 2px solid red;\n"
                                     "}\n";
    const QString buttonStyleRight = "QPushButton {\n"
                                     "    border: 2px solid green;\n"
                                     "}\n";
    const QString buttonStylePartRight = "QPushButton {\n"
                                         "    border: 2px solid orange;\n"
                                         "}\n";
    const QString buttonStyleFocus = "QPushButton {\n"
                                     "    border: 2px solid #2d2d2d;\n"
                                     "}\n";
};


#endif //AUTO_EXAM_PROBLEMINDICATORWIDGET_H
