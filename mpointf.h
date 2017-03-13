#ifndef MPOINTF_H
#define MPOINTF_H

#include <QPointF>
#include <cmath>


class MPointF : public QPointF
{

public:
    MPointF();
    MPointF(QPointF a, QPointF b, double angle);

    double getAngle(const QPointF &a, const QPointF &b);
    void setAngle(double value);

private:
    double angle;
    int id;
};

#endif // MPOINTF_H
