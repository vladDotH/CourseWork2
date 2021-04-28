#include "Filter.h"

Filter::Filter(QWidget *parent, QWidget *buttonParent) :
        Tool("Фильтр каналов", parent, buttonParent) {
    colorBox = new QGroupBox("Канал", this);
    r = new QRadioButton("Красный", colorBox);
    g = new QRadioButton("Зелёный", colorBox);
    b = new QRadioButton("Синий", colorBox);
    colorLt = new QVBoxLayout(colorBox);
    colorLt->addWidget(r);
    colorLt->addWidget(g);
    colorLt->addWidget(b);

    lt = new QVBoxLayout(this);
    val = new QSlider(Qt::Horizontal, this);
    lt->addWidget(colorBox);
    lt->addWidget(val);
    setLayout(lt);
}
