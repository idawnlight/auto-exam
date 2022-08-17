/**
 * @project Automatic Examination
 * @file NavigatorWidget.h
 * @location src/ui/widgets
 * @brief This message displayed in Doxygen Files index
 * @date 2022/8/17
 */

#ifndef AUTO_EXAM_NAVIGATORWIDGET_H
#define AUTO_EXAM_NAVIGATORWIDGET_H

#include <QtWidgets>

enum class NavigatorStatus {
    None,
    Middle,
    First,
    Last
};

class NavigatorWidget : public QWidget {
    Q_OBJECT

public:
    explicit NavigatorWidget(QWidget *parent = nullptr);

    void setStatus(NavigatorStatus status);

protected:
    QPushButton * previousButton;
    QPushButton * nextButton;

signals:
    void previous();
    void next();
};


#endif //AUTO_EXAM_NAVIGATORWIDGET_H
