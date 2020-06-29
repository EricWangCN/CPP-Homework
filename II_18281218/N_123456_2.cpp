//
// Created by 王子龙 on 2019/9/16.
//
#include "N_123456_2.h"

namespace N123456 {



    /*
    void CStudentMng::add_student (STUDENT &stu) {
        if ( available == 0) { // if no space, expand it.
            STUDENT *tmp = new STUDENT[count + BLOCK];
            for (int i = 0; i < count; ++i) {
                tmp[i].number = gStu[i].number;
                tmp[i].name.set_string(gStu[i].name.get_string());
                tmp[i].major.set_string(gStu[i].major.get_string());
                tmp[i].score = gStu[i].score;
            }
            delete[] gStu;
            gStu = tmp;
            available = BLOCK;
        }
        // Add student information.
        gStu[count].number = stu.number;
        gStu[count].name.set_string(stu.name.get_string());
        gStu[count].major.set_string(stu.major.get_string());
        gStu[count].score = stu.score;

        count++;
        available--;
    }

    void CStudentMng::display() {
        cout << "ID\tName\tMajor\tScore" << endl;
        for (int i = 0; i < count; ++i) {
            cout << gStu[i].number << "\t" << gStu[i].name.get_string() << "\t"
            << gStu[i].major.get_string() << "\t" << gStu[i].score << endl;
        }
    }

    int CStudentMng::delete_student(long ID) {
        bool isFound = false;
        for (int i = 0; i < count; ++i) {
            if (gStu[i].number == ID) {
                isFound = !isFound;
            }
            if (isFound) {
                gStu[i].number = gStu[i+1].number;
                gStu[i].score = gStu[i+1].score;
                gStu[i].major.set_string(gStu[i+1].major.get_string());
                gStu[i].name.set_string(gStu[i+1].name.get_string());
            }
        }
        if (isFound) {
            count--;
            available++;
        }
        if ( available > MAX_AVAILABLE ) {
            auto *tmp = new STUDENT[count + BLOCK];
            for (int i = 0; i < count; ++i) {
                tmp[i].number = gStu[i].number;
                tmp[i].name.set_string(gStu[i].name.get_string());
                tmp[i].major.set_string(gStu[i].major.get_string());
                tmp[i].score = gStu[i].score;
            }
            delete[] gStu;
            gStu = tmp;
            available = BLOCK;
        }
        if (isFound) return 0;
        else return -1;
    }

    CStudentMng::CStudentMng() {
        gStu = nullptr;
        count = 0;
        available = 0;
    }

    CStudentMng::CStudentMng(STUDENT &stu) {
        gStu = new STUDENT[BLOCK];
        gStu[0] = stu;
        count = 1;
        available = BLOCK - 1;
    }

    CStudentMng::CStudentMng(CStudentMng &stuMng) {
        int num = stuMng.count + stuMng.available;
        if (num == 0) {
            gStu = nullptr;
        } else {
            gStu = new STUDENT[num];
        }

        count = stuMng.count;
        available = stuMng.available;

        for (int i = 0; i < stuMng.count; ++i) {
            gStu[i] = stuMng.gStu[i];
        }
    }

    CStudentMng &CStudentMng::operator=(CStudentMng &stuMng) {
        if(this != &stuMng) {
            int num = stuMng.count + stuMng.available;
            if (num == 0) {
                delete[] gStu;
                gStu = nullptr;
            } else {
                delete[] gStu;
                gStu = new STUDENT[num];
            }

            count = stuMng.count;
            available = stuMng.available;

            for (int i = 0; i < stuMng.count; ++i) {
                gStu[i] = stuMng.gStu[i];
            }
        }
        return *this;
    }

    STUDENT &CStudentMng::getByName(char *name) {
        for (int i = 0; i < count; ++i) {
            if (strcmp(name, gStu[i].name.get_string()) == 0) {
                return gStu[i];
            }
        }
        return gStu[0];
    }

    bool CStudentMng::existByName(char *name) {
        for (int i = 0; i < count; ++i) {
            if (strcmp(name, gStu[i].name.get_string()) == 0) {
                return true;
            }
        }
        return false;
    }

    STUDENT &CStudentMng::modifyScoreByName(char *name, double score) {
        STUDENT & stu = getByName(name);
        stu.score = score;
        return stu;
    }

    void CStudentMng::display(char *name) {
        STUDENT & stu = getByName(name);
        cout << "ID\tName\tMajor\tScore\t\n";
        cout << stu.number << '\t' << stu.name.get_string() << '\t' << stu.major.get_string() << '\t' << stu.score << "\n\n";
    }

    CStudentMng::~CStudentMng() {
        delete[] gStu;
    }

    void CStudentMng::display(long ID) {
        for (int i = 0; i < count; ++i) {
            if (ID == gStu[i].number) {
                cout << "ID\tName\tMajor\tScore\t\n";
                cout << gStu[i].number << '\t' << gStu[i].name.get_string() << '\t' << gStu[i].major.get_string() << '\t' << gStu[i].score << "\n\n";
            }
        }
    }

    void CStudentMng::display(double score) {
        for (int i = 0; i < count; ++i) {
            if (score == gStu[i].score) {
                cout << "ID\tName\tMajor\tScore\t\n";
                cout << gStu[i].number << '\t' << gStu[i].name.get_string() << '\t' << gStu[i].major.get_string() << '\t' << gStu[i].score << "\n\n";
            }
        }
    }

    void CStudentMng::display(double min, double max) {
        for (int i = 0; i < count; ++i) {
            if (gStu[i].score >= min && gStu[i].score <= max) {
                cout << "ID\tName\tMajor\tScore\t\n";
                cout << gStu[i].number << '\t' << gStu[i].name.get_string() << '\t' << gStu[i].major.get_string() << '\t' << gStu[i].score << "\n";
            }
        }
        cout << endl;
    }*/
    CStudentMng::CStudentMng() {
        gStu = nullptr;
        count = 0;
        available = 0;
    }

    CStudentMng::CStudentMng(int num, MyString &name, MyString &major, double score): number(num), name(name), major(major), score {

    }
}