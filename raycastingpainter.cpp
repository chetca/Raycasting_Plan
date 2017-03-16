#include "raycastingpainter.h"
#include "mygeom.h"

RaycastingPainter::RaycastingPainter(QWidget *parent) : QWidget(parent){
    m_scene = new Scene();
    //paint (parent, this->player.getPos(),QPointF(100*cos(player.getDir()),100*sin(player.getDir())) );
    player = new Player(this);
}

void RaycastingPainter::paint(QWidget *widget, QPointF position, QPointF direction)
{
    //описать алгоритм как бросать луч
    //по возможности передать усилия на другие методы

    //Итак, можно сделать буфер. Это даст плавность кадров, но рендеринг будет медленнее
    if (player->getBuffer()->size() != widget->size())
        player->setBuffer(QImage(WIDTH,HEIGHT, QImage::Format_ARGB32));
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

    double dist;   //переменная расстояния до препятствия

    //new version

    QVector <int> seg; //список отрезков попавших в угол обзора

    QPointF leftViewSide  (direction-(rayStep*width/2)),
            rightViewSide (direction+(rayStep*width/2));

    for (int i=0; i<m_scene->getCnt(); i++) {
        if (vec(position,leftViewSide,m_scene->getMapSegment(i).A()) <=0 ||
            vec(position,leftViewSide,m_scene->getMapSegment(i).B()) <=0) {

            if (vec(position,rightViewSide,m_scene->getMapSegment(i).A()) >=0 ||
                vec(position,rightViewSide,m_scene->getMapSegment(i).B()) <=0) {
                seg.push_back(i);
            }
        }
    }

    int segmentsInViewSize = seg.size();

    for (int i=0; i<width/2; i++) {
        QPointF rayDirect1 (direction + rayStep*i);

        for (int j=0; j<segmentsInViewSize; j++) {
            dist = std::min(dist, rayIntersect (position,rayDirect1,m_scene->getMapSegment(seg[j]) ));
        }
        makeColumn(dist,i);

        QPointF rayDirect2 (direction - rayStep*(i+1));

        for (int j=0; j<segmentsInViewSize; j++) {
            dist = std::min(dist, rayIntersect (position,rayDirect2,m_scene->getMapSegment(seg[j]) ));
        }
        makeColumn(dist,i);
    }

    // sortPoints;

    // casts;

    //old version:
 /**
    for (int i = 0; i < (int)(width/2);i++){
        //Бросаем по одному лучу на каждый кусочек экрана и переходим на следующий кусочек
        QPointF rayDirect1 (direction + rayStep);
        QPointF rayDirect2 (direction - rayStep);

        dist = rayIntersectionWithSegm(position,rayDirect1);

        //... shader
        makeColumn(dist,i);

        dist = rayIntersectionWithSegm(position,rayDirect2);

        //... shader
    }
 **/
}

void RaycastingPainter::makeColumn(double dist, int ii)
{
    int h = 10/dist;
    if (dist == 1e9) {
        h = 0;
    }

    int high = player->getBuffer()->height();

    for (int i=0; i<high/2-h/2; i++) {
        player->setPixelToBuf(ii,i,12);
        //в дальнейшем Qrgb заменится на текстурку
    }

    for (int i=high/2-h/2; i<high/2+h/2; i++) {
        player->setPixelToBuf(ii,i,14);
    }

    for (int i=high/2+h/2; i<high; i++) {
        player->setPixelToBuf(ii,i,15);
    }
}
