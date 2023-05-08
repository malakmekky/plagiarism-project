#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QPixmap>
#include <QLabel>
#include <QDateTime>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    uh();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::uh()
{
    QString filename = "C:/Users/obadw/Desktop/image.jpg";
    QPixmap pixmap(filename);
    ui->Wallpaper->setPixmap(pixmap);
    QString file = "C:/Users/obadw/Desktop/Detector.jpg";
    QPixmap det(file);
    ui->Detector_2->setPixmap(file);
    ui->Detector_2->setPixmap(det.scaled(ui->Detector_2->size(), Qt::KeepAspectRatio));
    QDateTime currentDateTime = QDateTime::currentDateTime();
    QString formattedDate = currentDateTime.toString("dd/MM/yyyy");
    QString formattedTime = currentDateTime.toString(" hh:mm:ss ");
    ui->date->setText(formattedDate);
    ui->time->setText(formattedTime);
}

void MainWindow::processFile(const QString& filename)
{
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::warning(this, "Error", "Unable to open file");
        return;
    }

    QTextStream in(&file);
    QString fileContents = in.readAll();

    while (!in.atEnd())
    {
        QString line = in.readLine();
        // process each line of the file

    }

    ui->textEdit->setText(fileContents);

    file.close();
}


void MainWindow::on_openFile_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, "Open File", QDir::homePath(), "Text Files (*.txt)");
        if (!filename.isEmpty())
        {
            processFile(filename);
        }
}

void MainWindow::on_pushButton_clicked()
{
        ui->stackedWidget->hide();
}
