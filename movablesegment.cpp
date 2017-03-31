#include "movablesegment.h"

MovableSegment::MovableSegment(SSegment *parent)
{

}

MovableSegment::MovableSegment(QPointF moveCentre, double l1, double l2, double speed, SSegment *parent)
{
    mvPt = moveCentre;
    this->l1 = l1;
    this->l2 = l2;
    l = l1;
    du = speed;
    len = 0;
}

void MovableSegment::update(double &time)
{
    if (l1 > l2) {
        if (l<=l2) {
            return;
        }
    }
    else {
        if (l>=l2) {
            return;
        }
    }

    l+=du*time;


}

