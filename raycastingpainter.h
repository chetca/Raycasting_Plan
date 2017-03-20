#ifndef RAYCASTINGPAINTER_H
#define RAYCASTINGPAINTER_H

#include "scene.h"
#include "player.h"

#include <QWidget>
#include <QPointF>
#include <QtMath>
#include <QVector>
#include <algorithm>
#include <utility>
#include <QPaintEvent>

class RaycastingPainter:public QWidget
{
    Q_OBJECT

public:

    explicit RaycastingPainter(QWidget *parent=0);

    void paint(QWidget *widget, QPointF position, QPointF direction);

    Scene *scene();
    void setScene(Scene *scene);
    void castRays(QPointF position, QPointF direction, int width);

    double getWidth() const;
    void setWidth(double value);

    void makeColumn(double dist, int i);

    int WIDTH = 800;
    int HEIGHT = 600;

private:
    Scene *m_scene = 0;
    QImage rbuffer;

public: Player *player;
    QImage getRbuffer() const;
    void setRbuffer(const QImage &value);
};

#endif // RAYCASTINGPAINTER_H
