#include "raycastingpainter.h"

RaycastingPainter::RaycastingPainter()
{

}

void RaycastingPainter::paint(QWidget *widget, QPointF position, QPointF direction)
{
    //описать алгоритм как бросать луч
    //по возможности передать усилия на другие методы

    //Итак, можно сделать буфер. Это даст плавность кадров, но рендеринг будет медленнее
    if (buffer.size() != size())
        buffer = QImage(size(), QImage::Format_ARGB32);
    castRays(position, direction, fow, width);
}

Scene *RaycastingPainter::scene() const
{
    return m_scene;
}

void RaycastingPainter::setScene(Scene *scene)
{
    m_scene = scene;
}

void RaycastingPainter::castRays(QPointF position, QPointF direction, double fov, double width)
{
    //Метод описывающий бросание лучей
    double angleBetweenRays = ((double)direction*(180/Math.PI) / width)*Math.PI /180; //делим угол обзора на маленьки кусочки - углы куда будут бросаться лучи
    double dist;   //переменная расстояния до препятствия
    double angle = fov/2 + (double)position; //(pos+dir+plane)
    if(angle < 0) //Если получившийся угол отрицательный
        angle += 360 * Math.PI /180;//поворачиваем его на 2*Pi по часовой
    if(angle > 0) //Если получившийся угол положительный
        angle -= 360 * Math.PI /180; //поворачиваем его на 2*Pi против часовой

      for (int i = 0; i < width;i++){
        //Бросаем по одному лучу на каждый кусочек экрана и переходим на следующий кусочек
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
