//
// Created by 王子龙 on 2019/10/29.
//

#ifndef IV_2_CSTUDENTMNG_H
#define IV_2_CSTUDENTMNG_H

#include "Student.h"

class CStudentMng {
#define BLOCK 10
#define MAX_AVAILABLE 12
public:
    CStudentMng();
    explicit CStudentMng(CStudent & stu);
    CStudentMng(CStudentMng &stuMng);
    CStudentMng & operator = (CStudentMng &stuMng);
    ~CStudentMng();

    void add_student(CStudent &stu);
    CStudent &getByName(char* name);
    bool existByName(char* name);
    CStudent &modifyScoreByName(char* name, double score);
    void display();
    void display(char* name);
    void display(long ID);
    void display(double score);
    void display(double min, double max);
    int delete_student(long ID);

private:
    CStudent *gStu;
    int count;
    int available;
};



#endif //IV_2_CSTUDENTMNG_H
