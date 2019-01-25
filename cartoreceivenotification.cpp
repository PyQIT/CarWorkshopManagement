#include "cartoreceivenotification.h"
#include "ui_cartoreceivenotification.h"

carToReceiveNotification::carToReceiveNotification(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::carToReceiveNotification)
{
    ui->setupUi(this);
}

carToReceiveNotification::~carToReceiveNotification()
{
    delete ui;
}

void carToReceiveNotification::on_pushButton_clicked()
{
    hide();
}
