#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QPainter>

#include "raycastingpainter.h"

namespace Ui {
class mainwidget;
}

class mainwidget : public QWidget
{
    Q_OBJECT

public:
    explicit mainwidget(QWidget *parent = 0);
    ~mainwidget();

    void paintEvent(QPaintEvent *);

private:
    Ui::mainwidget *ui;

    RaycastingPainter *RP;
    QImage *plScreen;
    QRectF *targetP;
};

#endif // MAINWIDGET_H
