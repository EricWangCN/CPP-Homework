//
// Created by 王子龙 on 2019/10/29.
//

#include "Student.h"


CStudent::CStudent(){}

CStudent::CStudent(int num,MyString &name,MyString & major,double score):number(num),name(name),major(major),score(score)
{
}

CStudent::CStudent(const CStudent &stu):number(stu.number),name(stu.name),major(stu.major),score(stu.score)
{
}

CStudent::CStudent(int num, char* n, char *m, double score): number(num), score(score){
    MyString a(n);
    MyString b(m);
    name = a;
    major = m;
}

CStudent::~CStudent(){
}

void CStudent::set_number(int num)
{
    number = num;
}

MyString & CStudent::set_name(const MyString &name)
{
    this->name = name;
    return this->name;
}



void CStudent::set_score(double score)
{
    this->score = score;
}

MyString &CStudent::set_major(const MyString &major) {
    this->major = major;
    return this->major;
}

