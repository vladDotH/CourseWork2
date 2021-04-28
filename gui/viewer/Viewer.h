#ifndef CW2_VIEWER_H
#define CW2_VIEWER_H

#include <QMainWindow>
#include <QImage>
#include <QLabel>
#include <QScrollArea>
#include <QApplication>
#include <QClipboard>
#include <QDir>
#include <QFileDialog>
#include <QImageReader>
#include <QImageWriter>
#include <QLabel>
#include <QMenuBar>
#include <QMessageBox>
#include <QMimeData>
#include <QPainter>
#include <QScreen>
#include <QScrollArea>
#include <QScrollBar>
#include <QStandardPaths>
#include <QStatusBar>
#include <QVBoxLayout>
#include <QMouseEvent>
#include <QDebug>
#include "ImageLabel.h"

class Viewer : public QWidget {
Q_OBJECT
public:

    Viewer(QWidget *parent = nullptr);
    ImageLabel *getImageLabel() const;

public slots:

    void setImage(const QImage &newImage);

    const QImage &getImage() const;

private:
    QImage image;
    ImageLabel *imageLabel;
    QScrollArea *scrollArea;
    QVBoxLayout *lt;
};

#endif //CW2_VIEWER_H