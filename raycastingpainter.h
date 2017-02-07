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

private:
    Scene *m_scene = 0;
};

#endif // RAYCASTINGPAINTER_H
