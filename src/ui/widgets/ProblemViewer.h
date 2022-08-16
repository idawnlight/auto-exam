/**
 * @project Automatic Examination
 * @file ProblemViewer.h
 * @location src/ui/widgets
 * @brief This message displayed in Doxygen Files index
 * @date 2022/8/15
 */

#ifndef AUTO_EXAM_PROBLEMVIEWER_H
#define AUTO_EXAM_PROBLEMVIEWER_H

#include <QtWidgets>

class ProblemViewer : public QWidget {
    Q_OBJECT

protected:
    int currentIndex;
};


#endif //AUTO_EXAM_PROBLEMVIEWER_H
