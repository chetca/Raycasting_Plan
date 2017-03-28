#include "raycastingpainter.h"

#include <QDebug>
#include <deque>

RaycastingPainter::RaycastingPainter(QWidget *parent) : QWidget(parent) {
    m_scene = new Scene();
    player = new Player(this);
    player->setPos(m_scene->ps);

    rbuffer = QImage(WIDTH, HEIGHT, QImage::Format_ARGB32);

    textures.push_back(QImage(":/wall1.jpg" ));
    textures.push_back(QImage(":/wall2.jpg" ));
    textures.push_back(QImage(":/doors2.jpg"));

    this->grabKeyboard();
}

void RaycastingPainter::paint()
{
    castRays(player->getPos(), player->getPtDir(), WIDTH);
    //qDebug() << player->getPtDir() << " " << player->getDir();
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

        QPointF intersectPt(INF,INF);

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

void RaycastingPainter::makeColumn(double dist, int ii, int texture, double e) // shader !!! "e" - the distance between rayIntersection & an end of segment
{
    int h = round(10000./dist);
    if (dist == INF) {h = 0;}

    QRgb cceil  = qRgb(133, 133, 133);
    QRgb ffloor = qRgb(227, 227, 255);
    QRgb wall   = qRgb(150, 0, 100);

    int wallBeg = (HEIGHT/2-h/2);
    int wallEnd = (HEIGHT/2+h/2);

    for (int i=0; i<wallBeg; i++) {
        rbuffer.setPixel(ii,i,ffloor);
    }

    if (texture >= 0) {
        int wdth = textures[texture].width();
        int hght = textures[texture].height();

//        QImage texturedColumn = textures[texture].scaled(wdth*h/hght,h);
//        e = int(round(e/wdth))%texturedColumn.width();
//        for (int i=wallBeg; i<wallEnd; i++) {
//            rbuffer.setPixel(ii,i,texturedColumn.pixel(e,i-wallBeg));
//            //rbuffer.setPixel(ii,i,wall);
//        }

        QImage textureColumn = (textures[texture].copy(int(round(e))%wdth,1,1,h)).scaled(1,h);

        qDebug() <<int(round(e));

        for (int i=wallBeg; i<wallEnd; i++) {
            if (i>=wallBeg && i<HEIGHT) {
                //rbuffer.setPixel(ii,i,wall);
                if (i>=0 && i<HEIGHT) {
                    rbuffer.setPixel(ii,i,textureColumn.pixel(0,i-wallBeg));
                }
            }
        }
    }

    for (int i=wallEnd; i<HEIGHT; i++) {
        rbuffer.setPixel(ii,i,cceil);
    }
}

QImage RaycastingPainter::getRbuffer() {return rbuffer;}
void RaycastingPainter::setRbuffer(const QImage &value) {rbuffer = value;}
Scene *RaycastingPainter::scene() {return m_scene;}
void RaycastingPainter::setScene(Scene *scene) {m_scene = scene;}
