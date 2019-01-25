#include "notification.hpp"

/**
 * @code
 * callback_notification()
 * @endcode
 * @note Funkcja sprawdzająca czy w bazie są jakieś nieodebrane pojazdy.
 * */

static int callback_notification(void *data, int argc, char **argv, char **azColName){

    int i; /**< Iterator wypisujący wszystkie kolumny pobrane z odpowiedzi z bazy danych*/
    char notification[20]; /**< Zmienna, która pobiera odpowiedź z bazy danych*/
    int not1 = 0; /**< Zmienna, która pobiera dane o ilości występowania statusu 'Nieodebrane'*/

    for(i = 0; i<argc; i++){
        sprintf(notification, "%s", argv[i] ? argv[i] : "NULL");
    }

    not1 = atoi(notification);


    if(not1 > 0) {
        carToReceiveNotification carToReceiveNotificationObj;
        carToReceiveNotificationObj.setModal(true);
        carToReceiveNotificationObj.exec();
    }
    return 0;
}

/**
 * @code
 * execute_sqlite_database_notification()
 * @endcode
 * @note Funkcja pobierająca zapytania z bazy danych.
 * */

void execute_sqlite_database_notification(){

    int rc; /**< Zmienna, do której przypisywana jest funkcja wykonawcza*/
    char *errmsg; /**< Zmienna wypisujaca występujące błędy*/
    const char* data = " "; /**< Zmienna, która służy do wypisywania zapytania*/

    rc = sqlite3_exec(database, sql, callback_notification, (void*)data, &errmsg);

    if( rc != SQLITE_OK ) {
        fprintf(stderr, "SQL error: %s\n", errmsg);
        sqlite3_free(errmsg);
    }
}
