#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QPainter>
#include <QtCore>
#include <QApplication>
#include <QDesktopWidget>
#include <QTime>
#include <QLabel>
#include <QGraphicsView>
#include <QSet>

#include "raycastingpainter.h"
#include "minimapplayer.h"
#include "mygeom.h"

namespace Ui {
class mainwidget;
}

class mainwidget : public QWidget
{
    Q_OBJECT

public:
    explicit mainwidget(QWidget *parent = 0);
    ~mainwidget();

    void paintEvent(QPaintEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void timerEvent(QTimerEvent *event);
    const QPoint screenCentre = QApplication::desktop()->screenGeometry().center();


signals:
    void keyPressed(QKeyEvent *event);

private:
    Ui::mainwidget *ui;
    QBasicTimer ticker;

    QTime watch;

    QLabel *fps;
    RaycastingPainter *RP;
    QRectF *targetP;
    QGraphicsView *miniMap;
    int FPS;
    MiniMapPlayer *plRect;
    QGraphicsScene *mmap;
};

#endif // MAINWIDGET_H
