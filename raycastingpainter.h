#ifndef RAYCASTINGPAINTER_H
#define RAYCASTINGPAINTER_H

#include "scene.h"

#include <QWidget>
#include <QPointF>
#include <QtMath>

#define PI (acos(-1.))

class RaycastingPainter
{
public:
    RaycastingPainter();

    void paint(QWidget *widget, QPointF position, QPointF direction);

    Scene *scene() const;
    void setScene(Scene *scene);
    void castRays(QPointF position, QPointF direction, double width);

    double getFov() const;
    void setFov(double value);

    double getWidth() const;
    void setWidth(double value);

    QImage getBuffer() const;
    void setBuffer(const QImage &value);

    double rayIntersectionWithSegm (QPointF pos, QPointF dir);
private:
    Scene *m_scene = 0;
    QImage buffer;
    double fov; //Угол обзора
    double width;
};

#endif // RAYCASTINGPAINTER_H
