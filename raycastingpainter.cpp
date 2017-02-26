#include "raycastingpainter.h"

RaycastingPainter::RaycastingPainter()
{

}

void RaycastingPainter::paint(QWidget *widget, QPointF position, QPointF direction)
{
    //описать алгоритм как бросать луч
    //по возможности передать усилия на другие методы

    //Итак, можно сделать буфер. Это даст плавность кадров, но рендеринг будет медленнее
    if (buffer.size() != widget->size())
        buffer = QImage(widget->size(), QImage::Format_ARGB32);
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

    for (int i = 0; i < (int)(width/2);i++){
        //Бросаем по одному лучу на каждый кусочек экрана и переходим на следующий кусочек
        QPointF rayDirect1 (direction + rayStep);
        QPointF rayDirect2 (direction - rayStep);

        dist = rayIntersectionWithSegm(position,rayDirect1);

        //... shader

        dist = rayIntersectionWithSegm(position,rayDirect2);

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

double RaycastingPainter::rayIntersectionWithSegm(QPointF pos, QPointF dir)
{
    double dist=0;
    //for (int i=0; i<m_scene->segment().size(); i++) {
        //take intersection point of segment and ray (with boost)...
    //}

    return dist;
}
