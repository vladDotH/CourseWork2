#include "Rotator.h"

Rotator::Rotator(QWidget *parent, QWidget *buttonParent) :
        Tool("Поворот", parent, buttonParent) {
    lt = new QVBoxLayout(this);
    angles = new QGroupBox("Угол поворота (градусы)", this);
    anglesLt = new QVBoxLayout(angles);
    d90 = new QRadioButton("90", angles);
    d180 = new QRadioButton("180", angles);
    d270 = new QRadioButton("270", angles);
    anglesLt->addWidget(d90);
    anglesLt->addWidget(d180);
    anglesLt->addWidget(d270);
    angles->setLayout(anglesLt);
    lt->addWidget(angles);
    setLayout(lt);
}
