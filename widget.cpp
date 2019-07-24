#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::ChangeMoney(int n){

        money += n;
        ui->lcdNumber->display(money);
        if(money >= 100) ui->pbCoffee->setEnabled(true);
        if(money >= 150) ui->pbTea->setEnabled(true);
        if(money >= 200) ui->pbCoke->setEnabled(true);
        if(money < 200) ui->pbCoke->setEnabled(false);
        if(money < 150) ui->pbTea->setEnabled(false);
        if(money < 100) ui->pbCoffee->setEnabled(false);

}
void Widget::on_pb10_clicked()
{
    ChangeMoney(10);
}

void Widget::on_pb50_clicked()
{
    ChangeMoney(50);
}

void Widget::on_pb100_clicked()
{
    ChangeMoney(100);
}

void Widget::on_pb500_clicked()
{
    ChangeMoney(500);
}

void Widget::on_pbCoffee_clicked()
{
    ChangeMoney(-100);

}

void Widget::on_pbTea_clicked()
{
    ChangeMoney(-150);
}

void Widget::on_pbCoke_clicked()
{
    ChangeMoney(-200);
}


void Widget::on_pbReset_clicked()
{
    cnt500 = money / 500;
    money %= 500;
    cnt100 = money / 100;
    money %= 100;
    cnt50 = money / 50;
    money %= 50;
    cnt10 = money / 10;
    money %= 10;
    QMessageBox msg;
    QString cnt = QString("500 = %1, 100 = %2, 50 = %3, 10 = %4 ").arg(cnt500).arg(cnt100).arg(cnt50).arg(cnt10);
    msg.information(nullptr, "Reset", cnt);
    ui->lcdNumber->display(money);
}
