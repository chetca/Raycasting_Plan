#include "mygeom.h"

#include <QDebug>

double vec              ( QPointF a,  QPointF b,  QPointF c)  {return (b.x()-a.x())*(c.y()-b.y()) - (b.y()-a.y())*(c.x()-b.x());}
double getDist          ( QPointF a,  QPointF b)                    {return sqrt((b.x()-a.x())*(b.x()-a.x()) + (b.y()-a.y())*(b.y()-a.y()));}
double getSquaredDist   ( QPointF a,  QPointF b)                    {return     ((b.x()-a.x())*(b.x()-a.x()) + (b.y()-a.y())*(b.y()-a.y()));}


double getAngleBetweenTwoPt(const QPointF &a, const QPointF &b)
{
    QPointF v = b-a;
    double angle = atan(v.y()/v.x());
    return b.y() > a.y() ? angle : angle + PI;
}

double getAngleBetween3Pts(const QPointF &a, const QPointF &b, const QPointF &c) //angle = (b,a,c);
{
    double A = getSquaredDist(b,c);
    double B = getSquaredDist(a,c);
    double C = getSquaredDist(b,a);

    return acos((B + C - A)/(sqrt(B)*sqrt(C)*2));
}

QPointF getIntersectionOfLines (QPointF a, QPointF b, QPointF c, QPointF d)
{
    double A1 = a.y() - b.y(),
           B1 = b.x() - a.x(),
           C1 = -A1*a.x() - B1*a.y(); // коэффициенты первой прямой ab;


    double A2 = c.y() - d.y(),
           B2 = d.x() - c.x(),
           C2 = -A2*c.x() - B2*c.y(); // коэффициенты второй прямой cd;

    double ABBA = A1*B2 - A2*B1;

    if (ABBA == 0) {
        return QPointF(1e9,1e9);
    }

    double x = - (C1*B2 - C2*B1)/ABBA;
    double y =   (C1*A2 - C2*A1)/ABBA;

    return QPointF(x,y);
}

QPointF rayIntersect( QPointF a,  QPointF b,  SSegment ss)
{
    QPointF inter (1e9,1e9);

    if ((vec(a,b,ss.A()) < 0 && vec(a,b,ss.B()) > 0)) {
        if (vec(ss.A(),ss.B(),a) > 0) {
            inter = getIntersectionOfLines (a,b,ss.A(),ss.B());
        }
    }
    if ((vec(a,b,ss.A()) > 0 && vec(a,b,ss.B()) < 0)) {
        if (vec(ss.A(),ss.B(),a) < 0) {
            inter = getIntersectionOfLines (a,b,ss.A(),ss.B());
        }
    }

    if (inter.x()!=INF) {return inter;}

    return QPointF(INF,INF);
}
