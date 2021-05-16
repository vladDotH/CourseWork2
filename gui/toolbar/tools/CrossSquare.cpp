#include <sys/param.h>
#include "CrossSquare.h"

CrossSquare::CrossSquare(QWidget *parent, QWidget *buttonParent) :
        Tool("Квадрат с диагоналями", parent, buttonParent) {
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

void CrossSquare::process(QMouseEvent *ev, BitMapQ *bm) {
    if (ev->type() == QEvent::MouseButtonPress) {
        p1 = ev->pos();
    }
    if (ev->type() == QEvent::MouseMove || ev->type() == QEvent::MouseButtonRelease) {
        p2 = ev->pos();
        QPixmap buffer(*bm->getQImg());
        QPainter painter(&buffer);
        painter.setCompositionMode(QPainter::RasterOp_SourceAndNotDestination);
        painter.setPen(QPen(Qt::white, 3, Qt::DashDotLine));
        Vec2DQ v(p2 - p1);
        v = Vec2DQ(v.sgn() * MAX(abs(v.x), abs(v.y)));
        p2 = p1 + v.point();
        painter.drawRect(QRect(p1, p2));
        emit update(&buffer);
    }
    if (ev->type() == QEvent::MouseButtonRelease) {
        bm->drawCrossRect(p1, p2, color->getColor(), wd->value(), fill->isChecked(), fillColor->getColor());
        bm->updQImg();
        emit update(bm->getQImg());
    }
}
