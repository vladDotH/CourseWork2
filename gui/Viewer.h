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

class Viewer : public QWidget {
Q_OBJECT
private:
    QImage image;
    QLabel *imageLabel;
    QScrollArea *scrollArea;
    QVBoxLayout *layout;

public:
    Viewer(QWidget *parent = nullptr);

public slots:

    void setImage(const QImage &newImage);

    const QImage &getImage() const;
};

#endif //CW2_VIEWER_H