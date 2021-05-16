#include <sys/param.h>
#include "Circle.h"

Circle::Circle(QWidget *parent, QWidget *buttonParent) :
        Tool("Окружность", parent, buttonParent) {
    layout = new QVBoxLayout(this);
    color = new ColorSetting(this);
    fillColor = new ColorSetting(this);
    fill = new QRadioButton(this);
    wd = new QSlider(Qt::Horizontal, this);
    wd->setRange(1, 100);

    QLabel *colorLabel = new QLabel("Цвет", this),
            *wdLabel = new QLabel("Толщина", this),
            *fillLabel = new QLabel("Заливка", this),
            *fillColorLabel = new QLabel("Цвет Заливки", this);

    layout->addWidget(colorLabel);
    layout->addWidget(color);
    layout->addWidget(wdLabel);
    layout->addWidget(wd);
    layout->addWidget(fillLabel);
    layout->addWidget(fill);
    layout->addWidget(fillColorLabel);
    layout->addWidget(fillColor);

    fillColorLabel->setVisible(false);
    fillColor->setVisible(false);
    connect(fill, &QRadioButton::clicked, [this, fillColorLabel](bool checked) {
        fillColorLabel->setVisible(checked);
        fillColor->setVisible(checked);
        this->adjustSize();
    });

    setLayout(layout);
}

void Circle::process(QMouseEvent *ev, BitMapQ *bm) {
    switch (ev->type()) {
        case QEvent::MouseButtonPress:
            p1 = ev->pos();
            break;
        case QEvent::MouseMove: {
            p2 = ev->pos();
            QPixmap buffer(*bm->getQImg());
            QPainter painter(&buffer);
            painter.setPen(QPen(Qt::black, 3, Qt::DashDotLine, Qt::RoundCap, Qt::RoundJoin));
            QPoint d = (p1 - ev->pos());
            if (QApplication::keyboardModifiers() == Qt::ShiftModifier) {
                Vec2DQ v(p2 - p1);
                v = Vec2DQ(v.sgn() * MAX(abs(v.x), abs(v.y)));
                p2 = p1 + v.point();
                c = (p2 + p1) / 2;
                R = abs(p2.x() - p1.x()) / 2;
                painter.drawRect(QRect(p1, p2));
                painter.drawEllipse(c, R, R);
            } else {
                R = QVector2D(d).length();
                c = p1;
                painter.drawEllipse(p1, R, R);
            }
            emit update(&buffer);
            break;
        }
        case QEvent::MouseButtonRelease:
            bm->drawCircle(c, R, color->getColor(), wd->value(), fill->isChecked(), fillColor->getColor());
            bm->updQImg();
            emit update(bm->getQImg());
            break;
        default:
            break;
    }
}
