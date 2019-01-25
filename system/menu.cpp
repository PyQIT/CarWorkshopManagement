#include "menu.hpp"

int sqlite_connection(void){


    int connection;

    connection = sqlite3_open("SQLite_database.db", &database);

    if(connection) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(database));
        return(0);
    }
    else {
        fprintf(stderr, "Opened database successfully\n");
    }
}

void check_database_correct(void){

    char buffer[300];
    char buffer1[300];
    char buffer2[300];


    sprintf(buffer,"CREATE TABLE IF NOT EXISTS CARS (ID_CAR INTEGER PRIMARY KEY AUTOINCREMENT, MARKA TEXT, MODEL TEXT,NUMER_REJESTRACYJNY TEXT,ID_PERSON INT);");
    sql = buffer;
    execute_sqlite_database();
    sprintf(buffer1,"CREATE TABLE IF NOT EXISTS PERSON(ID_PERSON INTEGER PRIMARY KEY AUTOINCREMENT,IMIE TEXT,NAZWISKO TEXT,DATA_URODZENIA TEXT,KONTAKT TEXT);");
    sql = buffer1;
    execute_sqlite_database();
    sprintf(buffer2,"CREATE TABLE IF NOT EXISTS REPAIR(ID INTEGER PRIMARY KEY AUTOINCREMENT,INFORMACJA TEXT,KOSZT_NAPRAWY REAL,STATUS_ZLECENIA TEXT DEFAULT 'W trakcie',ID_CAR INT);");
    sql = buffer2;
    execute_sqlite_database();
}

void sqlite_end(void){

    sqlite3_close(database);
}

void menu(void) {
    char buffer[300];

    sprintf(buffer, "SELECT COUNT(STATUS_ZLECENIA) FROM REPAIR WHERE STATUS_ZLECENIA = 'Do odebrania'");
    sql = buffer;

    execute_sqlite_database_notification();
}
