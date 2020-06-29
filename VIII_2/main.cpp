#include <iostream>
#include <fstream>
#include "Student.h"

using namespace N123456;
int main() {
    CStudentMng stuMng;
    int choice = -1;
    CStudent s;
    while (choice != 0) {
        cout << "1 录入学生信息 \n";
        cout << "2 显示学生信息 \n";
        cout << "3 通过名字修改成绩(方法一)\n";
        cout << "4 通过名字修改成绩(方法二)\n";
        cout << "5 测试复制构造函数(复制当前学生管理对象并显示学生信息)\n";
        cout << "6 测试有参构造函数\n";
        cout << "7 保存学生信息 \n";
        cout << "8 从文件中加载学生信息 \n";
        cout << "9 保存学生信息（二进制）\n";
        cout << "10 从文件中加载学生信息 \n";
        cout << "11 退出\n";
        cout << "请选择所需要的操作:";
        cin >> choice;
        if (1 == choice) {
            cout << "请依次输入学号、姓名、专业和成绩\n";
            char buf[64];
            int tmp;
            cin >> tmp;
            s.set_number(tmp);
            cin >> buf;
            s.set_name(buf);
            cin >> buf;
            s.set_major(buf);
            cin >> tmp;
            s.set_score(tmp);
            stuMng.add_student(s);
        }
        else if (2 == choice)
            stuMng.display();
        else if (3 == choice) {
            cout << "请输入要查询的学生姓名:";
            char name[20];
            cin >> name;
            if (stuMng.existByName(name)) {
                cout << "请输入要修改的成绩:";
                double score;
                cin >> score;
                stuMng.getByName(name).modifyScore(score);
                stuMng.display(name);
            } else
                cout << "查询的学生 " << name << " 不存在!\n\n";
        }
        else if (4 == choice) {
            cout << "请输入学生的姓名和成绩:";
            char name[20];
            double score;
            cin >> name >> score;
            if (stuMng.existByName(name))
                stuMng.modifyScoreByName(name, score);
            else
                cout << "学生 " << name << " 不存在!\n\n";
        }
        else if (5 == choice) {
            CStudentMng stuMngBak(stuMng);
            stuMngBak.display();
        }
        else if (6 == choice) {
            CStudent stu(1, "zhangsan", "computer", 100);
            CStudentMng stuMng(stu);
            stuMng.display();
        }
        else if (7 == choice) {
            ofstream out("test.txt");
            out << stuMng;
            out.close();
        }
        else if (8 == choice) {
            ifstream in("test.txt");
            stuMng.read_text(in);
            in.close();
        }
        else if (9 == choice) {
            ofstream out("test.dat");
            stuMng.write_binary(out);
            out.close();
        }
        else if (10 == choice) {
            ifstream in("test.dat");
            stuMng.read_binary(in);
            in.close();
        }
        else if(11 == choice)
            break;
        else
            cout << "你的选择有误，请重新选择!\n" << endl;
    }
    return 0;
}