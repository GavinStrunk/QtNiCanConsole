#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    isOpen = false;

    this->RefreshInterfaces();

    canObj = new NiCanDriver();
}

MainWindow::~MainWindow()
{
    delete canObj;
    delete ui;
}

void MainWindow::RefreshInterfaces()
{
    ui->canBox->clear();
    QStringList interfaces = NiCanDriver::GetListOfInterfaces();

    foreach(const QString &n, interfaces)
    {
        ui->canBox->addItem(n);
    }
}

void MainWindow::on_refreshButton_clicked()
{
    this->RefreshInterfaces();
}

void MainWindow::on_openButton_clicked()
{
    if(isOpen)
    {
        canObj->Close();
        ui->openButton->setText(QString("Open"));
        isOpen = false;
    }
    else
    {
        canObj->Open(ui->canBox->currentText());
        ui->openButton->setText(QString("Close"));
        isOpen = true;
    }
}

void MainWindow::on_pushButton_clicked()
{
    canObj->Write();
}
