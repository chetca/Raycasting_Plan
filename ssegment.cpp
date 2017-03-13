#include "ssegment.h"
#include "mygeom.h"

SSegment::SSegment()
{

}

SSegment::SSegment(QPointF a, QPointF b)
{
    this->a = a;
    this->b = b;
}

QPointF SSegment::getIntersect(QPointF pos, QPointF dir)
{
    double vca = vec(pos, dir, a),
           vcb = vec(pos, dir, b);

    bool aa = vca>=0 ? 1 : 0;
    bool bb = vcb<=0 ? 1 : 0;

    if (aa && bb) {
        QPointF v1=a-b,v2=dir-pos;
        double y = ((v1.x()*a.y())/v1.y() + a.x() - pos.x()/v2.x() - pos.y()/v2.y())/(v1.x()/v1.y() - v2.x()/v2.y()),
               x = v1.x()*(y-a.y())/v1.y() + a.x();

        if (getDist(dir,QPointF(x,y)) > getDist(pos, QPointF(x,y))) {
            goto LOL;
        }
        return QPointF(x,y);
    }
    else {
LOL:        return QPointF(1e9,1e9);
    }
}

double SSegment::getSize()
{
    return getDist(a,b);
}

QPointF SSegment::A()
{
    return a;
}

void SSegment::setA(const QPointF &value)
{
    a = value;
}

QPointF SSegment::B()
{
    return b;
}

void SSegment::setB(const QPointF &value)
{
    b = value;
}

void SSegment::swapEnds()
{
    QPointF c = a;
    a = b;
    b = c;
}
