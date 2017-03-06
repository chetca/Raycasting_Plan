#ifndef SCENE_H
#define SCENE_H

#include "ssegment.h"

#include <QPointF>
#include <QVector>
//#include <boost/geometry.hpp>

class Scene
{
public:


    Scene();

    SSegment targetSegment(QPointF position, QPointF direction);

private:
    QVector<SSegment> mapSegment;
    QPointF pos, dir;
};

#endif // SCENE_H
