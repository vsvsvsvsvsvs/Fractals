#ifndef MANDELBROTWIDGET_H
#define MANDELBROTWIDGET_H

#include <QWidget>
#include <QImage>
#include <QPoint>

class MandelbrotWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MandelbrotWidget(QWidget *parent = nullptr);

    void resetView();

protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

private:
    void generateMandelbrot();

    QImage image;

    double minX, maxX;
    double minY, maxY;

    int maxIterations;
    int zoomCount;
    int maxZoom;

    QPoint startPoint;
    QPoint endPoint;
    bool selecting;
};

#endif
