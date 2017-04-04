#ifndef SSEGMENT_H
#define SSEGMENT_H

#include <QPointF>
#include <cmath>
#include <algorithm>

//#include "movablesegment.h";

class SSegment
{
public:
    SSegment();
    SSegment(QPointF a, QPointF b, int tx=0);

    double getSize();

    QPointF A();
    void setA(const QPointF &value);

    QPointF B();
    void setB(const QPointF &value);

    void swapEnds();

    int getTexture() const;
    void setTexture(int value);   

    virtual void update(double time);

private:
    QPointF a,b;
    int texture;
};

#endif // SSEGMENT_H
