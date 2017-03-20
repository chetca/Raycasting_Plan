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

signals:

public slots:

private:
    int WIDTH = 800;
    int HEIGHT = 600;
    double dir;
    QPointF pos;
};

#endif // PLAYER_H
