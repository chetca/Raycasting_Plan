#include "scene.h"

#include <QDebug>
#include <QFile>
#include <sstream>
#include <algorithm>

Scene::Scene()
{
//    QFile mapTxt("/home/chetca/Projects/Raycasting_Plan-test/testlevel.map");
    QFile mapTxt("/Users/dugar/Desktop/Raycasting_Plan-test/testlevel.map");

    if (!mapTxt.open(QIODevice::ReadOnly)) {qDebug() << "file can't be opened";}
    else {qDebug() << "successfull opening file !";}
    bool FF=0;
    while (!mapTxt.atEnd()) {
        QByteArray l = mapTxt.readLine();
        std::stringstream ss;
        ss << l.toStdString();
        std::string g;
        double x,y;

        if (!FF) {if (ss>>x>>y) { ps = QPointF(x,y); FF=1;}}

        if (FF) {
            double x1,y1,x2,y2,t;
            ss >> x1 >> y1 >> x2 >> y2 >> t;
            mapSegment.push_back(MovableSegment(QPointF(x1,y1),QPointF(x2,y2),QPointF(x2,y2),t));
        }
    }


//    mapSegment.push_back(SSegment(QPointF(-10,10),QPointF(100,10),1));
//    mapSegment.push_back(SSegment(QPointF(-10,-10),QPointF(100,-10),2));

//    mapSegment.push_back(SSegment(QPointF(0,12),QPointF(20,-10),0));
//    mapSegment.push_back(SSegment(QPointF(15,0),QPointF(15,-10),1));
//    mapSegment.push_back(SSegment(QPointF(10.5,5),QPointF(10,-0.6)));
//    mapSegment.push_back(MovableSegment(QPointF(100,20), QPointF(120, 20), QPointF(100,-20), 1, 0,0,0.4));
//    mapSegment.push_back(MovableSegment(QPointF(120,20), QPointF(120, 40), QPointF(100,-20), 1, 0,0,0.4));
//    mapSegment.push_back(MovableSegment(QPointF(100,20), QPointF(100, 40), QPointF(100,-20), 1, 0,0,0.4));
//    mapSegment.push_back(MovableSegment(QPointF(100,40), QPointF(120, 40), QPointF(100,-20), 1, 0,0,0.4));

//    mapSegment.push_back(MovableSegment(QPointF(140,40), QPointF(160, 40), QPointF(100,-20), 1, 0,0,0.4));
//    mapSegment.push_back(MovableSegment(QPointF(160,60), QPointF(180, 60), QPointF(100,-20), 1, 0,0,0.4));
//    mapSegment.push_back(MovableSegment(QPointF(140,40), QPointF(140, 60), QPointF(100,-20), 1, 0,0,0.4));
//    mapSegment.push_back(MovableSegment(QPointF(140,60), QPointF(160, 60), QPointF(100,-20), 1, 0,0,0.4));

//    mapSegment.push_back(MovableSegment(QPointF(100,10), QPointF(100,-20), QPointF(100,-20), 0,0,0.4));
//    mapSegment.push_back(MovableSegment(QPointF(100,10), QPointF(100,-20), QPointF(100,-20), 0,0,0.4));
}

QVector<MovableSegment> Scene::getMapSegment()
{
    return mapSegment;
}

MovableSegment Scene::getMapSegment(int i)
{
    if (i>=0 && i<mapSegment.size()) {
        return mapSegment[i];
    }

    qDebug() << "mapSegment [" << i << "] doesn't exist, motherfacka !!!!";
}

void Scene::setMapSegment(const QVector<MovableSegment> &value)
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

void Scene::update(double time)
{
    mapSegment[0].update(time);
}
