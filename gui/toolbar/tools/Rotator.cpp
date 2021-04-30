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

    connect(d90, &QRadioButton::clicked, [this](bool checked) {
        angle = RotateAngle::D90;
    });
    connect(d180, &QRadioButton::clicked, [this](bool checked) {
        angle = RotateAngle::D180;
    });
    connect(d90, &QRadioButton::clicked, [this](bool checked) {
        angle = RotateAngle::D270;
    });
    d90->setChecked(true);
    angle = D90;
}

void Rotator::process(QMouseEvent *ev, BitMapQ *bm) {
    switch (ev->type()) {
        case QEvent::MouseButtonPress:
            p1 = ev->pos();
            break;
        case QEvent::MouseMove: {
            p2 = ev->pos();
            QPixmap buffer(*bm->getQImg());
            QPainter painter(&buffer);
            painter.setPen(QPen(Qt::black, 3, Qt::DashDotLine, Qt::RoundCap, Qt::RoundJoin));
            painter.drawRect(QRect(p1, p2));
            emit update(&buffer);
            break;
        }
        case QEvent::MouseButtonRelease:
            bm->rotate(p1, p2, angle);
            bm->updQImg();
            emit update(bm->getQImg());
            break;
    }
}
