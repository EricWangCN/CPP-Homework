//
// Created by 王子龙 on 2019/9/16.
//
#include "N_123456_2.h"
using namespace N123456;

int main() {
    char choice = '\0';
    STUDENT s;
    long ID;

    while (choice != '0') {
        cout << " - Student Information Manage System - \n";
        cout << "1 Input student information.\n";
        cout << "2 Display student information.\n";
        cout << "3 Delete specific student information by ID。\n";
        cout << "0 Exit.\n";
        cout << "Please choose:";
        cin >> choice;

        switch (choice) {
            case '1': {
                cout << "Please input ID, name, major, and average score in order.\n";
                cin >> s.number >> s.name >> s.major >> s.score;
                add_student(s);
                cout << endl;
                break;
            }
            case '2': {
                display();
                cout << endl;
                break;
            }
            case '3': {
                cout << "Please input the ID:\n";
                cin >> ID;
                if ( delete_student(ID) == -1 )
                    cout << "Cannot find this element!" << endl;
                else
                    cout << "Delete success!" << endl;
                break;
            }
            case '0':
                break;
            default: cout << "Wrong choice! choose again!\n";
        }
    }

    return 0;
}