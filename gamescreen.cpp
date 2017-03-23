#include "gamescreen.h"

GameScreen::GameScreen(QImage img, QWidget *parent)
{
//    a = new QImage(800, 600, QImage::Format_ARGB32);
//    *a = img;
    a = QImage(800,600, QImage::Format_ARGB32);
}

//void GameScreen::paintEvent(QPaintEvent *event)
//{
//    QPainter aa(this);
//    aa.drawImage(event->rect(), (a), event->rect());
//}

//void GameScreen::setImg(QImage img)
//{
//    a = img;
//}
