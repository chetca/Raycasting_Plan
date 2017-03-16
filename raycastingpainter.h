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

    QImage getBuffer() const;
    void setBuffer(const QImage &value);

    void makeColumn(double dist, int i);

    int WIDTH = 800;
    int HEIGHT = 600;

private:
    Scene *m_scene = 0;
    //QImage buffer;
    //double fov; //Угол обзора
public: Player *player;
};

#endif // RAYCASTINGPAINTER_H
