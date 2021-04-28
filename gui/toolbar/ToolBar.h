#ifndef CW2_TOOLBAR_H
#define CW2_TOOLBAR_H

#include <QtWidgets/QWidget>
#include <QScrollArea>
#include <QVBoxLayout>
#include <QMouseEvent>
#include <QGroupBox>
#include <QDebug>
#include <QVector>
#include "toolbar/tools/CrossSquare.h"
#include "toolbar/tools/Circle.h"
#include "toolbar/tools/Filter.h"
#include "toolbar/tools/Rotator.h"

class ToolBar : public QWidget {
Q_OBJECT
public:

    ToolBar(QWidget *parent = nullptr);

public slots:

    void mouseHandler(QMouseEvent *ev);

    void toolPicked(Tool* tool);

private:
    QVBoxLayout *lt;
    QGroupBox *toolsPick;
    QVBoxLayout *toolsPickLt;
    QWidget *toolSettings;
    QVBoxLayout *toolSettingsLt;
    CrossSquare *csq;
    Circle *crc;
    Filter *flt;
    Rotator *rot;
    QVector<Tool *> tools;
    Tool *currentTool = nullptr;
};

#endif //CW2_TOOLBAR_H
