//
// Created by 王子龙 on 2019/9/16.
//
#include "N_123456_2.h"
#include <string>

namespace N123456 {
    STUDENT *gStu = NULL;
    int count = 0;
    int available = 0;

    void add_student (STUDENT &stu) {
        if ( available == 0) { // if no space, expand it.
            STUDENT *tmp = new STUDENT[count + BLOCK];
            for (int i = 0; i < count; ++i) {
                tmp[i].number = gStu[i].number;
                strcpy(tmp[i].name, gStu[i].name);
                strcpy(tmp[i].major, gStu[i].major);
                tmp[i].score = gStu[i].score;
            }
            delete[] gStu;
            gStu = tmp;
            available = BLOCK;
        }
        // Add student information.
        gStu[count].number = stu.number;
        strcpy(gStu[count].name, stu.name);
        strcpy(gStu[count].major, stu.major);
        gStu[count].score = stu.score;

        count++;
        available--;
    }

    void display() {
        cout << "ID\tName\tMajor\tScore" << endl;
        for (int i = 0; i < count; ++i) {
            cout << gStu[i].number << "\t" << gStu[i].name << "\t"
            << gStu[i].major << "\t" << gStu[i].score << endl;
        }
    }

    int delete_student(long ID) {
        bool isFound = false;
        for (int i = 0; i < count; ++i) {
            if (gStu[i].number == ID) {
                isFound = !isFound;
            }
            if (isFound) {
                gStu[i].number = gStu[i+1].number;
                gStu[i].score = gStu[i+1].score;
                strcpy(gStu[i].major, gStu[i+1].major);
                strcpy(gStu[i].name, gStu[i+1].name);
            }
        }
        if ( isFound == true ) {
            count--;
            available++;
        }
        if ( available > MAX_AVAILABLE ) {
            STUDENT *tmp = new STUDENT[count + BLOCK];
            for (int i = 0; i < count; ++i) {
                tmp[i].number = gStu[i].number;
                strcpy(tmp[i].name, gStu[i].name);
                strcpy(tmp[i].major, gStu[i].major);
                tmp[i].score = gStu[i].score;
            }
            delete[] gStu;
            gStu = tmp;
            available = BLOCK;
        }
        if (isFound) return 0;
        else return -1;
    }
}
