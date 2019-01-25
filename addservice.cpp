#include "addservice.h"
#include "ui_addservice.h"
#include <iostream>
#include "system/client_management.hpp"

using namespace std;

addService::addService(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addService)
{
    ui->setupUi(this);
    QPixmap background("C:/Users/Asus/Documents/CWM/CarWorkshopManagement/resources/background.png");
    ui->picture->setPixmap(background);
    QPixmap darktheme("C:/Users/Asus/Documents/CWM/CarWorkshopManagement/resources/darkTheme.png");
    ui->theme1->setPixmap(darktheme);
}

addService::~addService()
{
    delete ui;
}

void addService::on_pushButton_7_clicked()
{
    hide();
    addService addServiceObj;
    addServiceObj.setModal(true);
    addServiceObj.exec();
}

void addService::on_pushButton_6_clicked()
{
    hide();
    delService delServiceObj;
    delServiceObj.setModal(true);
    delServiceObj.exec();
}

void addService::on_pushButton_5_clicked()
{
    hide();
    printService printServiceObj;
    printServiceObj.setModal(true);
    printServiceObj.exec();
}

void addService::on_pushButton_4_clicked()
{
    hide();
    searchService searchServiceObj;
    searchServiceObj.setModal(true);
    searchServiceObj.exec();
}

void addService::on_radioButton_2_toggled(bool checked)
{
    if(checked){
        hide();
        addServiceRegularCustomer addServiceRegularCustomerObj;
        addServiceRegularCustomerObj.setModal(true);
        addServiceRegularCustomerObj.exec();
    }

}

class Input{
public:
    static char *name;
    static char *surname;
    static char *birthDate;
    static char *contact;
    static char *plate;
    static char *model;
    static char *mark;
    static char *information;
    static double cost;
 /*   void setName(char *n){
        strcpy(name,n);
        cout << name;
    }

    char* getName(){
        return name;
    }
    void setSurname(char *n){
        strcpy(surname,n);
    }

    char* getSurname(){
        return surname;
    }

    void setBirthDate(char *n){
        strcpy(birthDate,n);
    }

    char* getBirthDate(){
        return birthDate;
    }

    void setContact(char *n){
        strcpy(contact,n);
    }

    char* getContact(){
        return contact;
    }

    void setPlate(char *n){
        strcpy(plate,n);
    }

    char* getPlate(){
        return plate;
    }

    void setModel(char *n){
        strcpy(model,n);
    }

    char* getModel(){
        return model;
    }

    void setMark(char *n){
        strcpy(mark,n);
    }

    char* getMark(){
        return mark;
    }

    void setInformation(char *n){
        strcpy(information,n);
    }

    char* getInformation(){
        return information;
    }

    void setCost(double n){
        cost = n;
    }

    double getCost(){
        return cost;
    }*/
};

char* Input::name;
char* Input::surname;
char* Input::birthDate;
char* Input::contact;
char* Input::mark;
char* Input::model;
char* Input::plate;
char* Input::information;
double Input::cost = 0.0;

void add_order(int not1){
    char buffor1[300];
    char status[10] = "W trakcie";
    Input a;

    sprintf(buffor1, "insert into REPAIR (INFORMACJA, KOSZT_NAPRAWY, STATUS_ZLECENIA, ID_CAR) values (\"%s\",\"%lf\",\"%s\",\"%d\") ",a.information, a.cost,status,not1);

    sql = buffor1;
    execute_sqlite_database();
}

static int callback_ID1(void *data, int argc, char **argv, char **azColName){

    int i;
    char notification[20];
    int not1 = 0;

    for(i = 0; i<argc; i++){
        sprintf(notification, "%s", argv[i] ? argv[i] : "NULL");
    }

    not1 = atoi(notification);
    add_order(not1);

    return 0;
}

void execute_sqlite_database_ID1(void){

    int rc;
    char *errmsg;
    const char* data = " ";

    rc = sqlite3_exec(database, sql, callback_ID1, (void*)data, &errmsg);

    if( rc != SQLITE_OK ) {
        fprintf(stderr, "SQL error: %s\n", errmsg);
        sqlite3_free(errmsg);
    }
}

void add_car(int not1){
    char buffor1[300];
    Input a;
    sprintf(buffor1, "insert into CARS (MARKA, MODEL, NUMER_REJESTRACYJNY, ID_PERSON) values (\"%s\",\"%s\",\"%s\",\"%d\") ",a.mark, a.model, a.plate,not1);

    sql = buffor1;
    execute_sqlite_database();
}

