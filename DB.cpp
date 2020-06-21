//
// Created by cmg on 5/30/20.
//


#include "DB.h"

DB::DB() {
    mysql = mysql_init(nullptr);
    if (mysql == nullptr) {
        cout << "error occurs " << mysql_error(mysql);
        exit(1);
    }
}

DB::~DB() {
    if (mysql != nullptr) {
        mysql_close(mysql);
    }
}


bool DB::connectDb() {
    if (!mysql_real_connect(mysql, host, user, password, db, 0, nullptr, 0)) {
        cout << "error occurs " << mysql_error(mysql);
        exit(1);
    } else {
//        cout<<"Mysql Database Connected"<<endl;
        return true;
    }
}


bool DB::execSql(string sql,string& res) {
    if (mysql_query(mysql, sql.c_str())) {
        cout << "query error " << mysql_error(mysql) << endl;
        return false;
    } else {
        result = mysql_use_result(mysql);
        if (result) {
            unsigned int num_fields = mysql_num_fields(result);
            unsigned int num_rows = mysql_num_rows(reinterpret_cast<MYSQL_RES *>(mysql));
            for (int i = 0; i < num_rows; i++) {
                row = mysql_fetch_row(result);
                if (!row) break;
                for (int j = 0; j < num_fields; j++) {
//                    cout << row[j] << "\t";
                    res += row[j];
                    res += "\t";
                }
//                cout << endl;
                res += "\n";
            }
        }
        mysql_free_result(result);
    }
    return true;
}

bool DB::execSql(string sql) {
    if (mysql_query(mysql, sql.c_str())) {
        cout << "query error " << mysql_error(mysql) << endl;
        return false;
    } else {
        result = mysql_use_result(mysql);
        if (result) {
            unsigned int num_fields = mysql_num_fields(result);
            unsigned int num_rows = mysql_num_rows(reinterpret_cast<MYSQL_RES *>(mysql));
            for (int i = 0; i < num_rows; i++) {
                row = mysql_fetch_row(result);
                if (!row) break;
                for (int j = 0; j < num_fields; j++) {
                    cout << row[j] << "\t";
                }
                cout << endl;
            }
        }
        mysql_free_result(result);
    }
    return true;
}

bool DB::closeDb() {
    if (mysql != nullptr) {
        mysql_close(mysql);
    }
    return true;
}

