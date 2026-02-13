#ifndef MANDELBROTWIDGET_H
#define MANDELBROTWIDGET_H

#include <QImage>
#include <QPoint>
#include <QWidget>
#include <vector>

class MandelbrotWidget : public QWidget {
    Q_OBJECT
public:
    explicit MandelbrotWidget(QWidget *parent = nullptr);

    void resetView();
    void prevView();

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

    std::vector<std::vector<double>> pos;
};

#endif
