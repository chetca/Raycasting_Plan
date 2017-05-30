#ifndef MINIMAPPLAYER_H
#define MINIMAPPLAYER_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>

#include "mygeom.h"

class MiniMapPlayer: public QGraphicsPixmapItem
{
public:
    MiniMapPlayer(QGraphicsItem *parent=0);

    void rotate();
    double dir;
};

#endif // MINIMAPPLAYER_H
