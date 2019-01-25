#include "printservice.h"
#include "ui_printservice.h"
#include "system/client_management.hpp"
#include <mainwindow.h>

printService::printService(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::printService)
{
    ui->setupUi(this);
    QPixmap background("C:/Users/Asus/Documents/CWM/CarWorkshopManagement/resources/background.png");
    ui->picture->setPixmap(background);
    QPixmap darktheme("C:/Users/Asus/Documents/CWM/CarWorkshopManagement/resources/darkTheme.png");
    ui->theme1->setPixmap(darktheme);
    MainWindow conn;
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery *qry = new QSqlQuery(conn.mydb);
    char buffer[300];
    sprintf(buffer, "SELECT ID, IMIE,NAZWISKO,DATA_URODZENIA,KONTAKT,MARKA,MODEL,NUMER_REJESTRACYJNY,INFORMACJA,KOSZT_NAPRAWY,STATUS_ZLECENIA FROM CARS as a INNER JOIN PERSON as b INNER JOIN REPAIR as c ON a.ID_PERSON=b.ID_PERSON WHERE a.ID_CAR=c.ID_CAR");
    qry->prepare(buffer);
    qry->exec();
    model->setQuery(*qry);
    ui->tableView->setModel(model);
}

printService::~printService()
{
    delete ui;
}

void printService::on_pushButton_7_clicked()
{
    hide();
    addService addServiceObj;
    addServiceObj.setModal(true);
    addServiceObj.exec();
}

void printService::on_pushButton_6_clicked()
{
    hide();
    delService delServiceObj;
    delServiceObj.setModal(true);
    delServiceObj.exec();
}

void printService::on_pushButton_5_clicked()
{
    hide();
    printService printServiceObj;
    printServiceObj.setModal(true);
    printServiceObj.exec();
}

void printService::on_pushButton_4_clicked()
{
    hide();
    searchService searchServiceObj;
    searchServiceObj.setModal(true);
    searchServiceObj.exec();
}

