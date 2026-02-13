#include "mainwindow.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>
#include "mandelbrotwidget.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    QWidget *central = new QWidget(this);
    setCentralWidget(central);

    QVBoxLayout *layout = new QVBoxLayout(central);

    mandelbrotWidget = new MandelbrotWidget(this);
    QPushButton *resetButton = new QPushButton("Сброс приближения");
    QPushButton *prevButton = new QPushButton("Предыдущий шаг");

    layout->addWidget(resetButton);
    layout->addWidget(mandelbrotWidget);
    layout->addWidget(prevButton);

    connect(resetButton, &QPushButton::clicked, mandelbrotWidget, &MandelbrotWidget::resetView);
    connect(prevButton, &QPushButton::clicked, mandelbrotWidget, &MandelbrotWidget::resetView);
}
