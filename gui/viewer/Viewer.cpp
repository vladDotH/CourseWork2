#include "Viewer.h"

Viewer::Viewer(QWidget *parent) : QWidget(parent) {
    lt = new QVBoxLayout(this);
    scrollArea = new QScrollArea(this);
    imageLabel = new ImageLabel(scrollArea);
    lt->addWidget(scrollArea);
    setLayout(lt);

    imageLabel->setBackgroundRole(QPalette::Base);
    scrollArea->setBackgroundRole(QPalette::Dark);
    scrollArea->setWidget(imageLabel);
    scrollArea->setVisible(true);
    imageLabel->setText("Загрузите изображение");
    imageLabel->adjustSize();

    connect(imageLabel, &ImageLabel::mouseEvent, [this](QMouseEvent *ev) {
        emit mouseEvent(ev);
    });
}

void Viewer::setImage(QPixmap *qimg) {
    imageLabel->setPixmap(*qimg);
    imageLabel->adjustSize();
}


