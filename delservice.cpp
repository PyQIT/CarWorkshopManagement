#include "delservice.h"
#include "ui_delservice.h"
#include <iostream>
#include <system/client_management.hpp>
#include <mainwindow.h>

using namespace  std;

delService::delService(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::delService)
{
    ui->setupUi(this);
    QPixmap background("C:/Users/Asus/Documents/CWM/CarWorkshopManagement/resources/background.png");
    ui->picture->setPixmap(background);
    QPixmap darktheme("C:/Users/Asus/Documents/CWM/CarWorkshopManagement/resources/darkTheme.png");
    ui->theme1->setPixmap(darktheme);
    MainWindow conn;
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery *qry = new QSqlQuery(conn.mydb);

    qry->prepare("SELECT ID, IMIE,NAZWISKO,DATA_URODZENIA,KONTAKT,MARKA,MODEL,NUMER_REJESTRACYJNY,INFORMACJA,KOSZT_NAPRAWY,STATUS_ZLECENIA FROM CARS as a INNER JOIN PERSON as b INNER JOIN REPAIR as c ON a.ID_PERSON=b.ID_PERSON WHERE a.ID_CAR=c.ID_CAR");
    qry->exec();
    model->setQuery(*qry);
    ui->tableView->setModel(model);
}

delService::~delService()
{
    delete ui;
}

void delService::on_pushButton_7_clicked()
{
    hide();
    addService addServiceObj;
    addServiceObj.setModal(true);
    addServiceObj.exec();
}

void delService::on_pushButton_6_clicked()
{
    hide();
    delService delServiceObj;
    delServiceObj.setModal(true);
    delServiceObj.exec();
}

void delService::on_pushButton_5_clicked()
{
    hide();
    printService printServiceObj;
    printServiceObj.setModal(true);
    printServiceObj.exec();
}

void delService::on_pushButton_4_clicked()
{
    hide();
    searchService searchServiceObj;
    searchServiceObj.setModal(true);
    searchServiceObj.exec();
}

void delService::on_lineEdit_editingFinished()
{

}

void delService::on_pushButton_clicked()
{
    int integer_value = ui->lineEdit->text().toInt();
    delete_client_in_database(integer_value);
}
