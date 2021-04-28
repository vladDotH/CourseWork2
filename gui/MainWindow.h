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
#include <toolbar/ToolBar.h>
#include "viewer/Viewer.h"

class MainWindow : public QMainWindow {
Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    bool loadFile(const QString &fileName);

    bool saveFile(const QString &fileName);

private slots:

    void open();

    void saveAs();

private:
    QSplitter *central;
    QGridLayout *lt;
    Viewer *viewer;
    ToolBar *toolBar;
};

#endif //CW2_MAINWINDOW