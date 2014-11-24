#include <QFileDialog>
#include <QMessageBox>
#include <QStringList>
#include <QTextCodec>
#include <QDebug>
#include "mojeokno.h"
#include "ui_mojeokno.h"

mojeokno::mojeokno(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mojeokno)
{
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
    ui->setupUi(this);
    a1 = new QTimer(this);
    connect(ui->start, SIGNAL(clicked()), this, SLOT(start()));
    connect(a1, SIGNAL(timeout()), this, SLOT(ruch()));
    a2 = new QTimer(this);
    connect(a2, SIGNAL(timeout()), this, SLOT(nowy()));
    a=220;
    b=60;
    h=360;
}
mojeokno::~mojeokno()
{
    delete ui;
}
void mojeokno::start()
{
    ruch();
   // a2->start(1000);
}

void mojeokno::ruch()
{
    b++;
    if(b==h)
    {
        b=60;
    }
    ui->thing->setGeometry(a, b, 100, 40);
    a1->start(20);
}
void mojeokno::nowy()
{
// a2->start(1000);
}

void mojeokno::koniec()
{

}
