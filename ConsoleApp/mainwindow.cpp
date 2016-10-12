#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    canObj = new NiCanDriver();
}

MainWindow::~MainWindow()
{
    delete canObj;
    delete ui;
}
