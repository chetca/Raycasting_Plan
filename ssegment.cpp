#include "ssegment.h"

SSegment::SSegment()
{

}

SSegment::SSegment(QPointF a, QPointF b)
{
    this->a = a;
    this->b = b;
}

inline double vec (QPointF a, QPointF b, QPointF c)
{
    return (b.x()-a.x())*(c.y()-b.y()) - (b.y()-a.y())*(c.x()-b.x());
}

inline double getDist(QPointF a, QPointF b)
{
    return sqrt((b.x()-a.x())*(b.x()-a.x()) + (b.y()-a.y())*(b.y()-a.y()));
}

void ABC (QPointF a, QPointF b, double &A, double &B, double &C)
{
    //http://e-maxx.ru/algo/segment_to_line
    A = a.y() - b.y();
    B = b.x() - a.x();
    C = - A * a.x() - B * a.y();
}

QPointF SSegment::getIntersect(QPointF pos, QPointF dir)
{
    double vca = vec(pos, dir, a),
           vcb = vec(pos, dir, b);

    bool aa = vca>=0 ? 1 : 0;
    bool bb = vcb<=0 ? 1 : 0;

    if (aa && bb) { //положение отрезка относительно луча
        double a1,b1,c1,
               a2,b2,c2;

        ABC( a , b ,a1,b1,c1);
        ABC(pos,dir,a2,b2,c2);

        double ABAB = a1*b2 - a2*b1;

        if (ABAB==0) goto LOL; // если детерминант матрицы a1,b1,a2,b2 равен нулю, то точки пересечения нет

        double x = (c1*b2-c2*b1)/ABAB;
        double y = (a1*c2-a2*c1)/ABAB;

        if ((pos.x() <= x && dir.x() >= x) || (pos.x() >= x && dir.x() <= x)) {
            if ((pos.y() <= y && dir.y() >= y) || (pos.y() <= y && dir.y() >= y)) {

            }
        }

        return QPointF(x, y); // формула Крамера
    }
    else {
LOL:        return QPointF(1e9,1e9);
    }
}

double SSegment::getSize()
{
    return getDist(a,b);
}

QPointF SSegment::A() const
{
    return a;
}

void SSegment::setA(const QPointF &value)
{
    a = value;
}

QPointF SSegment::B() const
{
    return b;
}

void SSegment::setB(const QPointF &value)
{
    b = value;
}
