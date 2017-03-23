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
    RP->paint(RP->player->getPos(), QPointF(5,0));
    RP->show();

    ticker.start(1, this);

    //connect(this, SIGNAL(keyPressed(QKeyEvent *)), RP, SLOT(keyPressEvent(QKeyEvent *)));

    setAttribute(Qt::WA_OpaquePaintEvent, true);
    setMouseTracking(1);

    //gameScreen = new GameScreen(RP->getRbuffer(), this);
    //gameScreen->setGeometry(0,0,800,600);
}

mainwidget::~mainwidget()
{
    delete ui;
}

void mainwidget::paintEvent(QPaintEvent *event)
{
    static int stt;
    qDebug() << "paintEvent started :" << stt++;
    QPainter painter(this);
    painter.setCompositionMode(QPainter::CompositionMode_Source);
    painter.drawImage(event->rect(),(RP->getRbuffer()), event->rect());
}

//void mainwidget::keyPressEvent(QKeyEvent *event)
//{
//    QPointF dir (10*cos(RP->player->getDir()),10*sin(RP->player->getDir()));
//    QPaintEvent *a = new QPaintEvent(QRect(0,0,800,600));

//    emit(keyPressed(event));
//}




void mainwidget::timerEvent(QTimerEvent *) {
    RP->player->setDir(RP->player->getDir()-(QCursor::pos().x()-screenCentre.x()));
    //gameScreen->setImg(RP->getRbuffer());
    QCursor::setPos(screenCentre);
    this->update();
}

void mainwidget::update()
{
    QPaintEvent aa = QPaintEvent(QRect());
    //gameScreen->paintEvent(&aa);
}
