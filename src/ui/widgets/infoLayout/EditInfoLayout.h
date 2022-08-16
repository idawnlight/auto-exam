/**
 * @project Automatic Examination
 * @file EditInfoLayout.h
 * @location src/ui/widgets/infoLayout
 * @brief This message displayed in Doxygen Files index
 * @date 2022/8/15
 */

#ifndef AUTO_EXAM_EDITINFOLAYOUT_H
#define AUTO_EXAM_EDITINFOLAYOUT_H

#include "../AlignedInfoLayout.h"

class EditInfoLayout : public AlignedInfoLayout {
    Q_OBJECT

public:
    explicit EditInfoLayout(QWidget *parent = nullptr);
};


#endif //AUTO_EXAM_EDITINFOLAYOUT_H