#include "minimapplayer.h"

#include <QDebug>

MiniMapPlayer::MiniMapPlayer(QGraphicsItem *parent)
{
    setPixmap(QPixmap(":/MinimapPlayer.png"));
    dir=0;
}

void MiniMapPlayer::rotate()
{
    qDebug() << dir;
    setRotation(dir*acos(-1.)/360. + 90);
    setPos(this->pos() - QPointF(cos(dir), sin(dir)));
}
