#include <iostream>
#include <fstream>
#include "_123456_2.h"
using namespace N123456;

int main()
{
    CStudentMng stuMng;

    int choice = -1;
    while (choice != 0)
    {
        cout << "1 录入本科生信息 \n";
        cout << "2 录入研究生信息 \n";
        cout << "3 显示学生信息 \n";
        cout << "4 通过名字修改成绩 \n";
        cout << "5 保存学生信息（文本格式） \n";
        cout << "6 从文件中加载学生信息（文本格式） \n";
        cout << "7 保存学生信息（二进制格式） \n";
        cout << "8 从文件中加载学生信息（二进制格式） \n";
        cout << "0 退出\n";
        cout << "请选择所需要的操作：";
        cin >> choice;

        if (1 == choice)	//录入本科生信息
        {
            CStudent * pStu = new CStudent;
            cout << "请依次输入学号、姓名、专业和成绩\n";
            char buf[64];
            int  tmp;
            cin >> tmp;
            pStu->set_number(tmp);
            cin >> buf;
            pStu->set_name(buf);
            cin >> buf;
            pStu->set_major(buf);
            cin >> tmp;
            pStu->set_score(tmp);
            stuMng.add_student(pStu);
        }
        else if (2 == choice)	//录入研究生信息
        {
            CGraduate * pGraduate = new CGraduate;
            cout << "请依次输入学号、姓名、专业、成绩和导师姓名\n";
            char buf[64];
            int  tmp;
            cin >> tmp;
            pGraduate->set_number(tmp);
            cin >> buf;
            pGraduate->set_name(buf);
            cin >> buf;
            pGraduate->set_major(buf);
            cin >> tmp;
            pGraduate->set_score(tmp);
            cin >> buf;
            pGraduate->set_supervisor(buf);
            stuMng.add_student(pGraduate);
        }
        else if (3 == choice)	//显示学生列表
            stuMng.display();
        else if (4 == choice)	//根据姓名修改学生的成绩
        {
            cout << "请输入要查询的学生姓名：";
            char name[64];
            cin >> name;
            if (stuMng.existByName(name))
            {
                cout << "请输入要修改的成绩：";
                double score;
                cin >> score;
                stuMng.getByName(name)->modifyScore(score);
                stuMng.display(name);
            }
            else
                cout << "查询的学生 " << name << " 不存在！\n\n";
        }
        else if (5 == choice)	//将学生信息写入到文本文件中
        {
            ofstream out("test.txt");
            //取得每一个学生并逐个写入文件：本科生的标记为1，研究生的标记为2
            int i, count = stuMng.get_count();
            out << count << " ";	//先写入学生总数
            for (i = 0; i < count; i++)
            {
                if (dynamic_cast<CGraduate*>(stuMng[i]) == NULL)
                    out << 1 << " ";
                else
                    out << 2 << " ";
                stuMng[i]->write_text(out);
                out << " ";
            }
            out.close();
        }
        else if (6 == choice)	//从文本文件中读取数据并回复stuMng对象
        {
            stuMng.clear();
            ifstream in("test.txt");
            int i, count, type;
            in >> count;
            in.get();
            CStudent * pStu;
            for (i = 0; i < count; i++)
            {
                in >> type;
                in.get();
                if (type == 1)	//是本科生
                {
                    CStudent * p = new CStudent;
                    p->read_text(in);
                    pStu = p;
                }
                else  //是研究生
                {
                    CGraduate * pGraduate = new CGraduate;
                    pGraduate->read_text(in);
                    pStu = pGraduate;
                }
                in.get();
                stuMng.add_student(pStu);
            }
            in.close();
        }
        else if (7 == choice)	//将学生信息写入到二进制文件中
        {
            ofstream out("test.dat", ios_base::binary);
            //取得每一个学生并逐个写入文件：本科生的标记为1，研究生的标记为2
            int i, type, count = stuMng.get_count();
            out.write((char*)&count, sizeof(int));	//先写入学生总数
            for (i = 0; i < count; i++)
            {
                if (dynamic_cast<CGraduate*>(stuMng[i]) == NULL)
                {
                    type = 1;
                    out.write((char*)&type, sizeof(int));
                }
                else
                {
                    type = 2;
                    out.write((char*)&type, sizeof(int));
                }
                stuMng[i]->write_binary(out);
            }
            out.close();
        }
        else if (8 == choice)	//从二进制文件中读取数据并回复stuMng对象
        {
            stuMng.clear();
            ifstream in("test.dat", ios_base::binary);
            int i, count, type;
            in.read((char*)&count, sizeof(int));
            CStudent * pStu;
            for (i = 0; i < count; i++)
            {
                in.read((char*)&type, sizeof(int));
                if (type == 1)	//是本科生
                {
                    CStudent * p = new CStudent;
                    p->read_binary(in);
                    pStu = p;
                }
                else  //是研究生
                {
                    CGraduate * pGraduate = new CGraduate;
                    pGraduate->read_binary(in);
                    pStu = pGraduate;
                }
                stuMng.add_student(pStu);
            }
            in.close();
        }
        else if(0 == choice)
            break;
        else
            cout << "你的选择有误，请重新选择！\n" << endl;
    }

    return 0;
}
