#include <iostream>
#include <fstream>
#include "Student.h"
#include <vector>
#include <cstring>

using namespace std;

void showChoice(){
    cout << "\n\n-------欢迎使用学生管理系统-------\n";
    cout << "\t1. 添加学生信息\n";
    cout << "\t2. 删除学生信息\n";
    cout << "\t3. 修改学生信息\n";
    cout << "\t4. 查看学生信息\n";
    cout << "\t5. 执行自定义sql语句\n";
    cout << "\t6. 把sql语句的执行结果存为文件\n";
    cout << "\t7. 把文件中的数据导入到数据库\n";
    cout << "\t8. 退出\n";
    cout << "------------------------------\n\n";
    cout<<"Please input a number:"<<endl;
}

int main() {
    auto *student = new Student;

    int choice;
    while (true){
        showChoice();
        cin>>choice;
        switch (choice) {
            case 1:
                student->add();
                break;
            case 2:
                student->del();
                break;
            case 3:
                student->change();
                break;
            case 4:
                student->query();
                break;
            case 5:
                student->execYourSql();
                break;
            case 6:
                student->sqlResultToFile();
                break;
            case 7:
                student->fileToDB();
                break;
            default:
                return 0;
        }
    }
}

