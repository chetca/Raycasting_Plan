#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QPainter>
#include <QtCore>
#include <QApplication>
#include <QDesktopWidget>

#include "raycastingpainter.h"
#include "gamescreen.h"

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
    void timerEvent(QTimerEvent *event);
    void update();
    const QPoint screenCentre = QApplication::desktop()->screenGeometry().center();

signals:
    void keyPressed(QKeyEvent *event);

private:
    Ui::mainwidget *ui;
    QBasicTimer ticker;

    RaycastingPainter *RP;
    GameScreen *gameScreen;
    QImage *plScreen;
    QRectF *targetP;
};

#endif // MAINWIDGET_H
