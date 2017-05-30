#include "movablesegment.h"

#include <QDebug>

MovableSegment::MovableSegment(SSegment *parent)
{

}

MovableSegment::MovableSegment(QPointF a, QPointF b, QPointF moveCentre, int texture, double l1, double l2, double speed, SSegment *parent) : SSegment(a,b,texture)
{
    mvPt = moveCentre;
    this->l1 = l1;
    this->l2 = l2;
    l = getAngleBetweenTwoPt(a,b);
    l1 += l;
    l2 += l;
    du = speed;
    len = getDist(a,b);
}

void MovableSegment::update(double &time)
{
    time = qBound(1.,time,200.);
    if (l1 > l2) {
        if (l+du*time<=l2) {
            l = l2;
            setB(QPointF(cos(l)*len + A().x(), sin(l)*len + A().y()));
            return;
        }
    }
    else {
        if (l+du*time>=l2) {
            l = l2;
            setB(QPointF(cos(l)*len + A().x(), sin(l)*len + A().y()));
            return;
        }
    }

    l+=du*time;

    setB(QPointF(cos(l)*len + A().x(), sin(l)*len + A().y()));
}

