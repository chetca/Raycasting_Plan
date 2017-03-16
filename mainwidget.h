#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
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


private:
    Ui::mainwidget *ui;

    RaycastingPainter *RP;
    QImage *plScreen;
};

#endif // MAINWIDGET_H
