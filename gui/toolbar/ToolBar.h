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
#include "qgraphics/BitMapQ.h"

class ToolBar : public QWidget {
Q_OBJECT
public:

    ToolBar(QWidget *parent = nullptr);

public slots:

    void paintHandler(QMouseEvent *ev, BitMapQ *bm);

    void toolPicked(Tool *tool);

signals:
    void update(QPixmap *qimg);

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
