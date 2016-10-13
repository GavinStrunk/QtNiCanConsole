#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "nicandriver.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_refreshButton_clicked();
    void on_openButton_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    NiCanDriver *canObj;
    bool isOpen;

    void RefreshInterfaces(void);
};

#endif // MAINWINDOW_H
