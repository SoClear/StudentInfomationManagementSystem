//
// Created by cmg on 5/30/20.
//


#include <string>
#include <iostream>
#include <mysql/mysql.h>
#include "/usr/include/mysql/mysql.h"

using namespace std;

#ifndef SIMS_DB_H
#define SIMS_DB_H


class DB {
private:
    MYSQL *mysql;
    MYSQL_RES *result{};
    MYSQL_ROW row{};
    const char *host = "localhost";
    const char *user = "root";
    const char *password = "123456";
    const char *db = "aaa";


public:
    DB();

    ~DB();

    bool connectDb();

    bool execSql(string sql);

    bool execSql(string sql, string &res);

    bool closeDb();
};


#endif //SIMS_DB_H
