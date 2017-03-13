#include "player.h"

Player::Player(QObject *parent) : QObject(parent)
{
    buffer = new QImage(800, 600, QImage::Format_ARGB32);

}

QPointF Player::getPos() const
{
    return pos;
}

void Player::setPos(const QPointF &value)
{
    pos = value;
}

double Player::getDir() const
{
    return dir;
}

void Player::setDir(double value)
{
    dir = value;
}

QImage *Player::getBuffer() const
{
    return buffer;
}

void Player::setBuffer(QImage value)
{
    *buffer = value;
}

void Player::setPixelToBuf(int x, int y, int color)
{
    this->buffer->setPixel(x,y,color);
}

