#include "mainwidget.h"
#include "ui_mainwidget.h"

mainwidget::mainwidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mainwidget)
{
    ui->setupUi(this);

    RP = new RaycastingPainter(this);


    RP->setGeometry(10,10,640,480);
    RP->show();
}

mainwidget::~mainwidget()
{
    delete ui;
}
