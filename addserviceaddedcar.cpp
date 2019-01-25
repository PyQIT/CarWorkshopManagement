#include "addserviceaddedcar.h"
#include "ui_addserviceaddedcar.h"
#include <iostream>
#include "system/client_management.hpp"
#include <mainwindow.h>

using namespace std;

addServiceAddedCar::addServiceAddedCar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addServiceAddedCar)
{
    ui->setupUi(this);
    QPixmap background("C:/Users/Asus/Documents/CWM/CarWorkshopManagement/resources/background.png");
    ui->picture->setPixmap(background);
    QPixmap darktheme("C:/Users/Asus/Documents/CWM/CarWorkshopManagement/resources/darkTheme.png");
    ui->theme1->setPixmap(darktheme);
    MainWindow conn;
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery *qry = new QSqlQuery(conn.mydb);
    char buffor[300];

    qry->prepare("SELECT CARS.ID_CAR AS ID, MARKA,MODEL,NUMER_REJESTRACYJNY,INFORMACJA, IMIE AS IMIĘ, NAZWISKO FROM CARS, PERSON, REPAIR WHERE CARS.ID_PERSON = PERSON.ID_PERSON AND REPAIR.ID_CAR = CARS.ID_CAR");
    qry->exec();
    model->setQuery(*qry);
    ui->tableView->setModel(model);
}

addServiceAddedCar::~addServiceAddedCar()
{
    delete ui;
}

void addServiceAddedCar::on_pushButton_7_clicked()
{
    hide();
    addService addServiceObj;
    addServiceObj.setModal(true);
    addServiceObj.exec();
}

void addServiceAddedCar::on_pushButton_6_clicked()
{
    hide();
    delService delServiceObj;
    delServiceObj.setModal(true);
    delServiceObj.exec();
}

void addServiceAddedCar::on_pushButton_5_clicked()
{
    hide();
    printService printServiceObj;
    printServiceObj.setModal(true);
    printServiceObj.exec();
}

void addServiceAddedCar::on_pushButton_4_clicked()
{
    hide();
    searchService searchServiceObj;
    searchServiceObj.setModal(true);
    searchServiceObj.exec();
}

void addServiceAddedCar::on_pushButton_clicked()
{

    int carID = ui->textEdit_17->toPlainText().toInt();

    QString tmp4 = ui->textEdit_7->toPlainText();
    const QByteArray stringData4 = tmp4.toUtf8();
    char information[100];
    information[qMin(99,stringData4.size())]='\0';
    copy(stringData4.constBegin(),stringData4.constBegin()+qMin(99,stringData4.size()),information);

    double cost = ui->textEdit_6->toPlainText().toDouble();

    char buffor1[300];
    char status[10] = "W trakcie";

    sprintf(buffor1, "insert into REPAIR (INFORMACJA, KOSZT_NAPRAWY, STATUS_ZLECENIA, ID_CAR) values (\"%s\",\"%lf\",\"%s\",\"%d\") ",information, cost, status, carID);

    sql = buffor1;
    execute_sqlite_database();
}
