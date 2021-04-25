#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    QMenu *fileMenu = menuBar()->addMenu(tr("&File"));

    QAction *openAct = fileMenu->addAction(tr("&Open"), this, &MainWindow::open);
    openAct->setShortcut(QKeySequence::Open);

    QAction *saveAct = fileMenu->addAction(tr("&Save as"), this, &MainWindow::saveAs);
    saveAct->setShortcut(QKeySequence::SaveAs);

    QAction *exitAct = fileMenu->addAction(tr("E&xit"), this, &QWidget::close);
    exitAct->setShortcut(tr("Ctrl+Q"));

    central = new QSplitter(this);
    layout = new QGridLayout(central);
    viewer = new Viewer(central);
    toolBar = new ToolBar(central);

    layout->addWidget(viewer, 0, 0);
    layout->addWidget(toolBar, 0, 1);
    central->setLayout(layout);
    setCentralWidget(central);
    resize(QGuiApplication::primaryScreen()->availableSize() / 2);
}

bool MainWindow::loadFile(const QString &fileName) {
    QImageReader reader(fileName);
    reader.setAutoTransform(true);
    const QImage newImage = reader.read();
    if (newImage.isNull()) {
        QMessageBox::information(this, QGuiApplication::applicationDisplayName(),
                                 tr("Cannot load %1: %2")
                                         .arg(QDir::toNativeSeparators(fileName), reader.errorString()));
        return false;
    }
    viewer->setImage(newImage);

    setWindowFilePath(fileName);

    const QString message = tr("Opened \"%1\", %2x%3, Depth: %4")
            .arg(QDir::toNativeSeparators(fileName)).arg(newImage.width()).arg(newImage.height()).arg(newImage.depth());
    statusBar()->showMessage(message);
    return true;
}

bool MainWindow::saveFile(const QString &fileName) {
    QImageWriter writer(fileName);

    if (!writer.write(viewer->getImage())) {
        QMessageBox::information(this, QGuiApplication::applicationDisplayName(),
                                 tr("Cannot write %1: %2")
                                         .arg(QDir::toNativeSeparators(fileName)), writer.errorString());
        return false;
    }
    const QString message = tr("Wrote \"%1\"").arg(QDir::toNativeSeparators(fileName));
    statusBar()->showMessage(message);
    return true;
}

void MainWindow::open() {
    QString file = QFileDialog::getOpenFileName(this, tr("Open Image"), "/home",
                                                tr("Image Files (*.bmp *.BMP)"));
    if (!file.isEmpty())
        loadFile(file);
}

void MainWindow::saveAs() {
    QString file = QFileDialog::getSaveFileName(this, tr("Open Image"), "/home",
                                                tr("Image Files (*.bmp *.BMP)"));
    if (!file.isEmpty())
        saveFile(file);
}

