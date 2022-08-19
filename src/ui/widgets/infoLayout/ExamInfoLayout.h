/**
 * @project Automatic Examination
 * @file ExamInfoLayout.h
 * @location src/ui/widgets/infoLayout
 * @brief This message displayed in Doxygen Files index
 * @date 2022/8/16
 */

#ifndef AUTO_EXAM_EXAMINFOLAYOUT_H
#define AUTO_EXAM_EXAMINFOLAYOUT_H

#include "../AlignedInfoLayout.h"
#include "models/Paper.h"

class ExamInfoLayout : public AlignedInfoLayout {
    Q_OBJECT

public:
    explicit ExamInfoLayout(QWidget *parent = nullptr);

    void setScore(double score);

public slots:
    void updateExamInfo(std::shared_ptr<Paper> p);
};


#endif //AUTO_EXAM_EXAMINFOLAYOUT_H
