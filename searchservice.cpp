#include "searchservice.h"
#include "ui_searchservice.h"
#include <system/client_management.hpp>
#include <QPainter>
#include <mainwindow.h>

searchService::searchService(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::searchService)
{
    ui->setupUi(this);
    QPixmap background("C:/Users/Asus/Documents/CWM/CarWorkshopManagement/resources/background.png");
    ui->picture->setPixmap(background);
    QPixmap darktheme("C:/Users/Asus/Documents/CWM/CarWorkshopManagement/resources/darkTheme.png");
    ui->theme1->setPixmap(darktheme);
}

searchService::~searchService()
{
    delete ui;
}

void searchService::on_pushButton_7_clicked()
{
    hide();
    addService addServiceObj;
    addServiceObj.setModal(true);
    addServiceObj.exec();
}

void searchService::on_pushButton_6_clicked()
{
    hide();
    delService delServiceObj;
    delServiceObj.setModal(true);
    delServiceObj.exec();
}

void searchService::on_pushButton_5_clicked()
{
    hide();
    printService printServiceObj;
    printServiceObj.setModal(true);
    printServiceObj.exec();
}

void searchService::on_pushButton_4_clicked()
{
    hide();
    searchService searchServiceObj;
    searchServiceObj.setModal(true);
    searchServiceObj.exec();
}

void searchService::printDatabase(void *p_data, int num_fields, char **p_fields, char **p_col_names){
        int i;

        //ui->textEdit->setText("Hello");

        int* nof_records = (int*) p_data;
        (*nof_records)++;


        if (first_row) {
            first_row = 0;

            printf("%1s", p_col_names[0]);

            for (i=1; i < num_fields; i++) {
                printf("%16s", p_col_names[i]);
            }

            printf("\n");
            for (i=0; i< num_fields*15; i++) {
                printf("=");
            }
            printf("\n");
        }

        printf("%2s", p_fields[0]);

        for(i=1; i < num_fields; i++) {
            if (p_fields[i]) {
                printf("%16s", p_fields[i]);
            }
            else {
                printf("%16s", " ");
            }
        }

        printf("\n");
    }

/**
 * @code
 * select_callback()
 * @endcode
 * @note Funkcja wypisuje na ekranie zapytanie z bazy danych w formie tabelki. Otrzymuje wartosc pola, numer kolumny, wiersz oraz nazwe kolumny. Zwraca 0.
 * */

int select_callback1(void *p_data, int num_fields, char **p_fields, char **p_col_names) {
    searchService s;
    s.printDatabase(p_data, num_fields, p_fields, p_col_names);
    return 0;
}

/**
 * @code
 * select_stmt()
 * @endcode
 * @note Funkcja pobierająca zapytania z bazy danych. Otrzymuje komendę w zmiennej stmt.
 * */

void select_stmt1(const char* stmt) {
    char *errmsg;
    int   ret;
    int   nrecs = 0;

    first_row = 1;

    ret = sqlite3_exec(database, stmt, select_callback1, &nrecs, &errmsg);

    if(ret!=SQLITE_OK) {
        perror("SQLITE_OK");
    }
    else {
        fprintf(stdout, "\n\nOperation done successfully\n");
    }
}

/**
 * @code
 * on_pushButton_clicked()
 * @endcode
 * @note Metoda wyszukuje samochod po numerze rejestracyjnym. Nic nie otrzymuje, nic nie zwraca.
 * */

void searchService::on_pushButton_clicked()
{
    QString tmp = ui->lineEdit->text();
    const QByteArray stringData = tmp.toUtf8();
    char registration_number[100];
    registration_number[qMin(99,stringData.size())]='\0';
    copy(stringData.constBegin(),stringData.constBegin()+qMin(99,stringData.size()),registration_number);
   // find_car(text);
    MainWindow conn;
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery *qry = new QSqlQuery(conn.mydb);
    char buffor[300];

    sprintf(buffor, "SELECT ID, IMIE,NAZWISKO,DATA_URODZENIA,KONTAKT,MARKA,MODEL,NUMER_REJESTRACYJNY,INFORMACJA,KOSZT_NAPRAWY,STATUS_ZLECENIA FROM CARS as a INNER JOIN PERSON as b INNER JOIN REPAIR as c ON a.ID_PERSON=b.ID_PERSON WHERE a.ID_CAR=c.ID_CAR AND NUMER_REJESTRACYJNY GLOB \"%s*\"", registration_number);
    qry->prepare(buffor);
    qry->exec();
    model->setQuery(*qry);
    ui->tableView_2->setModel(model);
}

void searchService::on_lineEdit_editingFinished()
{

}
