#include "ToolBar.h"

ToolBar::ToolBar(QWidget *parent) : QWidget(parent) {
    layout = new QVBoxLayout(this);
    csq = new CrossSquare(this);
    crc = new Circle(this);
    flt = new Filter(this);
    rot = new Rotator(this);
    scroller = new QScrollArea(this);
    layout->addWidget(scroller);
    setLayout(layout);
    scroller->setVisible(true);
    scroller->setWidget(csq);
}
