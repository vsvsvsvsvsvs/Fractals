#include "mandelbrotwidget.h"
#include <QMouseEvent>
#include <QPainter>
#include <complex>
#include <vector>
#include <iostream>

MandelbrotWidget::MandelbrotWidget(QWidget *parent) :
    QWidget(parent), minX(-2.0), maxX(1.0), minY(-1.5), maxY(1.5), maxIterations(200), zoomCount(0), maxZoom(6),
    selecting(false) {
    setMinimumSize(800, 800);
    generateMandelbrot();
}

void MandelbrotWidget::generateMandelbrot() {

    image = QImage(width(), height(), QImage::Format_RGB32);

    for (int px = 0; px < width(); ++px) {
        for (int py = 0; py < height(); ++py) {
            double x0 = minX + px * (maxX - minX) / width();
            double y0 = minY + py * (maxY - minY) / height();

            std::complex<double> c(x0, y0);
            std::complex<double> z(0, 0);

            int iteration = 0;

            while (abs(z) <= 2.0 && iteration < maxIterations) {
                z = z * z + c;
                iteration++;
            }

            long double color;

            if (iteration == maxIterations) {
                color = 0;
            } else {
                color = (long double) iteration / (long double) maxIterations;
            }

            image.setPixel(px, py,
                           qRgb(255.0 * 9.0 * color * color * color * (1 - color),
                                255.0 * 15.0 * (1 - color) * (1 - color) * color * color,
                                255.0 * 8.5 * (1 - color) * (1 - color) * (1 - color) * color));
        }
    }
    pos.push_back({minX, maxX, minY, maxY});
    update();
}

void MandelbrotWidget::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    painter.drawImage(0, 0, image);

    if (selecting) {
        painter.setPen(Qt::blue);
        painter.drawRect(QRect(startPoint, endPoint));
    }
}

void MandelbrotWidget::mousePressEvent(QMouseEvent *event) {
    if (zoomCount >= maxZoom)
        return;

    selecting = true;
    startPoint = event->pos();
    endPoint = startPoint;
}

void MandelbrotWidget::mouseMoveEvent(QMouseEvent *event) {
    if (selecting) {
        endPoint = event->pos();
        update();
    }
}

void MandelbrotWidget::mouseReleaseEvent(QMouseEvent *event) {
    if (!selecting || zoomCount >= maxZoom)
        return;

    endPoint = event->pos();
    selecting = false;

    QRect selection(startPoint, endPoint);
    selection = selection.normalized();

    double new_minX = minX + selection.left() * (maxX - minX) / width();
    double new_maxX = minX + selection.right() * (maxX - minX) / width();
    double new_minY = minY + selection.top() * (maxY - minY) / height();
    double new_maxY = minY + selection.bottom() * (maxY - minY) / height();

    minX = new_minX;
    maxX = new_maxX;
    minY = new_minY;
    maxY = new_maxY;

    zoomCount++;
    generateMandelbrot();
}

void MandelbrotWidget::resetView() {
    minX = -2.0;
    maxX = 1.0;
    minY = -1.5;
    maxY = 1.5;
    zoomCount = 0;
    pos.clear();
    generateMandelbrot();
}

void MandelbrotWidget::prevView() {
    if (zoomCount == 0) {
        return;
    }
    zoomCount--;
    pos.pop_back();
    minX = pos[pos.size() - 1][0];
    maxX = pos[pos.size() - 1][1];
    minY = pos[pos.size() - 1][2];
    maxY = pos[pos.size() - 1][3];
    pos.pop_back();
    generateMandelbrot();
}
