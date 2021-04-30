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
    val->setRange(0, 255);
    val->setSingleStep(2);
    lt->addWidget(colorBox);
    lt->addWidget(val);
    setLayout(lt);

    connect(r, &QRadioButton::clicked, [this](bool checked) {
        ch = Channel::R;
    });
    connect(g, &QRadioButton::clicked, [this](bool checked) {
        ch = Channel::G;
    });
    connect(b, &QRadioButton::clicked, [this](bool checked) {
        ch = Channel::B;
    });
    r->setChecked(true);
    ch = Channel::R;
}

void Filter::process(QMouseEvent *ev, BitMapQ *bm) {
    switch (ev->type()) {
        case QEvent::MouseButtonPress:
            bm->filter(ch, val->value());
            bm->updQImg();
            emit update(bm->getQImg());
            break;
    }
}
