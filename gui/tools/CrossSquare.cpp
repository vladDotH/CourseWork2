#include "CrossSquare.h"

CrossSquare::CrossSquare(QWidget *parent) : QWidget(parent) {
    layout = new QVBoxLayout(this);
    r = new QSlider(Qt::Horizontal, this);
    g = new QSlider(Qt::Horizontal, this);
    b = new QSlider(Qt::Horizontal, this);
    wd = new QSlider(Qt::Horizontal, this);
    fill = new QRadioButton(this);
    layout->addWidget(fill);
    layout->addWidget(r);
    layout->addWidget(g);
    layout->addWidget(b);
    layout->addWidget(wd);
    setLayout(layout);
}
