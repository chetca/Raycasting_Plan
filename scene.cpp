#include "scene.h"

Scene::Scene()
{
    mapSegment.push_back(SSegment(QPointF(10,0),QPointF(10,10)));
    mapSegment.push_back(SSegment(QPointF(10,10),QPointF(0,10)));
}

QVector<SSegment> Scene::getMapSegment()
{
    return mapSegment;
}

SSegment Scene::getMapSegment(int i)
{
    return mapSegment[i];
}

void Scene::setMapSegment(const QVector<SSegment> &value)
{
    mapSegment = value;
}

int Scene::getCnt()
{
    return cnt;
}

void Scene::setCnt(int value)
{
    cnt = value;
}

void Scene::swapSegmentsEnds(int i)
{
    mapSegment[i].swapEnds();
}
