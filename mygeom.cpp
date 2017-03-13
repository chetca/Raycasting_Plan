#include "mygeom.h"

double vec (const QPointF &a, const QPointF &b, const QPointF &c)
{
    return (b.x()-a.x())*(c.y()-b.y()) - (b.y()-a.y())*(c.x()-b.x());
}


double getDist(const QPointF &a, const QPointF &b)
{
    return sqrt((b.x()-a.x())*(b.x()-a.x()) + (b.y()-a.y())*(b.y()-a.y()));
}

double getAngleBetweenTwoPt(const QPointF &a, const QPointF &b)
{
    QPointF v = b-a;
    double angle = atan(v.y()/v.x());
    return b.y() > a.y() ? angle : angle + PI;
}
