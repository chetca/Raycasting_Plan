#ifndef RAYCASTINGPAINTER_H
#define RAYCASTINGPAINTER_H

#include "scene.h"

#include <QWidget>
#include <QPointF>

class RaycastingPainter
{
public:
    RaycastingPainter();

    void paint(QWidget *widget, QPointF position, QPointF direction);

    Scene *scene() const;
    void setScene(Scene *scene);
    void castRays(QPointF position, QPointF direction, double fov, double width);

    double getFov() const;
    void setFov(double value);

    double getWidth() const;
    void setWidth(double value);

    QImage getBuffer() const;
    void setBuffer(const QImage &value);

private:
    Scene *m_scene = 0;
    QImage buffer;
    double fov; //Угол обзора
    double width;
};

#endif // RAYCASTINGPAINTER_H
