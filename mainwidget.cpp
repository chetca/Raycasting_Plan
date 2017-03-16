#include "mainwidget.h"
#include "ui_mainwidget.h"

#include <QLabel>

mainwidget::mainwidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mainwidget)
{
    ui->setupUi(this);

    RP = new RaycastingPainter(this);

    this->setGeometry(0,0,RP->WIDTH,RP->HEIGHT);

    RP->setGeometry(10,10,RP->WIDTH,RP->HEIGHT);
    RP->show();
    plScreen = new QImage (*(RP->player->getBuffer()));
    QLabel *sc = new QLabel(this);

}

mainwidget::~mainwidget()
{
    delete ui;
}
