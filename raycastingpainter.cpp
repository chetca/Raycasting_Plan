#include "raycastingpainter.h"

RaycastingPainter::RaycastingPainter()
{

}

void RaycastingPainter::paint(QWidget *widget, QPointF position, QPointF direction)
{
    //описать алгоритм как бросать луч
    //по возможности передать усилия на другие методы
}

Scene *RaycastingPainter::scene() const
{
    return m_scene;
}

void RaycastingPainter::setScene(Scene *scene)
{
    m_scene = scene;
}
