//
// Created by 王子龙 on 2019/10/29.
//

#ifndef IV_2_STUDENT_H
#define IV_2_STUDENT_H


#include "MyString.h"

class CStudent
{
public:
    CStudent();
    CStudent(int num,MyString & name,MyString & major,double score);
    CStudent(int num,char* n,char* m,double score);
    CStudent(const CStudent &stu);
    ~CStudent();
    void set_number(int num);
    int get_number() const {return number;}
    MyString & set_name(const MyString & name);
    MyString & get_name() {return name;}
    MyString get_name() const {return name;}
    MyString & set_major(const MyString & major);
    MyString & get_major() {return major;}
    MyString get_major() const {return major;}
    void set_score(double score);
    double get_score() const {return score;}
    CStudent & operator=(const CStudent & stu)
    {
        if(this != &stu)
        {

            number = stu.number;
            name = stu.name;
            major = stu.major;
            score = stu.score;
        }
        return *this;
    }

private:
    int number;
    MyString name;
    MyString major;
    double score;
};


#endif //IV_2_STUDENT_H
