#ifndef C_MENU_HPP
#define C_MENU_HPP

#include "notification.hpp"

/**
 * @code
 * sqlite_connection()
 * @endcode
 * @note Funkcja sprawdzająca połączenie z bazą danych. Jeżeli taka baza danych nie istnieje tworzy nową. Do poprawnego działania programu wymagana jest do tej funkcji dodatkowo check_database_correct(). Nic nie otrzymuje, nic nie zwraca.
 * */

int sqlite_connection(void);

/**
 * @code
 * check_database_correct()
 * @endcode
 * @note Funkcja sprawdzająca czy baza danych jest poprawnie utworzona. Zawiera przykład poprawnej bazy danych. Nic nie otrzymuje, nic nie zwraca.
 * */

void check_database_correct(void);

/**
 * @code
 * sqlite_end()
 * @endcode
 * @note Funkcja zamykająca dostęp do bazy danych. Zamyka połączenie. Nic nie otrzymuje, nic nie zwraca.
 * */

void sqlite_end(void);

/**
 * @code
 * menu()
 * @endcode
 * @note Główna funkcja projektu. Wyświetla menu oraz zawiera opcje do przechodzenia do kolejnych etapów. Nic nie otrzymuje, nic nie zwraca.
 * */

void menu(void);

#endif //C_MENU_HPP
