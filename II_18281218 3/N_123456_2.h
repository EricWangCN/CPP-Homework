//
// Created by 王子龙 on 2019/9/16.
//

#ifndef INC_1_N_123456_2_H
#define INC_1_N_123456_2_H

#include <iostream>
#include "MyString.h"
using namespace std;

namespace N123456 {

    class STUDENT {
    public:
        long number;
        double score;
        MyString name;
        MyString major;
    };

    class CStudentMng {
        #define BLOCK 10
        #define MAX_AVAILABLE 12
    public:
        CStudentMng();
        explicit CStudentMng(STUDENT & stu);
        CStudentMng(CStudentMng &stuMng);
        CStudentMng & operator = (CStudentMng &stuMng);
        ~CStudentMng();

        void add_student(STUDENT &stu);
        STUDENT &getByName(char* name);
        bool existByName(char* name);
        STUDENT &modifyScoreByName(char* name, double score);
        void display();
        void display(char* name);
        void display(long ID);
        void display(double score);
        void display(double min, double max);
        int delete_student(long ID);

        STUDENT *gStu;
        int count;
        int available;
    };


}

#endif //INC_1_N_123456_2_H
