//
// Created by 王子龙 on 2019/11/1.
//

#ifndef V_2_STUDENT_H
#define V_2_STUDENT_H

#include <iostream>
#include "MyString.h"
using namespace std;
namespace N123456 {
    class CStudent {
    public:
        CStudent() {}

        CStudent(const int number, const MyString &name,
                 const MyString &major, const double score)
                : number(number), name(name), major(major), score(score) {}

        int get_number() const { return number; }

        int set_number(const int number) {
            this->number = number;
            return number;
        }

        MyString get_name() const { return name; }

        MyString &get_name() { return name; }

        MyString &set_name(const char *s) {
            name.set_string(s);
            return name;
        }

        MyString &set_name(const MyString &name) {
            this->name = name;
            return this->name;
        }

        MyString get_major() const { return major; }

        MyString &get_major() { return major; }

        MyString &set_major(const char *s) {
            major.set_string(s);
            return major;
        }

        MyString &set_major(const MyString &major) {
            this->major = major;
            return this->major;
        }

        double get_score() const { return score; }

        double set_score(const double score) {
            this->score = score;
            return score;
        }

        double modifyScore(const double score) {
            this->score = score;
            return score;
        }

        friend ostream &operator<<(ostream &o, const CStudent &s);

        CStudent &read_text(istream &in) {
            in >> number;
            in.get();
            name.read_text(in);
            major.read_text(in);
            in >> score;
            in.get();
            return *this;
        }

        CStudent &read_binary(istream &in) {
            in.read((char*) &number, sizeof(int));
/*
            int len_name = 0;
            in.read((char*)& len_name, sizeof(int));
            char* char_name = new char[len_name+1];
            in.read(char_name, len_name);
            char_name[len_name] = '\0';
            name.set_string(char_name);

            int len_major = 0;
            in.read((char*)& len_major, sizeof(int));
            char* char_major = new char[len_major+1];
            in.read(char_major, len_major);
            char_name[len_major] = '\0';
            major.set_string(char_major);
*/

            name = name.read_binary(in);
            major = major.read_binary(in);
            in.read((char*) &score, sizeof(double));
            return *this;
        }

        CStudent &write_binary(ostream &o) {
            o.write((char*) &number, sizeof(int));
            /*
            int len_name = strlen(name.get_string());
            o.write((char*)& len_name, sizeof(int));
            o.write(name.get_string(), len_name);

            int len_major = strlen(major.get_string());
            o.write((char*)& len_major, sizeof(int));
            o.write(major.get_string(), len_major);
            */


            name.write_binary(o);
            major.write_binary(o);
            o.write((char*) &score, sizeof(double));
            return *this;
        }

        void display(ostream &o) const {
            o << number << "\t" << name.get_string() << "\t"
              << major.get_string() << "\t" << score << endl;
        }

    private:
        int number;
        MyString name;
        MyString major;
        double score;
    };

    class CStudentMng {
#define BLOCK 10
    public:
        CStudentMng();

        CStudentMng(const CStudent &stu);

        CStudentMng(const CStudentMng &stuMng);

        CStudentMng &operator=(const CStudentMng &stuMng);

        ~CStudentMng();

        void add_student(CStudent &stu);

        CStudent &getByName(char *name);

        const CStudent &getByName(char *name) const;

        bool existByName(char *name) const;

        CStudent &modifyScoreByName(char *name, double score);

        void display() const;

        void display(char *name) const;

//清空当前对象中的数据，在read函数中会调用此函数，为读取数据准备条件
        void clear() {
            delete[] gStu;
            gStu = NULL;
            count = 0;
            available = 0;
        }

        friend ostream &operator<<(ostream &o, const CStudentMng &mng);

        CStudentMng &read_text(istream &in);
        CStudentMng &read_binary(istream &in);
        CStudentMng &write_binary(ostream &o);
    private:
        CStudent *gStu;
        int count;
        int available;//可用的空间
    };
}

#endif //V_2_STUDENT_H
