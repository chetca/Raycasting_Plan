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

    this->setGeometry(0, 0, WIDTH, HEIGHT);

    RP->setGeometry(0, 0, WIDTH, HEIGHT);
    RP->paint();
    RP->show();

    ticker.start(10, this);
    watch.start();

    setAttribute(Qt::WA_OpaquePaintEvent, true);
    setMouseTracking(1);

    fps = new QLabel(this);
    fps->setGeometry(this->width()-80,0,100,30);
    fps->setFont(QFont("",22));
    FPS = 0;

    miniMap = new QGraphicsView(this);

    mmap = new QGraphicsScene();
    miniMap->setScene(mmap);
    miniMap->setGeometry(0,0,500,200);

    for (int i=0; i<RP->scene()->getMapSegment().size(); i++) {
        mmap->addLine(RP->scene()->getMapSegment(i).A().x(),
                      RP->scene()->getMapSegment(i).A().y(),
                      RP->scene()->getMapSegment(i).B().x(),
                      RP->scene()->getMapSegment(i).B().y());
    }

//    plRect = mmap->addRect(RP->player->getPos().x()-2,
//                           RP->player->getPos().y()-2,4,4,QPen(QColor(255,0,0)));
    plRect = new MiniMapPlayer();
    mmap->addItem(plRect);
    plRect->setPos(RP->player->getPos().x()-4.5,
                   RP->player->getPos().y()-4.5);
    plRect->rotate();
}

mainwidget::~mainwidget()
{
    delete ui;
}

void mainwidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setCompositionMode(QPainter::CompositionMode_Source);
    painter.drawImage(event->rect(), RP->rbuffer, event->rect());
}

void mainwidget::keyReleaseEvent(QKeyEvent *event)
{    
    event->accept();
    if (event->key() == Qt::Key_W ||
        event->key() == Qt::Key_A ||
        event->key() == Qt::Key_S ||
        event->key() == Qt::Key_D) {
        RP->player->setDX(0);
        RP->player->setDY(0);
    }
    //emit(keyPressed(event));
}

void mainwidget::keyPressEvent(QKeyEvent *event)
{
    event->accept();
    if (event->key() == Qt::Key_W) {
        RP->player->setDX(cos(RP->player->getDir()));
        RP->player->setDY(sin(RP->player->getDir()));


    }

    if (event->key() == Qt::Key_S) {
        RP->player->setDX(-cos(RP->player->getDir()));
        RP->player->setDY(-sin(RP->player->getDir()));


    }

    if (event->key() == Qt::Key_D) {
        RP->player->setDX(sin(RP->player->getDir()));
        RP->player->setDY(-cos(RP->player->getDir()));


    }

    if (event->key() == Qt::Key_A) {
        RP->player->setDX(-sin(RP->player->getDir()));
        RP->player->setDY(cos(RP->player->getDir()));

    }

    if (event->key() == Qt::Key_Escape) {
        this->close();
    }
}

void mainwidget::timerEvent(QTimerEvent *) {
    double time = watch.elapsed();

    static double k;
    static double tk;

    tk += time;

    watch.start();

    fps->setText(QString::number(FPS));

    RP->player->setDDIR((QCursor::pos().x()-screenCentre.x()));    

    QCursor::setPos(screenCentre);
    RP->paint();

    plRect->dir += (QCursor::pos().x()-screenCentre.x())*time;
    plRect->rotate();
    qDebug() << "time = " << time;

    RP->player->update(time);
    RP->updateScene(time);

//    if (!(mmap->collidingItems(plRect)).empty()) {
//        RP->player->setDX(0);
//        RP->player->setDY(0);
//        RP->player->back(time);

//    }

    plRect->setPos(RP->player->getPos() - QPointF (4.5,4.5));

    if (++k == 5) {
        FPS = 1000*k/tk;
        tk=0;
        k=0;
    }

    this->update();
}
