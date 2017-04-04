#include "ssegment.h"
#include "mygeom.h"

#include <QDebug>

SSegment::SSegment()
{

}

SSegment::SSegment(QPointF a, QPointF b, int tx)
{
    this->a = a;
    this->b = b;
    texture = tx;
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

int SSegment::getTexture() const
{
    return texture;
}

void SSegment::setTexture(int value)
{
    texture = value;
}

void SSegment::update(double time)
{
    //MovableSegment::update(time);
}
