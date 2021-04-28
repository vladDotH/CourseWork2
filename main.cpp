#include <QApplication>
#include <QGridLayout>
#include <gui/MainWindow.h>
#include "gui/viewer/Viewer.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    MainWindow mw;
    mw.show();
    return app.exec();
}