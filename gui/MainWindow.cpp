#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    QMenu *fileMenu = menuBar()->addMenu(tr("Файл"));
    fileMenu->addAction(tr("Открыть"), this, &MainWindow::open);
    fileMenu->addAction(tr("Сохранить как"), this, &MainWindow::saveAs);
    fileMenu->addAction(tr("Выход"), this, &QWidget::close);

    central = new QSplitter(this);
    lt = new QGridLayout(central);
    viewer = new Viewer(central);
    toolBar = new ToolBar(central);

    lt->addWidget(viewer, 0, 0);
    lt->addWidget(toolBar, 0, 1);
    central->setLayout(lt);
    setCentralWidget(central);
    resize(QGuiApplication::primaryScreen()->availableSize() / 2);

    connect(viewer, &Viewer::mouseEvent, [this](QMouseEvent *ev) {
        emit paintEvent(ev, &img);
    });
    connect(this, &MainWindow::paintEvent, toolBar, &ToolBar::paintHandler);
    connect(toolBar, &ToolBar::update, viewer, &Viewer::setImage);
}

bool MainWindow::loadFile(const QString &fileName) {
    try {
        img.read(fileName.toStdString());
    } catch (std::exception &e) {
        QMessageBox::information(this, QGuiApplication::applicationDisplayName(),
                                 tr("Не удалось загрузить %1: %2")
                                         .arg(QDir::toNativeSeparators(fileName).arg(e.what())), "OK");
        return false;
    }

    img.updQImg();
    QPixmap *qimg = img.getQImg();
    viewer->setImage(qimg);

    setWindowFilePath(fileName);

    const QString message = tr("Загружено \"%1\", %2x%3")
            .arg(QDir::toNativeSeparators(fileName)).arg(qimg->width()).arg(qimg->height());
    statusBar()->showMessage(message);
    return true;
}

bool MainWindow::saveFile(const QString &fileName) {
    try {
        img.save(fileName.toStdString());
    } catch (std::exception &e) {
        QMessageBox::information(this, QGuiApplication::applicationDisplayName(),
                                 tr("Не удалось записать %1: %2")
                                         .arg(QDir::toNativeSeparators(fileName)).arg(e.what()), "OK");
        return false;
    }

    const QString message = tr("Записано \"%1\"").arg(QDir::toNativeSeparators(fileName));
    statusBar()->showMessage(message);
    return true;
}

void MainWindow::open() {
    QString file = QFileDialog::getOpenFileName(this, tr("Открыть файл"), "/home",
                                                tr("bmp Изображения (*.bmp *.BMP)"));
    if (!file.isEmpty())
        loadFile(file);
}

void MainWindow::saveAs() {
    QString file = QFileDialog::getSaveFileName(this, tr("Сохранить файл как"), "/home",
                                                tr("bmp Изображения (*.bmp *.BMP)"));
    if (!file.isEmpty())
        saveFile(file);
}

