//
// Created by cmg on 5/30/20.
//




#include "Student.h"


bool Student::add() {
    cout << "Please input name gender birthday" << endl;
    string name, gender, birthday;
    cin >> name >> gender >> birthday;
    string sql = R"(insert into student(name,gender,birthday) values (")";
    sql += name;
    sql += "\",\"";
    sql += gender;
    sql += "\",\"";
    sql += birthday;
    sql += "\");";
    cout << sql << endl;

    Student::execSql(sql);
}

bool Student::del() {
    //show all record first
    query();


    cout << "Please input the id that you want to delete" << endl;
    int id;
    cin >> id;
    string sql = "delete from student where id=" + to_string(id) + ";";

    Student::execSql(sql);
}

bool Student::change() {
    //show all record first
    query();


    cout << "Please input the id that you want to change" << endl;
    int id;
    cin >> id;
    string name, gender, birthday;
    cout << "Please input name gender birthday" << endl;
    cin >> name >> gender >> birthday;
    string sql = R"(UPDATE	student	SET	name=")";
    sql += name;
    sql += "\",gender=\"";
    sql += gender;
    sql += "\",birthday=\"";
    sql += birthday;
    sql += "\" where id=" + to_string(id) + ";";

    Student::execSql(sql);
}

bool Student::query() {
    string sql = R"(select * from student)";
    Student::execSql(sql);
}

//execute any sql query that you write in console,and print the result to screen
bool Student::execYourSql() {
    string sql;
    cout<<"Please input sql query"<<endl;
    getchar();
    getline(cin, sql);
    return Student::execSql(sql);
}




bool Student::fileToDB() {
    string fileName;
    cout<<"Please input file name"<<endl;
    getchar();
    getline(cin,fileName);

    ifstream inf;
    inf.open(fileName,ios::in);
    string s;
    while (getline(inf, s)) {
        if(s.empty()){
            continue;
        }
        
        string sqlTemp = R"(REPLACE into student(id,name,gender,birthday) values (")";
        vector<string> resV = split(s, ",");
        string backS = resV.back();
        resV.pop_back();
        for (const auto &item:resV) {
            sqlTemp += item;
            sqlTemp += "\",\"";
        }
        sqlTemp += backS + "\")";
        cout << sqlTemp << endl;
        Student::execSql(sqlTemp);
    }
    inf.close();
    return false;
}



bool Student::execSql(string sql) {
    DB *db = new DB();
    db->connectDb();
    if (db->execSql(sql)) {
        cout << "succeed" << endl;
        db->closeDb();
        return true;
    } else {
        cout << "failed" << endl;
        db->connectDb();
        return false;
    }
}

bool Student::sqlResultToFile() {
    DB *db = new DB();
    db->connectDb();

    string sql;
    cout << "Please input sql query" << endl;
    getchar();
    getline(cin, sql);

    //the result is sql query result
    string result;
    if (db->execSql(sql, result)) {
        cout << "succeed" << endl;
        db->closeDb();

        ofstream ofs;
        for (char &r : result) {
            if (r == 9) {
                r = ',';
            }
        }

        string fileName;
        cout<<"Please input file name"<<endl;

        getline(cin, fileName);
        ofs.open(fileName,ios::out);
        ofs<<result<<endl;
        ofs.close();
        cout<<"sql result written to file "+fileName <<endl;
    } else {
        cout << "failed" << endl;
        db->connectDb();
        return false;
    }
}

vector<string> Student::split(const string &str, const string &delim) {
    vector<string> res;
    if (str.empty()) return res;
    //先将要切割的字符串从string类型转换为char*类型
    char *strs = new char[str.length() + 1]; //不要忘了
    strcpy(strs, str.c_str());

    char *d = new char[delim.length() + 1];
    strcpy(d, delim.c_str());

    char *p = strtok(strs, d);
    while (p) {
        string s = p; //分割得到的字符串转换为string类型
        res.push_back(s); //存入结果数组
        p = strtok(nullptr, d);
    }
    delete[]strs;
    delete[]d;
    return res;
}


