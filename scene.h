#ifndef SCENE_H
#define SCENE_H

#include "ssegment.h"

#include <QPointF>
#include <QVector>
#include <cmath>
//#include <boost/geometry.hpp>

class Scene
{
public:


    Scene();

    SSegment targetSegment(QPointF position, QPointF direction, int it);

private:
    QVector<SSegment> mapSegment;
    QPointF pos, dir;
};

#endif // SCENE_H
