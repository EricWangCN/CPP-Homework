//
// Created by 王子龙 on 2019/12/5.
//

#ifndef INC_8_2__123456_2_H
#define INC_8_2__123456_2_H

#include <iostream>
#include "MyString.h"
using namespace std;

namespace N123456
{
    class CStudent
    {
    public:
        CStudent(){ }
        CStudent(const int number, const MyString & name,
                 const MyString & major, const double score)
                : number(number), name(name), major(major), score(score)
        { }
        virtual ~CStudent() {}		//由于有继承，所以需要提供析构函数，并将其设为虚函数
        int get_number() const { return number; }	//对于类似的get-set函数，由于在派生类中不
//必重新实现，所以可以不为虚的，当然，也可以设为虚的
        int set_number(const int number) { this->number = number; return number; }

        const MyString get_name() const { return name; }
        MyString & get_name() { return name; }	//返回引用，从而可以对name作进一步运算
        MyString & set_name(const char * s) { name.set_string(s); return name; }
        MyString & set_name(const MyString & name){ this->name = name; return this->name; }

        const MyString get_major() const { return major; }
        MyString & get_major() { return major; }
        MyString & set_major(const char * s) { major.set_string(s); return major; }
        MyString & set_major(const MyString & major) { this->major = major; return this->major; }

        const double get_score() const { return score; }
        double set_score(const double score) { this->score = score; return score; }
        double modifyScore(const double score) { this->score = score; return score; }
        virtual bool equal(const CStudent & p)	//比较两个CStudent对象是否相等（即各项内容相同）
        {
            if (number != p.number || name != p.name || major != p.major || score != p.score)
                return false;
            else
                return true;
        }

        friend ostream & operator<<(ostream & o, const CStudent & s);
        virtual void write_text(ostream & out) const
        {
            out << number << " ";
            name.write_text(out);
            major.write_text(out);
            out << " " << score << " ";
        }
        virtual CStudent & read_text(istream & in)
        {
            in >> number;    //读取学号
            in.get();        //抛掉随后的一个空格
            name.read_text(in);   //读取学生的名字
            major.read_text(in);  //读取学生的专业
            in.get();
            in >> score;     //读取学生的成绩
            in.get();        //抛掉随后的空格

            return *this;
        }

        virtual void write_binary(ostream & out) const
        {
            out.write((char*)&number, sizeof(int));
            name.write_binary(out);
            major.write_binary(out);
            out.write((char*)&score, sizeof(double));
        }
        virtual CStudent & read_binary(istream & in)
        {
            in.read((char*)&number, sizeof(int));    //读取学号
            name.read_binary(in);   //读取学生的名字
            major.read_binary(in);  //读取学生的专业
            in.read((char*)&score, sizeof(double));     //读取学生的成绩

            return *this;
        }

        virtual void display(ostream & o) const {
            o << number << "\t" << name.get_string() << "\t" << major.get_string() << "\t" << score << "\t";
        }
    private:
        int  number;
        MyString name;
        MyString major;
        double score;
    };

    class CGraduate : public CStudent
    {
    public:
        CGraduate() { }
        CGraduate(const int number, const MyString & name,
                  const MyString & major, const double score, const MyString & supervisor)
                : CStudent(number, name, major, score), supervisor(supervisor)
        { }

        MyString & get_supervisor() { return supervisor; }
        const MyString get_supervisor() const { return supervisor; }
        MyString & set_supervisor(const char * p) { supervisor.set_string(p); return supervisor; }
        MyString & set_supervisor(const MyString & s) { supervisor = s; return supervisor; }

        bool equal(const CGraduate & p)	//比较两个CGraduate对象是否相等（即各项内容相同）
        {
            if (!this->CStudent::equal(p))
                return false;
            if (supervisor != p.supervisor)
                return false;

            return true;
        }

        friend ostream & operator<<(ostream & o, const CGraduate & s);
        virtual void write_text(ostream & out) const
        {
            CStudent::write_text(out);
            out << " ";
            supervisor.write_text(out);
        }
        virtual CGraduate & read_text(istream & in)
        {
            this->CStudent::read_text(in);	//调用基类的函数读取从基类继承下来的数据
            supervisor.read_text(in);				//读取新增加的导师信息

            return *this;

        }

        virtual void write_binary(ostream & out) const
        {
            this->CStudent::write_binary(out);
            supervisor.write_binary(out);
        }
        virtual CStudent & read_binary(istream & in)
        {
            this->CStudent::read_binary(in);
            supervisor.read_binary(in);

            return *this;
        }

        virtual void display(ostream & o) const {
            CStudent::display(o);
            o << supervisor << "\t";
        }
    private:
        MyString supervisor;
    };

    class CStudentMng
    {
#define BLOCK 10
    public:
        CStudentMng();
        //由于可加入的学生类型不可预知，所以只能使用基类指针作为参数，并且该指针一定指向
        //堆上的内存；调用构造函数后，该指针指向的内存就交给CStudentMng的对象来管理
        CStudentMng(CStudent * stu);
        ~CStudentMng();

        void add_student(CStudent * stu);
        CStudent * getByName(char * name);
        //const CStudent * getByName(char * name) const;  //常对象是没有意义的，所以不提供常函数版本
        bool existByName(char * name) const;
        int get_count() { return count; }		//取得保存的学生个数
        void display() const;
        void display(char * name) const;

        CStudent * operator[](const int idx) //对于此类，常对象是没有意义的，所以不必实现常函数版本
        {
            return gStu[idx];
        }

        void clear() //清空当前对象中的数据，在read函数中会调用此函数，为读取数据准备条件
        {
            for (int i = 0; i < count; i++)	//先逐个回收每个指针指向的空间
                delete gStu[i];
            delete[] gStu;					//再回收指针数组占用的空间
            gStu = NULL;
            count = 0;
            available = 0;
        }

        friend ostream & operator<<(ostream & o, const CStudentMng & mng);

/*		由于使用多态，我们无法预知学生中的类型，为了保持程序的通用性，就无法将读写文件的功能封装为成员函数
		void write_text(ostream & out) const;
		CStudentMng & read_text(istream & in);
		void write_binary(ostream & out) const;
		CStudentMng & read_binary(istream & in);*/
    private:
        //由于使用多态，所以无法实现复制构造函数和赋值运算符，因此将它们设为私有的，防止从外部调用
        CStudentMng(const CStudentMng & stuMng);
        CStudentMng & operator=(const CStudentMng & stuMng);

        CStudent ** gStu;
        int count;//已经加入的学生个数
        int available;//可用的空间
    };
}



#endif //INC_8_2__123456_2_H
