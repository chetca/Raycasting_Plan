#ifndef GAMESCREEN_H
#define GAMESCREEN_H

#include <QWidget>
#include <QImage>
#include <QPainter>
#include <QPaintEvent>

class GameScreen : public QWidget
{
public:
    GameScreen(QImage img, QWidget *parent = 0);

//    void paintEvent(QPaintEvent *event);
//    void setImg(QImage img);

private:
    QImage a;
};

#endif // GAMESCREEN_H
