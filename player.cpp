#include "player.h"

#include <QDebug>
#include <cmath>

Player::Player(QObject *parent) : QObject(parent)
{    
    pos = QPointF(0,0);
    dx = dy = 0;
    ddir = 0;
    dir = 0;
}


QPointF Player::    getPos()                     const  {return pos;}
void    Player::    setPos(const QPointF &value)        {pos = value;}
double  Player::   getDir()                      const  {return dir;}
void    Player::    setDir(double value)                {dir = value;}


void Player::update(double &time)
{
    pos.setX(pos.x() + dx*time*0.01);
    pos.setY(pos.y() + dy*time*0.01);
    dir += (ddir*time*(-0.00001));
    time = 0;
}

void Player::back(double &time)
{
    pos.setX(pos.x() - dx*time*0.01);
    pos.setY(pos.y() - dy*time*0.01);
}

QPointF Player::getPtDir()
{
    return QPointF(cos(dir)*10,sin(dir)*10) + pos;
}

void Player::setDX   (double r)  {dx = r;}
void Player::setDY   (double r)  {dy = r;}
void Player::setDDIR (double r)  {ddir = r;}
