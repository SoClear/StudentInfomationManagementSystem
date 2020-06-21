//
// Created by cmg on 5/30/20.
//
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>
#include "DB.h"

using namespace std;

#ifndef SIMS_STUDENT_H
#define SIMS_STUDENT_H


class Student {
private:
    vector<string> split(const string &str, const string &delim);

public:
    bool execSql(string sql);

    bool sqlResultToFile();


    bool fileToDB();

    bool execYourSql();

    bool add();

    bool del();

    bool change();

    bool query();
};


#endif //SIMS_STUDENT_H
