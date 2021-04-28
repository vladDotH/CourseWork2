#include "ImageLabel.h"

void ImageLabel::mousePressEvent(QMouseEvent *ev) {
    QLabel::mousePressEvent(ev);
    emit mouseEvent(ev);
}

void ImageLabel::mouseMoveEvent(QMouseEvent *ev) {
    QLabel::mouseMoveEvent(ev);
    emit mouseEvent(ev);
}

void ImageLabel::mouseReleaseEvent(QMouseEvent *ev) {
    QLabel::mouseReleaseEvent(ev);
    emit mouseEvent(ev);
}

ImageLabel::ImageLabel(QWidget *parent) : QLabel(parent) {}

