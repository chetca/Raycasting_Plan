#include "scene.h"

Scene::Scene()
{
    pos = QPointF(0,0);
    dir = QPointF(0,1);
}

inline double getDist(QPointF a, QPointF b)
{
    return sqrt((b.x()-a.x())*(b.x()-a.x()) + (b.y()-a.y())*(b.y()-a.y()));
}

SSegment Scene::targetSegment(QPointF position, QPointF direction, int it)
{
    //заглушка
}
