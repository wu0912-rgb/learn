#include <iostream>
#include"StudentManager.h"
using namespace std;
int main()
{
    StudentManager StudentManager;
    int choice=1;
    while (choice)
    {
        cout << "\n=== 学生管理系统 ===" << endl;
        cout << "1. 添加学生" << endl;
        cout << "2. 显示所有学生" << endl;
        cout << "3. 显示平均分" << endl;
        cout << "0. 退出" << endl;
        cout << "请选择操作: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            string name;
            int score;
            cout << "请输入学生姓名: ";
            cin >> name;
            cout << "请输入学生成绩: ";
            cin >> score;
            StudentManager.addStudent(name, score);
            break;
        }
        case 2: {
            StudentManager.showAllStudents();
            break;
        }
        case 3: {
            StudentManager.showAverage();
            break;
        }
        case 0: {
            cout << "感谢使用!" << endl;
            break;
        }
        default:
            cout << "无效选择!" << endl;
           
        }
    }
    return 0;
}


