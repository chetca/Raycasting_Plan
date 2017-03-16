#ifndef MYGEOM
#define MYGEOM

#include <QPointF>
#include <cmath>
#include <algorithm>

#include "ssegment.h"

#define PI (acos(-1.))
#define INF 1e8

double vec                      ( QPointF a,  QPointF b,  QPointF c);

double getDist                  ( QPointF a,  QPointF b);

double getSquaredDist           ( QPointF a,  QPointF b);

double getAngleBetweenTwoPt     (const QPointF &a, const QPointF &b);

double getAngleBetween3Pts      (const QPointF &a, const QPointF &b, const QPointF &c); //angle = (b,a,c);

QPointF getIntersectionOfLines  (QPointF a, QPointF b, QPointF c, QPointF d);

double rayIntersect             (QPointF a, QPointF b, SSegment ss);

#endif // MYGEOM

