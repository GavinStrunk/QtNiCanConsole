#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    NCTYPE_UINT32 serialNumber;
    NCTYPE_STATUS retval = ncGetHardwareInfo(1, 1, NC_ATTR_HW_SERIAL_NUM, \
                                             4, (NCTYPE_ANY_P)&serialNumber);

    qDebug() << "Serial Number" << QString::number(serialNumber, 16);
    qDebug() << "Return value = " << retval;
}

MainWindow::~MainWindow()
{
    delete ui;
}
