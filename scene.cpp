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

SSegment Scene::targetSegment(QPointF position, QPointF direction)
{
    int it=-1;
    double mx=1e9;
    for (int i=0; i<mapSegment.size(); i++) {
        QPointF pInter = mapSegment[i].getIntersect(position, direction);

        if (getDist(position,pInter) < mx) {
            mx = getDist(position, pInter);
            it = i;
        }
    }

    return SSegment(QPointF(mx,it),QPointF(0,0));
}
