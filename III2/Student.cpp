//
// Created by 王子龙 on 2019/10/27.
//

#include "Student.h"


CStudent::CStudent(){}

CStudent::CStudent(int num,MyString &name,MyString & major,double score):number(num),name(name),major(major),score(score)
{
}

CStudent::CStudent(const CStudent &stu):number(stu.number),name(stu.name),major(stu.major),score(stu.score)
{
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



