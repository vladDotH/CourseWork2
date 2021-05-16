#ifndef CW2_MAINWINDOW
#define CW2_MAINWINDOW

#include <QMainWindow>
#include <QMessageBox>
#include <QFileDialog>
#include <QMenu>
#include <QMenuBar>
#include <QStatusBar>
#include <QDir>
#include <QImageReader>
#include <QImageWriter>
#include <QLabel>
#include <QScrollArea>
#include <QGridLayout>
#include <QSplitter>
#include <QPainter>
#include <toolbar/ToolBar.h>
#include <qgraphics/BitMapQ.h>
#include "viewer/Viewer.h"
#include "BitMap.h"

using Graphics::BitMap;

class MainWindow : public QMainWindow {
Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    bool loadFile(const QString &fileName);

    bool saveFile(const QString &fileName);

private slots:

    void open();

    void saveAs();

    void info();

    void help();

signals:
    void paintEvent(QMouseEvent *ev, BitMapQ *bm);

private:
    QSplitter *central;
    QGridLayout *lt;
    Viewer *viewer;
    ToolBar *toolBar;
    BitMapQ img;
    QAction *infoAct;
};

#endif //CW2_MAINWINDOW