static int callback_ID_PERSON1(void *data, int argc, char **argv, char **azColName){

    int i;
    char notification[20];
    int not1 = 0;
    char buffor2[300];

    for(i = 0; i<argc; i++){
        sprintf(notification, "%s", argv[i] ? argv[i] : "NULL");
    }

    not1 = atoi(notification);
    add_car(not1);
    sprintf(buffor2, "SELECT (ID_CAR) FROM CARS WHERE ID_CAR=(SELECT max(ID_CAR) FROM CARS)");
    sql = buffor2;
    execute_sqlite_database_ID1();

    return 0;
}

void execute_sqlite_database_ID_PERSON1(void){

    int rc;
    char *errmsg;
    const char* data = " ";

    rc = sqlite3_exec(database, sql, callback_ID_PERSON1, (void*)data, &errmsg);

    if( rc != SQLITE_OK ) {
        fprintf(stderr, "SQL error: %s\n", errmsg);
        sqlite3_free(errmsg);
    }
}

void addService::on_pushButton_clicked()
{

    char name[100];
    char surname[100];
    char birthDate[100];
    char contact[100];
    char plate[100];
    char model[100];
    char mark[100];
    char information[100];
    double cost;

    QString tmp = ui->textEdit->toPlainText();
    const QByteArray stringData = tmp.toUtf8();
    name[qMin(99,stringData.size())]='\0';
    copy(stringData.constBegin(),stringData.constBegin()+qMin(99,stringData.size()),name);
    Input::name = name;

    QString tmp1 = ui->textEdit_2->toPlainText();
    const QByteArray stringData1 = tmp1.toUtf8();
    surname[qMin(99,stringData1.size())]='\0';
    copy(stringData1.constBegin(),stringData1.constBegin()+qMin(99,stringData1.size()),surname);
    Input::surname = surname;

    QString tmp2 = ui->textEdit_8->toPlainText();
    const QByteArray stringData2 = tmp2.toUtf8();
    birthDate[qMin(99,stringData2.size())]='\0';
    copy(stringData2.constBegin(),stringData2.constBegin()+qMin(99,stringData2.size()),birthDate);
    Input::birthDate = birthDate;

    QString tmp3 = ui->textEdit_9->toPlainText();
    const QByteArray stringData3 = tmp3.toUtf8();
    contact[qMin(99,stringData3.size())]='\0';
    copy(stringData3.constBegin(),stringData3.constBegin()+qMin(99,stringData3.size()),contact);
    Input::contact = contact;

    QString tmp4 = ui->textEdit_4->toPlainText();
    const QByteArray stringData4 = tmp4.toUtf8();
    mark[qMin(99,stringData4.size())]='\0';
    copy(stringData4.constBegin(),stringData4.constBegin()+qMin(99,stringData4.size()),mark);
    Input::mark = mark;

    QString tmp5 = ui->textEdit_5->toPlainText();
    const QByteArray stringData5 = tmp5.toUtf8();
    model[qMin(99,stringData5.size())]='\0';
    copy(stringData5.constBegin(),stringData5.constBegin()+qMin(99,stringData5.size()),model);
    Input::model = model;

    QString tmp6 = ui->textEdit_6->toPlainText();
    const QByteArray stringData6 = tmp6.toUtf8();
    plate[qMin(99,stringData6.size())]='\0';
    copy(stringData6.constBegin(),stringData6.constBegin()+qMin(99,stringData6.size()),plate);
    Input::plate = plate;

    cost = ui->textEdit_3->toPlainText().toDouble();
    Input::cost = cost;

    QString tmp8 = ui->textEdit_7->toPlainText();
    const QByteArray stringData8 = tmp8.toUtf8();
    information[qMin(99,stringData8.size())]='\0';
    copy(stringData8.constBegin(),stringData8.constBegin()+qMin(99,stringData8.size()),information);
    Input::information = information;

    char buffor[300];
    char buffor2[300];

    sprintf(buffor, "insert into PERSON (IMIE, NAZWISKO, DATA_URODZENIA, KONTAKT) values (\"%s\",\"%s\",\"%s\",\"%s\") ",name, surname, birthDate, contact);

    sql = buffor;
    execute_sqlite_database();

    sprintf(buffor2, "SELECT (ID_PERSON) FROM PERSON WHERE ID_PERSON=(SELECT max(ID_PERSON) FROM PERSON)");
    sql = buffor2;


    execute_sqlite_database_ID_PERSON1();
}
