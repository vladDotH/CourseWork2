#include "Viewer.h"

Viewer::Viewer(QWidget *parent) : QWidget(parent) {
    layout = new QVBoxLayout(this);
    scrollArea = new QScrollArea(this);
    imageLabel = new QLabel(scrollArea);
    layout->addWidget(scrollArea);
    setLayout(layout);

    imageLabel->setBackgroundRole(QPalette::Base);
    imageLabel->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    imageLabel->setScaledContents(true);

    scrollArea->setBackgroundRole(QPalette::Dark);
    scrollArea->setWidget(imageLabel);
    scrollArea->setVisible(true);
    imageLabel->setText("Browse an image");
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



