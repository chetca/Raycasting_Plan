#ifndef SSEGMENT_H
#define SSEGMENT_H

#include <QPointF>
#include <cmath>
#include <algorithm>

class SSegment
{
public:
    SSegment();
    SSegment(QPointF a, QPointF b);

    //точка пересечения лучей отрезка
    QPointF getIntersect(QPointF pos, QPointF dir);

    double getSize();

    QPointF A();
    void setA(const QPointF &value);

    QPointF B();
    void setB(const QPointF &value);

    void swapEnds();

private:
    QPointF a,b;
    int texture;
};

#endif // SSEGMENT_H