void printService::on_pushButton_clicked()
{
    int print = ui->comboBox->currentIndex();
    int sort = ui->comboBox_2->currentIndex();
    int change = ui->comboBox_3->currentIndex();
    int ID = ui->lineEdit->text().toInt();

    MainWindow conn;
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery *qry = new QSqlQuery(conn.mydb);

    if(change > 0){
        if(change == 1){
            char buffor[300];

            sprintf(buffor, "UPDATE REPAIR SET STATUS_ZLECENIA = 'W trakcie' WHERE ID =  \"%d\"",
                    ID);

            sql = buffor;
            execute_sqlite_database();
        }
        if(change == 2){
            char buffor[300];

            sprintf(buffor, "UPDATE REPAIR SET STATUS_ZLECENIA = 'Do odebrania' WHERE ID =  \"%d\"",
                    ID);

            sql = buffor;
            execute_sqlite_database();
        }
        if(change == 3){
            char buffor[300];

            sprintf(buffor, "UPDATE REPAIR SET STATUS_ZLECENIA = 'Zakonczone' WHERE ID =  \"%d\"",
                    ID);

            sql = buffor;
            execute_sqlite_database();
        }
    }
    else{
            char buffer[300];

            if(print == 0 && sort == 0)
                sprintf(buffer, "SELECT ID, IMIE,NAZWISKO,DATA_URODZENIA,KONTAKT,MARKA,MODEL,NUMER_REJESTRACYJNY,INFORMACJA,KOSZT_NAPRAWY,STATUS_ZLECENIA FROM CARS as a INNER JOIN PERSON as b INNER JOIN REPAIR as c ON a.ID_PERSON=b.ID_PERSON WHERE a.ID_CAR=c.ID_CAR");
            qry->prepare(buffer);
            qry->exec();
            model->setQuery(*qry);
            ui->tableView->setModel(model);
            if(print == 0 && sort == 1){
                sprintf(buffer, "SELECT ID, IMIE,NAZWISKO,DATA_URODZENIA,KONTAKT,MARKA,MODEL,NUMER_REJESTRACYJNY,INFORMACJA,KOSZT_NAPRAWY,STATUS_ZLECENIA FROM CARS as a INNER JOIN PERSON as b INNER JOIN REPAIR as c ON a.ID_PERSON=b.ID_PERSON WHERE a.ID_CAR=c.ID_CAR ORDER BY IMIE");
                qry->prepare(buffer);
                qry->exec();
                model->setQuery(*qry);
                ui->tableView->setModel(model);
            }
            if(print == 0 && sort == 2){
                sprintf(buffer, "SELECT ID, IMIE,NAZWISKO,DATA_URODZENIA,KONTAKT,MARKA,MODEL,NUMER_REJESTRACYJNY,INFORMACJA,KOSZT_NAPRAWY,STATUS_ZLECENIA FROM CARS as a INNER JOIN PERSON as b INNER JOIN REPAIR as c ON a.ID_PERSON=b.ID_PERSON WHERE a.ID_CAR=c.ID_CAR ORDER BY NAZWISKO");
                qry->prepare(buffer);
                qry->exec();
                model->setQuery(*qry);
                ui->tableView->setModel(model);
            }
            if(print == 0 && sort == 3){
                sprintf(buffer, "SELECT ID, IMIE,NAZWISKO,DATA_URODZENIA,KONTAKT,MARKA,MODEL,NUMER_REJESTRACYJNY,INFORMACJA,KOSZT_NAPRAWY,STATUS_ZLECENIA FROM CARS as a INNER JOIN PERSON as b INNER JOIN REPAIR as c ON a.ID_PERSON=b.ID_PERSON WHERE a.ID_CAR=c.ID_CAR ORDER BY MARKA");
                qry->prepare(buffer);
                qry->exec();
                model->setQuery(*qry);
                ui->tableView->setModel(model);
            }
            if(print == 0 && sort == 4){
                sprintf(buffer, "SELECT ID, IMIE,NAZWISKO,DATA_URODZENIA,KONTAKT,MARKA,MODEL,NUMER_REJESTRACYJNY,INFORMACJA,KOSZT_NAPRAWY,STATUS_ZLECENIA FROM CARS as a INNER JOIN PERSON as b INNER JOIN REPAIR as c ON a.ID_PERSON=b.ID_PERSON WHERE a.ID_CAR=c.ID_CAR ORDER BY NUMER_REJESTRACYJNY");
                qry->prepare(buffer);
                qry->exec();
                model->setQuery(*qry);
                ui->tableView->setModel(model);
            }
            if(print == 0 && sort == 5){
                sprintf(buffer, "SELECT ID, IMIE,NAZWISKO,DATA_URODZENIA,KONTAKT,MARKA,MODEL,NUMER_REJESTRACYJNY,INFORMACJA,KOSZT_NAPRAWY,STATUS_ZLECENIA FROM CARS as a INNER JOIN PERSON as b INNER JOIN REPAIR as c ON a.ID_PERSON=b.ID_PERSON WHERE a.ID_CAR=c.ID_CAR ORDER BY STATUS_ZLECENIA");
                qry->prepare(buffer);
                qry->exec();
                model->setQuery(*qry);
                ui->tableView->setModel(model);
            }
            if(print == 1 && sort == 0){
                sprintf(buffer, "SELECT ID, IMIE,NAZWISKO,DATA_URODZENIA,KONTAKT,MARKA,MODEL,NUMER_REJESTRACYJNY,INFORMACJA,KOSZT_NAPRAWY,STATUS_ZLECENIA FROM CARS as a INNER JOIN PERSON as b INNER JOIN REPAIR as c ON a.ID_PERSON=b.ID_PERSON WHERE a.ID_CAR=c.ID_CAR AND STATUS_ZLECENIA = \"W trakcie\"");
                qry->prepare(buffer);
                qry->exec();
                model->setQuery(*qry);
                ui->tableView->setModel(model);
            }
            if(print == 2 && sort == 0){
                sprintf(buffer, "SELECT ID, IMIE,NAZWISKO,DATA_URODZENIA,KONTAKT,MARKA,MODEL,NUMER_REJESTRACYJNY,INFORMACJA,KOSZT_NAPRAWY,STATUS_ZLECENIA FROM CARS as a INNER JOIN PERSON as b INNER JOIN REPAIR as c ON a.ID_PERSON=b.ID_PERSON WHERE a.ID_CAR=c.ID_CAR AND STATUS_ZLECENIA = \"Do odebrania\"");
                qry->prepare(buffer);
                qry->exec();
                model->setQuery(*qry);
                ui->tableView->setModel(model);
            }
            if(print == 3 && sort == 0){
                sprintf(buffer, "SELECT ID, IMIE,NAZWISKO,DATA_URODZENIA,KONTAKT,MARKA,MODEL,NUMER_REJESTRACYJNY,INFORMACJA,KOSZT_NAPRAWY,STATUS_ZLECENIA FROM CARS as a INNER JOIN PERSON as b INNER JOIN REPAIR as c ON a.ID_PERSON=b.ID_PERSON WHERE a.ID_CAR=c.ID_CAR AND STATUS_ZLECENIA = \"Zakonczone\"");
                qry->prepare(buffer);
                qry->exec();
                model->setQuery(*qry);
                ui->tableView->setModel(model);
            }
            if(print == 1 && sort == 1){
                sprintf(buffer, "SELECT ID, IMIE,NAZWISKO,DATA_URODZENIA,KONTAKT,MARKA,MODEL,NUMER_REJESTRACYJNY,INFORMACJA,KOSZT_NAPRAWY,STATUS_ZLECENIA FROM CARS as a INNER JOIN PERSON as b INNER JOIN REPAIR as c ON a.ID_PERSON=b.ID_PERSON WHERE a.ID_CAR=c.ID_CAR AND STATUS_ZLECENIA = \"W trakcie\" ORDER BY IMIE");
                qry->prepare(buffer);
                qry->exec();
                model->setQuery(*qry);
                ui->tableView->setModel(model);
            }
            if(print == 1 && sort == 2){
                sprintf(buffer, "SELECT ID, IMIE,NAZWISKO,DATA_URODZENIA,KONTAKT,MARKA,MODEL,NUMER_REJESTRACYJNY,INFORMACJA,KOSZT_NAPRAWY,STATUS_ZLECENIA FROM CARS as a INNER JOIN PERSON as b INNER JOIN REPAIR as c ON a.ID_PERSON=b.ID_PERSON WHERE a.ID_CAR=c.ID_CAR AND STATUS_ZLECENIA = \"W trakcie\" ORDER BY NAZWISKO");
                qry->prepare(buffer);
                qry->exec();
                model->setQuery(*qry);
                ui->tableView->setModel(model);
            }
            if(print == 1 && sort == 3){
                sprintf(buffer, "SELECT ID, IMIE,NAZWISKO,DATA_URODZENIA,KONTAKT,MARKA,MODEL,NUMER_REJESTRACYJNY,INFORMACJA,KOSZT_NAPRAWY,STATUS_ZLECENIA FROM CARS as a INNER JOIN PERSON as b INNER JOIN REPAIR as c ON a.ID_PERSON=b.ID_PERSON WHERE a.ID_CAR=c.ID_CAR AND STATUS_ZLECENIA = \"W trakcie\" ORDER BY MARKA");
                qry->prepare(buffer);
                qry->exec();
                model->setQuery(*qry);
                ui->tableView->setModel(model);
            }
            if(print == 1 && sort == 4){
                sprintf(buffer, "SELECT ID, IMIE,NAZWISKO,DATA_URODZENIA,KONTAKT,MARKA,MODEL,NUMER_REJESTRACYJNY,INFORMACJA,KOSZT_NAPRAWY,STATUS_ZLECENIA FROM CARS as a INNER JOIN PERSON as b INNER JOIN REPAIR as c ON a.ID_PERSON=b.ID_PERSON WHERE a.ID_CAR=c.ID_CAR AND STATUS_ZLECENIA = \"W trakcie\" ORDER BY NUMER_REJESTRACYJNY");
                qry->prepare(buffer);
                qry->exec();
                model->setQuery(*qry);
                ui->tableView->setModel(model);
            }
            if(print == 1 && sort == 5){
                sprintf(buffer, "SELECT ID, IMIE,NAZWISKO,DATA_URODZENIA,KONTAKT,MARKA,MODEL,NUMER_REJESTRACYJNY,INFORMACJA,KOSZT_NAPRAWY,STATUS_ZLECENIA FROM CARS as a INNER JOIN PERSON as b INNER JOIN REPAIR as c ON a.ID_PERSON=b.ID_PERSON WHERE a.ID_CAR=c.ID_CAR AND STATUS_ZLECENIA = \"W trakcie\" ORDER BY STATUS_ZLECENIA");
                qry->prepare(buffer);
                qry->exec();
                model->setQuery(*qry);
                ui->tableView->setModel(model);
            }
            if(print == 2 && sort == 1){
                sprintf(buffer, "SELECT ID, IMIE,NAZWISKO,DATA_URODZENIA,KONTAKT,MARKA,MODEL,NUMER_REJESTRACYJNY,INFORMACJA,KOSZT_NAPRAWY,STATUS_ZLECENIA FROM CARS as a INNER JOIN PERSON as b INNER JOIN REPAIR as c ON a.ID_PERSON=b.ID_PERSON WHERE a.ID_CAR=c.ID_CAR AND STATUS_ZLECENIA = \"Do odebrania\" ORDER BY IMIE");
                qry->prepare(buffer);
                qry->exec();
                model->setQuery(*qry);
                ui->tableView->setModel(model);
            }
            if(print == 2 && sort == 2){
                sprintf(buffer, "SELECT ID, IMIE,NAZWISKO,DATA_URODZENIA,KONTAKT,MARKA,MODEL,NUMER_REJESTRACYJNY,INFORMACJA,KOSZT_NAPRAWY,STATUS_ZLECENIA FROM CARS as a INNER JOIN PERSON as b INNER JOIN REPAIR as c ON a.ID_PERSON=b.ID_PERSON WHERE a.ID_CAR=c.ID_CAR AND STATUS_ZLECENIA = \"Do odebrania\" ORDER BY NAZWISKO");
                qry->prepare(buffer);
                qry->exec();
                model->setQuery(*qry);
                ui->tableView->setModel(model);
            }
            if(print == 2 && sort == 3){
                sprintf(buffer, "SELECT ID, IMIE,NAZWISKO,DATA_URODZENIA,KONTAKT,MARKA,MODEL,NUMER_REJESTRACYJNY,INFORMACJA,KOSZT_NAPRAWY,STATUS_ZLECENIA FROM CARS as a INNER JOIN PERSON as b INNER JOIN REPAIR as c ON a.ID_PERSON=b.ID_PERSON WHERE a.ID_CAR=c.ID_CAR AND STATUS_ZLECENIA = \"Do odebrania\" ORDER BY MARKA");
                qry->prepare(buffer);
                qry->exec();
                model->setQuery(*qry);
                ui->tableView->setModel(model);
            }
            if(print == 2 && sort == 4){
                sprintf(buffer, "SELECT ID, IMIE,NAZWISKO,DATA_URODZENIA,KONTAKT,MARKA,MODEL,NUMER_REJESTRACYJNY,INFORMACJA,KOSZT_NAPRAWY,STATUS_ZLECENIA FROM CARS as a INNER JOIN PERSON as b INNER JOIN REPAIR as c ON a.ID_PERSON=b.ID_PERSON WHERE a.ID_CAR=c.ID_CAR AND STATUS_ZLECENIA = \"Do odebrania\" ORDER BY NUMER_REJESTRACYJNY");
                qry->prepare(buffer);
                qry->exec();
                model->setQuery(*qry);
                ui->tableView->setModel(model);
            }
            if(print == 2 && sort == 5){
                sprintf(buffer, "SELECT ID, IMIE,NAZWISKO,DATA_URODZENIA,KONTAKT,MARKA,MODEL,NUMER_REJESTRACYJNY,INFORMACJA,KOSZT_NAPRAWY,STATUS_ZLECENIA FROM CARS as a INNER JOIN PERSON as b INNER JOIN REPAIR as c ON a.ID_PERSON=b.ID_PERSON WHERE a.ID_CAR=c.ID_CAR AND STATUS_ZLECENIA = \"Do odebrania\" ORDER BY STATUS_ZLECENIA");
                qry->prepare(buffer);
                qry->exec();
                model->setQuery(*qry);
                ui->tableView->setModel(model);
            }
            if(print == 3 && sort == 1){
                sprintf(buffer, "SELECT ID, IMIE,NAZWISKO,DATA_URODZENIA,KONTAKT,MARKA,MODEL,NUMER_REJESTRACYJNY,INFORMACJA,KOSZT_NAPRAWY,STATUS_ZLECENIA FROM CARS as a INNER JOIN PERSON as b INNER JOIN REPAIR as c ON a.ID_PERSON=b.ID_PERSON WHERE a.ID_CAR=c.ID_CAR AND STATUS_ZLECENIA = \"Zakonczone\" ORDER BY IMIE");
                qry->prepare(buffer);
                qry->exec();
                model->setQuery(*qry);
                ui->tableView->setModel(model);
            }
            if(print == 3 && sort == 2){
                sprintf(buffer, "SELECT ID, IMIE,NAZWISKO,DATA_URODZENIA,KONTAKT,MARKA,MODEL,NUMER_REJESTRACYJNY,INFORMACJA,KOSZT_NAPRAWY,STATUS_ZLECENIA FROM CARS as a INNER JOIN PERSON as b INNER JOIN REPAIR as c ON a.ID_PERSON=b.ID_PERSON WHERE a.ID_CAR=c.ID_CAR AND STATUS_ZLECENIA = \"Zakonczone\" ORDER BY NAZWISKO");
                qry->prepare(buffer);
                qry->exec();
                model->setQuery(*qry);
                ui->tableView->setModel(model);
            }
            if(print == 3 && sort == 3){
                sprintf(buffer, "SELECT ID, IMIE,NAZWISKO,DATA_URODZENIA,KONTAKT,MARKA,MODEL,NUMER_REJESTRACYJNY,INFORMACJA,KOSZT_NAPRAWY,STATUS_ZLECENIA FROM CARS as a INNER JOIN PERSON as b INNER JOIN REPAIR as c ON a.ID_PERSON=b.ID_PERSON WHERE a.ID_CAR=c.ID_CAR AND STATUS_ZLECENIA = \"Zakonczone\" ORDER BY MARKA");
                qry->prepare(buffer);
                qry->exec();
                model->setQuery(*qry);
                ui->tableView->setModel(model);
            }
            if(print == 3 && sort == 4){
                sprintf(buffer, "SELECT ID, IMIE,NAZWISKO,DATA_URODZENIA,KONTAKT,MARKA,MODEL,NUMER_REJESTRACYJNY,INFORMACJA,KOSZT_NAPRAWY,STATUS_ZLECENIA FROM CARS as a INNER JOIN PERSON as b INNER JOIN REPAIR as c ON a.ID_PERSON=b.ID_PERSON WHERE a.ID_CAR=c.ID_CAR AND STATUS_ZLECENIA = \"Zakonczone\" ORDER BY NUMER_REJESTRACYJNY");
                qry->prepare(buffer);
                qry->exec();
                model->setQuery(*qry);
                ui->tableView->setModel(model);
            }
            if(print == 3 && sort == 5){
                sprintf(buffer, "SELECT ID, IMIE,NAZWISKO,DATA_URODZENIA,KONTAKT,MARKA,MODEL,NUMER_REJESTRACYJNY,INFORMACJA,KOSZT_NAPRAWY,STATUS_ZLECENIA FROM CARS as a INNER JOIN PERSON as b INNER JOIN REPAIR as c ON a.ID_PERSON=b.ID_PERSON WHERE a.ID_CAR=c.ID_CAR AND STATUS_ZLECENIA = \"Zakonczone\" ORDER BY STATUS_ZLECENIA");
                qry->prepare(buffer);
                qry->exec();
                model->setQuery(*qry);
                ui->tableView->setModel(model);
            }
    }
}
