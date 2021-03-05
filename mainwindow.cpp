#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QTimer>
#include<QDate>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);                      //to show time
    QTimer *timer=new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(showTime()));    //signals and slots     (Object1,Signal1 , Object2,Slot1)
    timer->start();

    QDate date=QDate::currentDate();   // show  current date
    QString datetext=date.toString();
    ui->date->setText(datetext);
}

void MainWindow:: showTime()
{

QTime time=QTime::currentTime();

QString time_text=time.toString("hh : mm : ss");   // time

ui->Digital_clock->setText(time_text);

}

MainWindow::~MainWindow()
{
    delete ui;
}

