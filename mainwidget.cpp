#include "mainwidget.h"
#include "ui_mainwidget.h"

#include <QLabel>
#include <QDebug>

mainwidget::mainwidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mainwidget)
{
    ui->setupUi(this);

    RP = new RaycastingPainter(this);

    this->setGeometry(0,0,RP->WIDTH,RP->HEIGHT);

    RP->setGeometry(10,10,RP->WIDTH,RP->HEIGHT);
    RP->paint(this, RP->player->getPos(), QPointF(5,0));
    RP->show();

    targetP = new QRectF(0,0,800,600);

//    plScreen = new QImage (*(RP->player->getBuffer()));
//    QLabel *sc = new QLabel(this);

}

mainwidget::~mainwidget()
{
    delete ui;
}

void mainwidget::paintEvent(QPaintEvent *)
{
    static int stt;
    qDebug() << "paintEvent started :" << stt++;
    QPainter painter(this);
    QPointF tP(0,0);
    painter.drawImage(tP,(RP->getRbuffer()));
}
