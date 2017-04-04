#ifndef SCENE_H
#define SCENE_H

#include "ssegment.h"
#include "movablesegment.h"

#include <QPointF>
#include <QVector>
#include <QtMath>
#include <QRectF>

//#include <boost/geometry.hpp>

class Scene
{
public:
    Scene();

    QVector<MovableSegment> getMapSegment();
    MovableSegment getMapSegment(int i);
    void setMapSegment(const QVector<MovableSegment> &value);

    int getCnt();
    void setCnt(int value);
    void swapSegmentsEnds(int i);
    void update(double time);

private:
    QVector<MovableSegment> mapSegment;

public:
    QPointF ps;
    int cnt;
};

#endif // SCENE_H
