#include "addserviceregularcustomer.h"
#include "ui_addserviceregularcustomer.h"
#include <iostream>
#include "system/client_management.hpp"
#include <mainwindow.h>

using namespace std;

addServiceRegularCustomer::addServiceRegularCustomer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addServiceRegularCustomer)
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

    qry->prepare("SELECT ID_PERSON, IMIE,NAZWISKO,DATA_URODZENIA,KONTAKT FROM PERSON");
    qry->exec();
    model->setQuery(*qry);
    ui->tableView->setModel(model);
}

addServiceRegularCustomer::~addServiceRegularCustomer()
{
    delete ui;
}

void addServiceRegularCustomer::on_pushButton_7_clicked()
{
    hide();
    addService addServiceObj;
    addServiceObj.setModal(true);
    addServiceObj.exec();
}

void addServiceRegularCustomer::on_pushButton_6_clicked()
{
    hide();
    delService delServiceObj;
    delServiceObj.setModal(true);
    delServiceObj.exec();
}

void addServiceRegularCustomer::on_pushButton_5_clicked()
{
    hide();
    printService printServiceObj;
    printServiceObj.setModal(true);
    printServiceObj.exec();
}

void addServiceRegularCustomer::on_pushButton_4_clicked()
{
    hide();
    searchService searchServiceObj;
    searchServiceObj.setModal(true);
    searchServiceObj.exec();
}

void addServiceRegularCustomer::on_radioButton_2_toggled(bool checked)
{
    if(checked){
        hide();
        addServiceAddedCar addServiceAddedCarObj;
        addServiceAddedCarObj.setModal(true);
        addServiceAddedCarObj.exec();
    }
}

class Input{
public:
    static char *information1;
    static double cost1;
};

char* Input::information1;
double Input::cost1 = 0.0;

void add_order1(int not1){
    char buffor1[300];
    char status[10] = "W trakcie";
    Input a;

    sprintf(buffor1, "insert into REPAIR (INFORMACJA, KOSZT_NAPRAWY, STATUS_ZLECENIA, ID_CAR) values (\"%s\",\"%lf\",\"%s\",\"%d\") ",a.information1, a.cost1,status,not1);

    sql = buffor1;
    execute_sqlite_database();
}

static int callback_ID2(void *data, int argc, char **argv, char **azColName){

    int i;
    char notification[20];
    int not1 = 0;

    for(i = 0; i<argc; i++){
        sprintf(notification, "%s", argv[i] ? argv[i] : "NULL");
    }

    not1 = atoi(notification);
    add_order1(not1);

    return 0;
}

void execute_sqlite_database_ID2(void){

    int rc;
    char *errmsg;
    const char* data = " ";

    rc = sqlite3_exec(database, sql, callback_ID2, (void*)data, &errmsg);

    if( rc != SQLITE_OK ) {
        fprintf(stderr, "SQL error: %s\n", errmsg);
        sqlite3_free(errmsg);
    }
}

void addServiceRegularCustomer::on_pushButton_clicked()
{
    int ID = ui->textEdit_18->toPlainText().toInt();

    QString tmp1 = ui->textEdit_4->toPlainText();
    const QByteArray stringData1 = tmp1.toUtf8();
    char mark[100];
    mark[qMin(99,stringData1.size())]='\0';
    copy(stringData1.constBegin(),stringData1.constBegin()+qMin(99,stringData1.size()),mark);

    QString tmp2 = ui->textEdit_5->toPlainText();
    const QByteArray stringData2 = tmp2.toUtf8();
    char model[100];
    model[qMin(99,stringData2.size())]='\0';
    copy(stringData2.constBegin(),stringData2.constBegin()+qMin(99,stringData2.size()),model);

    QString tmp3 = ui->textEdit_6->toPlainText();
    const QByteArray stringData3 = tmp3.toUtf8();
    char plate[100];
    plate[qMin(99,stringData3.size())]='\0';
    copy(stringData3.constBegin(),stringData3.constBegin()+qMin(99,stringData3.size()),plate);

    QString tmp4 = ui->textEdit_7->toPlainText();
    const QByteArray stringData4 = tmp4.toUtf8();
    char information[100];
    information[qMin(99,stringData4.size())]='\0';
    copy(stringData4.constBegin(),stringData4.constBegin()+qMin(99,stringData4.size()),information);
    Input::information1 = information;

    double cost = ui->textEdit_3->toPlainText().toDouble();
    Input::cost1 = cost;

    //select_stmt("SELECT ID_PERSON, IMIE,NAZWISKO,DATA_URODZENIA,KONTAKT FROM PERSON");

    char buffor[300];
    char buffor2[300];

    sprintf(buffor, "insert into CARS (MARKA, MODEL, NUMER_REJESTRACYJNY, ID_PERSON) values (\"%s\",\"%s\",\"%s\",\"%d\")",mark, model, plate, ID);

    sql = buffor;
    execute_sqlite_database();

    sprintf(buffor2, "SELECT (ID_CAR) FROM CARS WHERE ID_CAR=(SELECT max(ID_CAR) FROM CARS)");
    sql = buffor2;
    execute_sqlite_database_ID2();

}
