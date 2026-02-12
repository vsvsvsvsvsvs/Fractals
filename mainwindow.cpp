#include "mainwindow.h"
#include "mandelbrotwidget.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QWidget *central = new QWidget(this);
    setCentralWidget(central);

    QVBoxLayout *layout = new QVBoxLayout(central);

    mandelbrotWidget = new MandelbrotWidget(this);
    QPushButton *resetButton = new QPushButton("Сброс приближения");

    layout->addWidget(mandelbrotWidget);
    layout->addWidget(resetButton);

    connect(resetButton, &QPushButton::clicked,
            mandelbrotWidget, &MandelbrotWidget::resetView);
}
