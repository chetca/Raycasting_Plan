#ifndef MOVABLESEGMENT_H
#define MOVABLESEGMENT_H

#include "ssegment.h"
#include "mygeom.h"

#include <QPointF>
#include <QtGlobal>

class MovableSegment : public SSegment
{
public:
    MovableSegment(SSegment *parent=0);
    MovableSegment(QPointF a, QPointF b, QPointF moveCentre, int texture=0, double l1=0, double l2=0, double speed=0, SSegment *parent=0);

private:


public:
    QPointF mvPt;   // centre of moving
    double du;      // speed of moving
    double l1,l2;   // between that angles move will execute (if l1>l2 then segment moves clockwise, else ccw)
    double l;       // current angle
    double len;
    void update(double &time);

};

#endif // MOVABLESEGMENT_H
