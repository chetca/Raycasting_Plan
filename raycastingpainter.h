#ifndef RAYCASTINGPAINTER_H
#define RAYCASTINGPAINTER_H

#include "scene.h"
#include "player.h"
#include "mygeom.h"

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

    void paint();

    Scene *scene();
    void setScene(Scene *scene);
    void castRays(QPointF position, QPointF direction, int width);

    void makeColumn(double dist, int i, int texture, double e);
    void updateScene(double time);
private:
    Scene *m_scene = 0;
    QVector <QImage> textures;

public: Player *player;
    QImage getRbuffer();
    QImage rbuffer;
    void setRbuffer(const QImage &value);
};

#endif // RAYCASTINGPAINTER_H
