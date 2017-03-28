#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QPointF>
#include <QImage>
#include <QKeyEvent>
#include <QEvent>

#include "mygeom.h"

class Player : public QObject
{
    Q_OBJECT
public:
    explicit Player(QObject *parent = 0);

    QPointF getPos() const;
    void setPos(const QPointF &value);

    double getDir() const;
    void setDir(double value);
    void update(double time);

    QPointF getPtDir();

    void setDX(double r);
    void setDY(double r);

    void setDDIR(double r);

signals:

public slots:

private:
    double dir;
    double dx,dy, ddir;
    QPointF pos;
};

#endif // PLAYER_H
