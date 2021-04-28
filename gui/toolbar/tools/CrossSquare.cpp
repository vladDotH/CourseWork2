#include "CrossSquare.h"

CrossSquare::CrossSquare(QWidget *parent, QWidget *buttonParent) :
        Tool("Квадрат с диагоналями", parent, buttonParent) {
    layout = new QVBoxLayout(this);
    color = new ColorSetting(this);
    fillColor = new ColorSetting(this);
    fill = new QRadioButton(this);
    wd = new QSlider(Qt::Horizontal, this);

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
