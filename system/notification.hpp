#ifndef C_NOTIFICATION_HPP
#define C_NOTIFICATION_HPP

#include "client_management.hpp"
#include "cartoreceivenotification.h"


/**
 * @code
 * callback_notification()
 * @endcode
 * @note Funkcja sprawdzająca czy w bazie są jakieś nieodebrane pojazdy.
 * */

static int callback_notification(void *data, int argc, char **argv, char **azColName);

/**
 * @code
 * execute_sqlite_database_notification()
 * @endcode
 * @note Funkcja pobierająca zapytania z bazy danych.
 * */

void execute_sqlite_database_notification();

#endif //C_NOTIFICATION_HPP
