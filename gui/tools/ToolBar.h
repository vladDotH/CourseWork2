#ifndef CW2_TOOLBAR_H
#define CW2_TOOLBAR_H

#include <QtWidgets/QWidget>
#include <QScrollArea>
#include <QVBoxLayout>
#include "CrossSquare.h"
#include "Circle.h"
#include "Filter.h"
#include "Rotator.h"

class ToolBar : public QWidget {
private:
    CrossSquare *csq;
    Circle *crc;
    Filter *flt;
    Rotator *rot;
    QScrollArea *scroller;
    QVBoxLayout *layout;

public:
    ToolBar(QWidget *parent = nullptr);
};


#endif //CW2_TOOLBAR_H
