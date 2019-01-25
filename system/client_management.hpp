#ifndef C_CLIENT_MANAGEMENT_HPP
#define C_CLIENT_MANAGEMENT_HPP

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "sqlite3.h"

extern char *sql; /**< Globalna zmienna sql do zapisywania zapytań do bazy danych*/
extern sqlite3* database; /**< Zmienna odnosząca się do bazy sqlite*/
extern sqlite3_stmt* stmt; /**< Zmienna odnosząca się do bazy sqlite przez stmt*/

extern int first_row; /**< Globalna zmienna do wypisywania zapytań bazy danych w formie tabeli.*/

using namespace std;

void execute_sqlite_database_ID();

/**
 * @code
 * callback()
 * @endcode
 * @note Funkcja wypisuje na ekranie zapytanie z bazy danych w formie listy. Otrzymuje wartosc pola, numer kolumny, wiersz oraz nazwe kolumny. Po wykonaniu zadania zwraca 0.
 * */

static int callback(void *data, int argc, char **argv, char **azColName);

/**
 * @code
 * select_callback()
 * @endcode
 * @note Funkcja wypisuje na ekranie zapytanie z bazy danych w formie tabelki. Otrzymuje wartosc pola, numer kolumny, wiersz oraz nazwe kolumny. Zwraca 0.
 * */

int select_callback(void *p_data, int num_fields, char **p_fields, char **p_col_names);

/**
 * @code
 * select_stmt()
 * @endcode
 * @note Funkcja pobierająca zapytania z bazy danych. Otrzymuje komendę w zmiennej stmt.
 * */

void select_stmt(const char* stmt);

/**
 * @code
 * execute_sqlite_database()
 * @endcode
 * @note Funkcja pobierajaca zapytania do bazy danych. Służy do późniejszego wypisywania w formie listy. Nic nie otrzymuje, nic nie zwraca.
 * */

void execute_sqlite_database(void);

/**
 * @code
 * callback_ID_PERSON()
 * @endcode
 * @note Funkcja pobiera dane od użytkownika odnośnie samochodu. Otrzymuje wartosc pola, numer kolumny, wiersz oraz nazwe kolumny. Po wykonaniu zwraca 0.
 * */

static int callback_ID_PERSON(void *data, int argc, char **argv, char **azColName);

/**
 * @code
 * execute_sqlite_database_ID_PERSON()
 * @endcode
 * @note Funkcja pobierająca zapytania z bazy danych. Nic nie otrzymuje, nic nie zwraca.
 * */

void execute_sqlite_database_ID_PERSON(void);

/**
 * @code
 * callback_ID()
 * @endcode
 * @note Funkcja pobiera dane od użytkownika odnośnie zlecenia. Otrzymuje wartosc pola, numer kolumny, wiersz oraz nazwe kolumny. Zwraca 0.
 * */

static int callback_ID(void *data, int argc, char **argv, char **azColName);

/**
 * @code
 * execute_sqlite_database_ID()
 * @endcode
 * @note Funkcja pobierająca zapytania z bazy danych. Nic nie otrzymuje, nic nie zwraca.
 * */

void execute_sqlite_database_ID(void);

/**
 * @code
 * add_person()
 * @endcode
 * @note Funkcja dodająca nową osobę w bazie, jeżeli jeszcze nie istnieje. Nic nie otrzymuje, nic nie zwraca.
 * */

void add_person(void);

/**
 * @code
 * delete_client_in_database()
 * @endcode
 * @note Funkcja usuwająca zlecenie w bazie danych. Nic nie otrzymuje, nic nie zwraca.
 * */

void delete_client_in_database(int delete_id);

/**
 * @code
 * add_client_to_database()
 * @endcode
 * @note Funkcja zajmująca się dodawaniem zleceń. Sprawdza czy klient już istnieje, jeżeli tak to pyta czy chcemy wybrać istniejący już samochód czy dodać nowy i dopisać do niego nowe zlecenie. Nic nie otrzymuje, nic nie zwraca.
 * */

void add_client_to_database(void);

/**
 * @code
 * find_car()
 * @endcode
 * @note Funkcja wyszukuje samochod po numerze rejestracyjnym. Nic nie otrzymuje, nic nie zwraca.
 * */

#endif //C_CLIENT_MANAGEMENT_HPP

