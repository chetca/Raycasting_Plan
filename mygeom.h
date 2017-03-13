#ifndef MYGEOM
#define MYGEOM
#include <QPointF>
#include <cmath>

#define PI (acos(-1.))

double vec (const QPointF &a, const QPointF &b, const QPointF &c);

double getDist(const QPointF &a, const QPointF &b);

double getAngleBetweenTwoPt (const QPointF &a, const QPointF &b);

#endif // MYGEOM

