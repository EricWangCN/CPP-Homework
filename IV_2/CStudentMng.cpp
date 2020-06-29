//
// Created by 王子龙 on 2019/10/29.
//

#include "CStudentMng.h"
using namespace std;

void CStudentMng::add_student (CStudent &stu) {
    if ( available == 0) { // if no space, expand it.
        CStudent *tmp = new CStudent[count + BLOCK];
        for (int i = 0; i < count; ++i) {
            tmp[i].set_number(gStu[i].get_number());
            tmp[i].set_major(gStu[i].get_major());
            tmp[i].set_name(gStu[i].get_name());
            tmp[i].set_score(gStu[i].get_score());
        }
        delete[] gStu;
        gStu = tmp;
        available = BLOCK;
    }
    // Add student information.
    gStu[count].set_number(stu.get_number());
    gStu[count].set_name(stu.get_name());
    gStu[count].set_major(stu.get_major());
    gStu[count].set_score(stu.get_score());

    count++;
    available--;
}

void CStudentMng::display() {
    cout << "ID\tName\tMajor\tScore" << endl;
    for (int i = 0; i < count; ++i) {
        cout << gStu[i].get_number() << "\t" << gStu[i].get_name().get_string() << "\t"
             << gStu[i].get_major().get_string() << "\t" << gStu[i].get_score() << endl;
    }
}

int CStudentMng::delete_student(long ID) {
    bool isFound = false;
    for (int i = 0; i < count; ++i) {
        if (gStu[i].get_number() == ID) {
            isFound = !isFound;
        }
        if (isFound) {
            gStu[i].set_number(gStu[i+1].get_number());
            gStu[i].set_score(gStu[i+1].get_score());
            gStu[i].set_major(gStu[i+1].get_major());
            gStu[i].set_name(gStu[i+1].get_name());
        }
    }
    if (isFound) {
        count--;
        available++;
    }
    if ( available > MAX_AVAILABLE ) {
        CStudent *tmp = new CStudent[count + BLOCK];
        for (int i = 0; i < count; ++i) {
            tmp[i].set_number(gStu[i].get_number());
            tmp[i].set_major(gStu[i].get_major());
            tmp[i].set_name(gStu[i].get_name());
            tmp[i].set_score(gStu[i].get_score());
        }
        delete[] gStu;
        gStu = tmp;
        available = BLOCK;
    }
    if (isFound) return 0;
    else return -1;
}

CStudentMng::CStudentMng(): gStu(NULL), count(0), available(0) {
}

CStudentMng::CStudentMng(CStudent &stu) {
    gStu = new CStudent[BLOCK];
    gStu[0] = stu;
    count = 1;
    available = BLOCK - 1;
}

CStudentMng::CStudentMng(CStudentMng &stuMng) {
    int num = stuMng.count + stuMng.available;
    if (num == 0) {
        gStu = nullptr;
    } else {
        gStu = new CStudent[num];
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
            gStu = new CStudent[num];
        }

        count = stuMng.count;
        available = stuMng.available;

        for (int i = 0; i < stuMng.count; ++i) {
            gStu[i] = stuMng.gStu[i];
        }
    }
    return *this;
}

CStudent &CStudentMng::getByName(char *name) {
    for (int i = 0; i < count; ++i) {
        if (strcmp(name, gStu[i].get_name().get_string()) == 0) {
            return gStu[i];
        }
    }
    return gStu[0];
}

bool CStudentMng::existByName(char *name) {
    for (int i = 0; i < count; ++i) {
        if (strcmp(name, gStu[i].get_name().get_string()) == 0) {
            return true;
        }
    }
    return false;
}

CStudent &CStudentMng::modifyScoreByName(char *name, double score) {
    CStudent & stu = getByName(name);
    stu.set_score(score);
    return stu;
}

void CStudentMng::display(char *name) {
    CStudent & stu = getByName(name);
    cout << "ID\tName\tMajor\tScore\t\n";
    cout << stu.get_number() << '\t' << stu.get_name().get_string() << '\t' << stu.get_major().get_string() << '\t'
         << stu.get_score() << "\n\n";
}

CStudentMng::~CStudentMng() {
    delete[] gStu;
}

void CStudentMng::display(long ID) {
    for (int i = 0; i < count; ++i) {
        if (ID == gStu[i].get_number()) {
            cout << "ID\tName\tMajor\tScore\t\n";
            cout << gStu[i].get_number() << '\t' << gStu[i].get_name().get_string() << '\t'
                 << gStu[i].get_major().get_string() << '\t' << gStu[i].get_score() << "\n\n";
        }
    }
}

void CStudentMng::display(double score) {
    for (int i = 0; i < count; ++i) {
        if (score == gStu[i].get_score()) {
            cout << "ID\tName\tMajor\tScore\t\n";
            cout << gStu[i].get_number() << '\t' << gStu[i].get_name().get_string() << '\t'
                 << gStu[i].get_major().get_string() << '\t' << gStu[i].get_score() << "\n\n";
        }
    }
}

void CStudentMng::display(double min, double max) {
    for (int i = 0; i < count; ++i) {
        if (gStu[i].get_score() >= min && gStu[i].get_score() <= max) {
            cout << "ID\tName\tMajor\tScore\t\n";
            cout << gStu[i].get_number() << '\t' << gStu[i].get_name().get_string() << '\t'
                 << gStu[i].get_major().get_string() << '\t' << gStu[i].get_score() << "\n";
        }
    }
    cout << endl;
}