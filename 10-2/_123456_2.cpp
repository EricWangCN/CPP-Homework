//
// Created by 王子龙 on 2019/12/5.
//

#include "_123456_2.h"

namespace N123456
{
    ostream & operator<<(ostream & o, const CStudent & s)
    {
        o << s.number << " " << s.name << s.major << s.score;
        o << " ";  //再输出一个空格，以防止两个学生的信息连在一起无法区分开
        return o;
    }

    ostream & operator<<(ostream & o, const CGraduate & s)
    {
        o << (CStudent)s;
        o << s.get_supervisor();
        o << " ";  //再输出一个空格，以防止两个学生的信息连在一起无法区分开
        return o;
    }

    //CStudentMng类的实现------------------------------------------------------
    ostream & operator<<(ostream & o, const CStudentMng & mng)
    {
        for (int i = 0; i < mng.count; i++)
        {
            mng.gStu[i]->display(o);
            o << endl;
        }
        return o;
    }

    CStudentMng::CStudentMng() : gStu(NULL), count(0), available(0)
    {
    }

    CStudentMng::CStudentMng(CStudent * stu) : count(1), available(BLOCK - 1)
    {
        gStu = new CStudent*[BLOCK];
        gStu[0] = stu;
    }

    CStudentMng::~CStudentMng()
    {
        for (int i = 0; i < count; i++)
            delete gStu[i];
        delete[] gStu;
    }

    void CStudentMng::add_student(CStudent * stu)
    {
        if (0 == available)
        {//如果没有空间，需先扩展空间
            CStudent ** tmp = new CStudent*[count + BLOCK];
            for (int i = 0; i < count; i++)
                tmp[i] = gStu[i];

            delete[] gStu;
            gStu = tmp;
            available = BLOCK;
        }
        //增加学生信息
        gStu[count] = stu;
        count++;
        available--;
    }

    bool CStudentMng::existByName(char * name) const
    {
        for (int i = 0; i < count; i++)
        {
            if (strcmp(name, gStu[i]->get_name().get_string()) == 0)
                return true;
        }

        return false;
    }

    CStudent * CStudentMng::getByName(char * name)
    {
        for (int i = 0; i < count; i++)
        {
            if (strcmp(name, gStu[i]->get_name().get_string()) == 0)
                return gStu[i];
        }

        //此时找不到要获取的学生，所以意味着出错，此时返回NULL
        return NULL;
    }

    void CStudentMng::display() const
    {
        cout << "学号\t姓名\t专业\t成绩\t导师" << endl;
        for (int i = 0; i < count; i++)
        {
            gStu[i]->display(cout);
            cout << endl;
        }
        cout << endl;
    }

    void CStudentMng::display(char * name) const
    {
        cout << "学号\t姓名\t专业\t成绩\t导师" << endl;
        for (int i = 0; i < count; i++)
        {
            if (strcmp(gStu[i]->get_name().get_string(), name) == 0)
                gStu[i]->display(cout);
            cout << endl;
        }
        cout << endl;
    }
}
