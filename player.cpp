#include "player.h"

#include <QDebug>
#include <cmath>

Player::Player(QObject *parent) : QObject(parent)
{    
    pos = QPointF(50000,6000);
    dx = dy = 0;
    dir = 12;
}

QPointF Player::getPos() const{return pos;}

void Player::setPos(const QPointF &value) {pos = value;}

double Player::getDir() const {return dir;}

void Player::setDir(double value) {dir = value;}

void Player::update(double time)
{
    pos.setX(pos.x() + dx*time*0.1);
    pos.setY(pos.y() + dy*time*0.1);
    dir += (ddir*time*0.1);
    ddir=0;
    dx=0;
    dy=0;
}

QPointF Player::getPtDir()
{
    return QPointF(cos(dir)*10,sin(dir)*10) + pos;
}

void Player::setDX(double r)   {dx = r;}
void Player::setDY(double r)   {dy = r;}
void Player::setDDIR(double r) {ddir = r;}
