#ifndef SCENE_H
#define SCENE_H

#include <QPointF>
#include <QVector>
#include <boost/geometry.hpp>


class Scene
{
public:
    using Segment = boost::geometry::model::segment<QPointF>;

    Scene();

    Segment targetSegment(QPointF position, QPointF direction);

private:
    QVector<Segment> m_segment;
};

#endif // SCENE_H
