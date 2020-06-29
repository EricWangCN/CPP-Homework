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
    private:
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
        CStudentMng(int num, MyString & name, MyString & major, double score);
        CStudentMng(const CStudentMng &stuMng);
        ~CStudentMng();
        void set_number(int num) {
            number = num;
        }
        int get_number() const {
            return number;
        };
        MyString & set_name (const MyString &name);
        MyString get_name() const {
            return name;
        }
        MyString & set_major (const MyString &major);
        MyString get_major() const {
            return major;
        }
        void set_score (double score) {
            this->score = score;
        }
        double get_score() const {
            return score;
        }
        CStudentMng &operator = (const CStudentMng & stu) {
            if (this != &stu) {
                number = stu.number;
                name = stu.name;
                major = stu.major;
                score = stu.score
            }
            return *this;
        }
        //explicit CStudentMng(STUDENT & stu);
        //CStudentMng(CStudentMng &stuMng);
        //CStudentMng & operator = (CStudentMng &stuMng);
        //~CStudentMng();

        //void add_student(STUDENT &stu);
        //STUDENT &getByName(char* name);
        //bool existByName(char* name);
        //STUDENT &modifyScoreByName(char* name, double score);
        //void display();
        //void display(char* name);
        //void display(long ID);
        //void display(double score);
        //void display(double min, double max);
        //int delete_student(long ID);

        STUDENT *gStu;
        int count;
        int available;
    private:
        int number;
        double score;
        MyString name;
        MyString major;
    };


}

#endif //INC_1_N_123456_2_H
