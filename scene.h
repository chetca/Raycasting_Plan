#ifndef SCENE_H
#define SCENE_H

#include "ssegment.h"

#include <QPointF>
#include <QVector>
#include <QtMath>
#include <QRectF>

//#include <boost/geometry.hpp>

class Scene
{
public:


    Scene();

    QVector<SSegment> getMapSegment();
    SSegment getMapSegment(int i);
    void setMapSegment(const QVector<SSegment> &value);

    int getCnt();
    void setCnt(int value);
    void swapSegmentsEnds(int i);

private:
    QVector<SSegment> mapSegment;

public:
    QPointF ps;
    int cnt;
};

#endif // SCENE_H
