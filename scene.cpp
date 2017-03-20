#include "scene.h"

#include <QDebug>

Scene::Scene()
{

    mapSegment.push_back(SSegment(QPointF(-10,10),QPointF(100,10)));
    mapSegment.push_back(SSegment(QPointF(-10,-10),QPointF(100,-10)));

    setCnt(4);
}

QVector<SSegment> Scene::getMapSegment()
{
    return mapSegment;
}

SSegment Scene::getMapSegment(int i)
{
    if (i>=0 && i<mapSegment.size()) {
        return mapSegment[i];
    }

    qDebug() << "mapSegment [" << i << "] doesn't exist, motherfacka !!!!";
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
    if (i>=mapSegment.size()) {
        return;
    }
    mapSegment[i].swapEnds();
}
