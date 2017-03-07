#include "raycastingpainter.h"

RaycastingPainter::RaycastingPainter(QWidget *parent) : QWidget(parent)
{
    m_scene = new Scene();

}

void RaycastingPainter::paint(QWidget *widget, QPointF position, QPointF direction)
{
    //описать алгоритм как бросать луч
    //по возможности передать усилия на другие методы

    //Итак, можно сделать буфер. Это даст плавность кадров, но рендеринг будет медленнее
    if (buffer.size() != widget->size())
        buffer = QImage(640,400, QImage::Format_ARGB32);
    castRays(position, direction, width);
}

Scene *RaycastingPainter::scene() const
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

void RaycastingPainter::castRays(QPointF position, QPointF direction, double width)
{
    //Метод описывающий бросание лучей
    double dist;   //переменная расстояния до препятствия

    QPointF rayStep(
                 (direction-position).y(),
                -(direction-position).x()
                );

    QPointF side1 = direction + rayStep*width/2;
    QPointF side2 = direction - rayStep*width/2;

    int it = 0;

    SSegment lim[4];
             lim[0] = SSegment (QPointF(-1e8, 1e8),QPointF( 1e8, 1e8));
             lim[1] = SSegment (QPointF(-1e8,-1e8),QPointF( 1e8,-1e8));
             lim[2] = SSegment (QPointF( 1e8, 1e8),QPointF( 1e8,-1e8));
             lim[3] = SSegment (QPointF(-1e8, 1e8),QPointF(-1e8,-1e8));




    for (int i = 0; i < (int)(width/2);i++){
        //Бросаем по одному лучу на каждый кусочек экрана и переходим на следующий кусочек
        QPointF rayDirect1 (direction + rayStep);
        QPointF rayDirect2 (direction - rayStep);

        dist = rayIntersectionWithSegm(position,rayDirect1,it);

        //... shader
        makeColumn(dist,i);

        dist = rayIntersectionWithSegm(position,rayDirect2,it);

        //... shader

    }
}

double RaycastingPainter::getFov() const
{
    return fov;
}

void RaycastingPainter::setFov(double value)
{
    fov = value;
}

double RaycastingPainter::getWidth() const
{
    return width;
}

void RaycastingPainter::setWidth(double value)
{
    width = value;
}

QImage RaycastingPainter::getBuffer() const
{
    return buffer;
}

void RaycastingPainter::setBuffer(const QImage &value)
{
    buffer = value;
}

void RaycastingPainter::makeColumn(double dist, int ii)
{
    int h = 10/dist;
    if (dist == 1e9) {
        h = 0;
    }

    int high = buffer.height();

    for (int i=0; i<high/2-h/2; i++) {
        buffer.setPixel(ii,i,12);
        //в дальнейшем Qrgb заменится на текстурку
    }

    for (int i=high/2-h/2; i<high/2+h/2; i++) {
        buffer.setPixel(ii,i,14);
    }

    for (int i=high/2+h/2; i<high; i++) {
        buffer.setPixel(ii,i,15);
    }
}


double RaycastingPainter::rayIntersectionWithSegm(QPointF pos, QPointF dir, int it)
{
    return m_scene->targetSegment(pos,dir,it).A().x();
}
