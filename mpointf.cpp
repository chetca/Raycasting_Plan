#include "mpointf.h"

MPointF::MPointF()
{

}

MPointF::MPointF(QPointF a, QPointF b, double angle)
{
    //перегруженый конструктор
}

double MPointF::getAngle(const QPointF &a, const QPointF &b)
{
    QPointF v = b-a;
    double angle = atan(v.y()/v.x());
    return b.y() > a.y() ? angle : (angle + (acos(-1.)));
}

void MPointF::setAngle(double value)
{
    angle = value;
}

