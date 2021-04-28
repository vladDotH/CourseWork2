#include "Viewer.h"

Viewer::Viewer(QWidget *parent) : QWidget(parent) {
    lt = new QVBoxLayout(this);
    scrollArea = new QScrollArea(this);
    imageLabel = new ImageLabel(scrollArea);
    lt->addWidget(scrollArea);
    setLayout(lt);

    imageLabel->setBackgroundRole(QPalette::Base);
    imageLabel->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    imageLabel->setScaledContents(true);

    scrollArea->setBackgroundRole(QPalette::Dark);
    scrollArea->setWidget(imageLabel);
    scrollArea->setVisible(true);
    imageLabel->setText("Загрузите изображение");
    imageLabel->adjustSize();
}

void Viewer::setImage(const QImage &newImage) {
    image = newImage;
    imageLabel->setPixmap(QPixmap::fromImage(image));
    imageLabel->adjustSize();
}

const QImage &Viewer::getImage() const {
    return image;
}

ImageLabel *Viewer::getImageLabel() const {
    return imageLabel;
}


