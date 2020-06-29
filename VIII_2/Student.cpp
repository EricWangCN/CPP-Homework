//
// Created by 王子龙 on 2019/11/1.
//

#include "Student.h"
namespace N123456
{
    ostream & operator<<(ostream & o, const CStudent & s) {
        o << s.number << " " << s.name << s.major << s.score;
        o << " "; //再输出一个空格，以防止两个学生的信息连在一起无法区分
        return o;
    }
//CStudentMng类的实现------------------------------------------------------
    ostream & operator<<(ostream & o, const CStudentMng & mng) {
        for (int i = 0; i < mng.count; i++)
            o << mng.gStu[i];
        return o;
    }
    CStudentMng & CStudentMng::read_text(istream & in) {
        clear();
        CStudent s;
        while (true)
        {
            in.get();
            if (in.eof())
//清空数据，为读取数据做好准备
//尝试读取一个字符，以检查是否到了文件尾
                break;
            else //没有到文件尾，所以回退一个字符，将之前多读取的字符送回输入流
                in.seekg(-1, ios_base::cur);
            s.read_text(in);
            add_student(s);
        }
        return *this;
    }

    CStudentMng &CStudentMng::read_binary(istream &in) {
        clear();
        CStudent s;
        while (true) {
            int i;
            in.read((char*) &i, sizeof(int));
            if (in.eof())
                break;
            else
                in.seekg(-sizeof(int), ios_base::cur);
            s.read_binary(in);
            add_student(s);
        }
        return *this;
    }

    CStudentMng &CStudentMng::write_binary(ostream &o) {
        for (int i = 0; i < count; ++i) {
            gStu[i].write_binary(o);
        }
        return *this;
    }

    CStudentMng::CStudentMng() : gStu(NULL), count(0), available(0)
    {
    }
    CStudentMng::CStudentMng(const CStudent & stu) : count(1), available(BLOCK - 1) {
        gStu = new CStudent[BLOCK];
        gStu[0] = stu;
    }
    CStudentMng::CStudentMng(const CStudentMng & stuMng)
    {
        int num = stuMng.count + stuMng.available;
        if (0 == num)
            gStu = NULL;
        else
            gStu = new CStudent[num]; count = stuMng.count; available = stuMng.available;
        for (int i = 0; i < stuMng.count; i++) gStu[i] = stuMng.gStu[i];
    }
    CStudentMng & CStudentMng::operator=(const CStudentMng & stuMng) {
        if (this != &stuMng) {
            int num = stuMng.count + stuMng.available; if (0 == num)
                gStu = NULL; else
                gStu = new CStudent[num]; count = stuMng.count; available = stuMng.available;
            for (int i = 0; i < stuMng.count; i++) gStu[i] = stuMng.gStu[i];
        }
        return *this;
    }
    CStudentMng::~CStudentMng() {
        delete[] gStu;
    }
    void CStudentMng::add_student(CStudent & stu) {
        if (0 == available) {//如果没有空间，需先扩展空间
            CStudent * tmp = new CStudent[count + BLOCK];
            for (int i = 0; i < count; i++) tmp[i] = gStu[i];
            delete[] gStu; gStu = tmp; available = BLOCK;
        }
//增加学生信息
        gStu[count] = stu;
        count++;
        available--;
    }
    bool CStudentMng::existByName(char * name) const
    {
        for (int i = 0; i < count; i++) {
            if (strcmp(name, gStu[i].get_name().get_string()) == 0) return true;
        }
        return false;
    }
    CStudent & CStudentMng::getByName(char * name)
    {
        for (int i = 0; i < count; i++) {
            if (strcmp(name, gStu[i].get_name().get_string()) == 0) return gStu[i];
        }
//此时找不到要获取的学生，所以意味着出错。由于还没有讲异常处理， //所以先返回一个非法的CStudent对象，以满足返回值类型的要求 return gStu[-1];
    }
    const CStudent & CStudentMng::getByName(char * name) const
    {
        for (int i = 0; i < count; i++) {
            if (strcmp(name, gStu[i].get_name().get_string()) == 0) return gStu[i];
        }
//此时找不到要获取的学生，所以意味着出错。由于还没有讲异常处理， //所以先返回一个非法的CStudent对象，以满足返回值类型的要求 return gStu[-1];
    }
    CStudent & CStudentMng::modifyScoreByName(char * name, double score)
    {
        CStudent & stu = getByName(name); stu.modifyScore(score);
        return stu;
    }
    void CStudentMng::display() const
    {
        cout << "学号\t姓名\t专业\t成绩" << endl; for (int i = 0; i < count; i++)
        {
            gStu[i].display(cout);
        }
        cout << endl;
    }
    void CStudentMng::display(char * name) const
    {
        cout << "学号\t姓名\t专业\t成绩" << endl; for (int i = 0; i < count; i++)
        {
            if (strcmp(gStu[i].get_name().get_string(), name) == 0) gStu[i].display(cout);
        }
        cout << endl;
    }

}