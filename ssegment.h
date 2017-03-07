#ifndef SSEGMENT_H
#define SSEGMENT_H

#include <QPointF>
#include <cmath>

class SSegment
{
public:
    SSegment();
    SSegment(QPointF a, QPointF b);

    //точка пересечения лучей отрезка
    QPointF getIntersect(QPointF pos, QPointF dir);

    double getSize();

    QPointF A() const;
    void setA(const QPointF &value);

    QPointF B() const;
    void setB(const QPointF &value);

private:
    QPointF a,b;
};

#endif // SSEGMENT_H
