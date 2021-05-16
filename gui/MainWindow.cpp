#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    setWindowTitle("Рисовалка");
    QMenu *fileMenu = menuBar()->addMenu("Файл");
    fileMenu->addAction("Открыть", this, &MainWindow::open);
    saveAct = fileMenu->addAction("Сохранить как", this, &MainWindow::saveAs);
    infoAct = fileMenu->addAction("Информация", this, &MainWindow::info);
    infoAct->setVisible(false);
    saveAct->setVisible(false);
    menuBar()->addAction("Справка", this, &MainWindow::help);
    menuBar()->addAction("Выход", this, &QWidget::close);

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
        BitMapQ newBM(fileName);
        newBM.copy(img);
    } catch (std::exception &e) {
        QMessageBox::warning(this, "Ошибка чтения",
                             QString("Не удалось загрузить %1: %2")
                                     .arg(QDir::toNativeSeparators(fileName)).arg(e.what()), "OK");
        return false;
    }

    img.updQImg();
    QPixmap *qimg = img.getQImg();
    viewer->setImage(qimg);

    const QString message = QString("Загружено \"%1\", %2x%3")
            .arg(QDir::toNativeSeparators(fileName)).arg(qimg->width()).arg(qimg->height());
    statusBar()->showMessage(message);

    infoAct->setVisible(true);
    saveAct->setVisible(true);
    return true;
}

bool MainWindow::saveFile(const QString &fileName) {
    try {
        img.save(fileName.toStdString());
    } catch (std::exception &e) {
        QMessageBox::warning(this, "Ошибка записи",
                             QString("Не удалось записать %1: %2")
                                     .arg(QDir::toNativeSeparators(fileName)).arg(e.what()), "OK");
        return false;
    }

    const QString message = QString("Записано \"%1\"").arg(QDir::toNativeSeparators(fileName));
    statusBar()->showMessage(message);
    return true;
}

void MainWindow::open() {
    QString file = QFileDialog::getOpenFileName(this, "Открыть файл", "/home",
                                                "bmp Изображения (*.bmp *.BMP)");
    if (!file.isEmpty()) {
        loadFile(file);
    }
}

void MainWindow::saveAs() {
    QString file = QFileDialog::getSaveFileName(this, "Сохранить файл как", "/home",
                                                "bmp Изображения (*.bmp *.BMP)");
    if (!file.isEmpty())
        saveFile(file);
}

void MainWindow::info() {
    QMessageBox::information(
            this, "Информация о файле",
            QString("Файл: %1\n"
                    "Размер %2 (байт)\n"
                    "Высота %3, Ширинна %4\n"
                    "Глубина цвета %5\n"
                    "Размер BitMapINFO %6")
                    .arg(QString::fromStdString(img.getName()))
                    .arg(img.getFileSize())
                    .arg(img.getHeight()).arg(img.getWidth())
                    .arg(img.getDepth()).arg(img.getInfoSize()), "OK");
}

void MainWindow::help() {
    QString HELP = "Загрузка/Сохранение/Информация файла - в меню \"Файл\"\n\n\n"
                   "Выбор инструментов - правая панель\n\n"
                   "1) Квадрат с диагоналями - рисует квадрат с диагоналями определённого цвета, толщины и заливки\n\n"
                   "2) Фильтр каналов - выставляет все пиксели выбранного цвета в выбранную величину (для применения - щелчок по изображению)\n\n"
                   "3) Окружность - рисует окружность с диагоналями определённого цвета, толщины и заливки. "
                   "С зажатым 'Shift' - вписывает окружность в выбранную квадратную область\n\n"
                   "4) Поворот - поворачивает часть изображения на выбранный угол (по часовой стрелке)";

    QMessageBox::information(this, "Справка", HELP, "OK");
}

