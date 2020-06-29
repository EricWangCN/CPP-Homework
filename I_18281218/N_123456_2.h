//
// Created by 王子龙 on 2019/9/16.
//

#ifndef INC_1_N_123456_2_H
#define INC_1_N_123456_2_H

#include <iostream>
using namespace std;

namespace N123456 {
    #define BLOCK 10
    #define MAX_AVAILABLE 12

    struct STUDENT {
        long number;
        double score;
        char name[30];
        char major[30];
    };

    extern STUDENT *gStu;
    extern int count;
    extern int available;

    void add_student(STUDENT &stu);
    void display();
    int delete_student(long ID);
}

#endif //INC_1_N_123456_2_H
