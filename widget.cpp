#include "widget.h"
#include "ui_widget.h"
#include "secondwindow.h"
#include "threewindow.h"

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

void Widget::on_pushButton_clicked()
{
    secondwindow window;
    window.setModal(true);
    window.exec();
}

void Widget::on_pushButton_2_clicked()
{
    threewindow window;
    window.setModal(true);
    window.exec();
}
