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

    plScreen = new QImage (WIDTH, HEIGHT, QImage::Format_ARGB32);

    fps = new QLabel(this);
    fps->setGeometry(0,0,100,30);
    fps->setFont(QFont("",22));
    FPS = 0;
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


    RP->player->update(time);
    RP->updateScene(time);



    if (++k == 10) {
        FPS = 1000*k/tk;
        tk=0;
        k=0;
    }

    this->update();
}
