#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QPointF>
#include <QImage>
#include <QKeyEvent>

class Player : public QObject
{
    Q_OBJECT
public:
    explicit Player(QObject *parent = 0);

    QPointF getPos() const;
    void setPos(const QPointF &value);

    double getDir() const;
    void setDir(double value);

    QImage *getBuffer() const;
    void setBuffer(QImage value);

    void setPixelToBuf(int x, int y, int color);

signals:

public slots:
    //void keyEvent (QKeyEvent *event);

private:
    double dir;
    QPointF pos;
    QImage *buffer;

};

#endif // PLAYER_H
