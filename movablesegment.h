#ifndef MOVABLESEGMENT_H
#define MOVABLESEGMENT_H

#include "ssegment.h"
#include "mygeom.h"

#include <QPointF>

class MovableSegment : public SSegment
{
public:
    MovableSegment(SSegment *parent=0);
    MovableSegment(QPointF moveCentre, double l1, double l2, double speed, SSegment *parent=0);

private:
    void update(double &time);

public:
    QPointF mvPt;   // centre of moving
    double du;      // speed of moving
    double l1,l2;   // between that angles move will execute (if l1>l2 then segment moves clockwise, else ccw)
    double l;       // current angle
    double len;
};

#endif // MOVABLESEGMENT_H
