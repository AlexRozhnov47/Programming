#include "mainwindow.h"
#include "ui_mainwindow.h"
    #include <QFileDialog>
    #include <QImage>
    #include <QBuffer>
    #include <QImageWriter>
void MainWindow::loadImage()
{
 connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::loadImage);
 QStringList mimeTypeFilters({"image/png",  // will show "PNG image (*.png)"
                           "application/octet-stream" // will show "All files (*)"
});
QFileDialog dialog(this);
dialog.setMimeTypeFilters(mimeTypeFilters);
dialog.exec();
QImage image;
      QByteArray ba;
      QBuffer buffer(&ba);
      buffer.open(QIODevice::WriteOnly);
      image.save(&buffer, "PNG");
    image.convertTo(QImage::Format_ARGB32);
    //ui->label->setText("Image Loaded");
}

void MainWindow::saveImage()
{
   connect(ui->pushButton_2, &QPushButton::clicked, this, &MainWindow::saveImage);
   QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                   "/home",
                                                   tr("Images (*.png)"));
   QImage image;
           QByteArray ba;
           QBuffer buffer(&ba);
           buffer.open(QIODevice::WriteOnly);
           image.save(&buffer, "PNG");
}

void MainWindow::encodeMsg()
{   QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                    "/home",
                                                    tr("Images (*.png)"));
    connect(ui->pushButton_3, &QPushButton::clicked, this, &MainWindow::saveImage);
    for (int y = 0; y < image.height(); ++y) {
        QRgb *line = reinterpret_cast<QRgb*>(image.scanLine(y));
        for (int x = 0; x < image.width(); ++x) {
            QRgb &rgb = line[x];
            rgb = qRgba(qRed(rgb), qGreen(0), qBlue(rgb), qAlpha(rgb));

        }
    }
    QImage image(3, 3, QImage::Format_Indexed8);
    QRgb value;

    value = qRgb(122, 163, 39); // 0xff7aa327
    image.setColor(0, value);

    value = qRgb(237, 187, 51); // 0xffedba31
    image.setColor(1, value);

    value = qRgb(189, 149, 39); // 0xffbd9527
    image.setColor(2, value);

    image.setPixel(0, 1, 0);
    image.setPixel(1, 0, 0);
    image.setPixel(1, 1, 2);
    image.setPixel(2, 1, 1);
    QImageWriter writer;
       writer.setFormat("png");
       if (writer.supportsOption(QImageIOHandler::Description))
           qDebug() << "Png supports embedded text";
    ui->label->setText(QString("a message has added to the picture"));

}

void MainWindow::decodeMsg()
{
    connect(ui->pushButton_4, &QPushButton::clicked, this, &MainWindow::saveImage);
    ui->label->setText(QString("Присутствует сообщение длиной %1 байт").arg(size));
    QString::fromUtf8(const QByteArray& str)


}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

