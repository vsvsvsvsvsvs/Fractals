#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class MandelbrotWidget;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

private:
    MandelbrotWidget *mandelbrotWidget;
};

#endif
