#include "player.h"

#include <QDebug>

Player::Player(QObject *parent) : QObject(parent)
{    
    pos = QPointF(0,0);
    dir = 0;

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
