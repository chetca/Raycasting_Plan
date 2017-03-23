#include "raycastingpainter.h"
#include "mygeom.h"

#include <QDebug>
#include <deque>

RaycastingPainter::RaycastingPainter(QWidget *parent) : QWidget(parent){
    m_scene = new Scene();
    //paint (parent, this->player.getPos(),QPointF(100*cos(player.getDir()),100*sin(player.getDir())) );
    player = new Player(this);

    rbuffer = QImage(800, 600, QImage::Format_ARGB32);

    textures.push_back(QImage(":/wall1.jpg"));
    textures.push_back(QImage(":/wall2.jpg"));
    textures.push_back(QImage(":/doors2.jpg"));
}

void RaycastingPainter::paint(QPointF position, QPointF direction)
{

    castRays(position, direction, WIDTH);
}

Scene *RaycastingPainter::scene()
{
    return m_scene;
}

void RaycastingPainter::setScene(Scene *scene)
{
    m_scene = scene;
}

double dist(QPointF a, QPointF b)
{
    return sqrt((b.x()-a.x())*(b.x()-a.x()) + (b.y()-a.y())*(b.y()-a.y()));
}

void RaycastingPainter::castRays(QPointF position, QPointF direction, int width)
{
    //Метод описывающий бросание лучей

    QPointF rayStep = QPointF( /** (A,B) ---> (B,-A) **/ // вектор смотрит в право относительно pos & dir => rightViewSide = dir+(rayStep*width/2)
                 (direction-position).y(),
                -(direction-position).x()
                )*1.5/width; //1.5 - половина ширины экрана в 1.5 раз меньше чем длина отрезка [pos,dir]. Формула определения угла обзора
    // в будущем необходимо вынести этот коэффициент в файл для настроек.

    double dist = INF;   //переменная расстояния до препятствия

    QVector <int> seg; //список отрезков попавших в угол обзора

    QPointF leftViewSide  (direction-(rayStep*width/2)),
            rightViewSide (direction+(rayStep*width/2));

    for (int i=0; i<m_scene->getMapSegment().size(); i++) {
        if (vec(position,leftViewSide,m_scene->getMapSegment(i).A()) <=0 ||
            vec(position,leftViewSide,m_scene->getMapSegment(i).B()) <=0) {

            if (vec(position,rightViewSide,m_scene->getMapSegment(i).A()) >=0 ||
                vec(position,rightViewSide,m_scene->getMapSegment(i).B()) >=0) {
                seg.push_back(i);
            }
        }
    }

    int segmentsInViewSize = seg.size();

    for (int i=0; i<width/2; i++) {
        QPointF rayDirect1 (direction - rayStep*i);

        QPointF intersectPt(INF,INF), tempPt(INF,INF);

        int texture_id=-1;

        double columnWidthId=0;

        for (int j=0; j<segmentsInViewSize; j++) {
            intersectPt = rayIntersect (position,rayDirect1,m_scene->getMapSegment(seg[j]) );
            double dst = getDist(intersectPt,position);
            if (intersectPt.x()>=INF) dst = INF;
            if (dist > dst) {
                texture_id = m_scene->getMapSegment(seg[j]).getTexture();
                columnWidthId = getDist(intersectPt,m_scene->getMapSegment(seg[j]).A());
                dist = dst;
            }
        }

        double k1 = getDist(QPointF(0,0),rayStep*i),
               k2 = getDist(position, direction),
               gg = sqrt(k1*k1 + k2*k2);

        makeColumn(dist*(k2/gg),width/2-i-1, texture_id, columnWidthId);
        dist = INF;

        columnWidthId = 0;
        texture_id = -1;
        QPointF rayDirect2 (direction + rayStep*(i+1));

        for (int j=0; j<segmentsInViewSize; j++) {
            intersectPt = rayIntersect (position,rayDirect2,m_scene->getMapSegment(seg[j]));
            double dst = getDist(intersectPt,position);
            if (intersectPt.x()>=INF) dst = INF;
            if (dist > dst) {
                texture_id = m_scene->getMapSegment(seg[j]).getTexture();
                columnWidthId = getDist(intersectPt,m_scene->getMapSegment(seg[j]).A());
                dist = dst;
            }
        }
        makeColumn(dist*(k2/gg),i+width/2, texture_id, columnWidthId);

        dist = INF;
    }

    this->update();
}

void RaycastingPainter::makeColumn(double dist, int ii, int texture, double e)
{
    int h = round(10000./dist);
    if (dist == INF) {
        h = 0;
    }

    h = std::min(h,HEIGHT);

    QRgb cceil  = qRgb(133, 133, 133),
         ffloor = qRgb(227, 227, 255),
         wwall   = qRgb(150,150,0);

    for (int i=0; i<HEIGHT/2-h/2; i++) {
        rbuffer.setPixel(ii,i,ffloor);
        //в дальнейшем Qrgb заменится на текстурку
    }


    if (texture >= 0) {
        int wdth = textures[texture].width();
        int hght = textures[texture].height();

        QImage texturedColumn = textures[texture].scaled(wdth*h/hght,h);
        e = int(round(e*texturedColumn.width()/5))%texturedColumn.width();
        int wallBeg = (HEIGHT/2-h/2);
        for (int i=wallBeg; i<HEIGHT/2+h/2; i++) {
            rbuffer.setPixel(ii,i,texturedColumn.pixel(e,i-wallBeg));
        }
    }

    for (int i=HEIGHT/2+h/2; i<HEIGHT; i++) {
        rbuffer.setPixel(ii,i,cceil);
    }
}

QImage RaycastingPainter::getRbuffer()
{
    return rbuffer;
}

void RaycastingPainter::setRbuffer(const QImage &value)
{
    rbuffer = value;
}
