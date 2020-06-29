#include "Student.h"
#include "CStudentMng.h"
using namespace std;
int main() {
    CStudentMng stuMng;
    CStudent s;
    int choice = -1;
    while (choice != 0) {
        cout << endl;
        cout << " - Student Information Manage System - \n";
        cout << "1 Input student information.\n";
        cout << "2 Display student information.\n";
        cout << "3 Modify score by name (METHOD A).\n";
        cout << "4 Modify score by name (METHOD B).\n";
        cout << "5 Test copy constructor.\n";
        cout << "6 Test parameter constructor.\n";
        cout << "7 Delete exact student information.\n";
        cout << "0 Exit.\n";
        cout << "Please choose:";
        cin >> choice;
        switch (choice) {
            case 1: {
                cout << "Please input ID, name, major, and average score in order.\n";
                char a[1000], b[1000];
                double x, y;
                cin >> x >> a >> b >> y;
                s.set_number(x);
                s.set_score(y);
                s.set_name(a);
                s.set_major(b);
                stuMng.add_student(s);
                cout << endl;
                break;
            }
            case 2: {
                char num;
                cout << "Please input the way of display:\n";
                cout << "1 Display all.\n";
                cout << "2 Display by number ( 1st one ).\n";
                cout << "3 Display by score  ( 1st one ).\n";
                cout << "4 Display by range  (   all   ).\n";
                cin >> num;
                switch (num) {
                    case '1':
                        stuMng.display();
                        break;
                    case '2':
                        long number;
                        cout << "Please input number:";
                        cin >> number;
                        stuMng.display(number);
                        break;
                    case '3':
                        double score;
                        cout << "Please input number:";
                        cin >> score;
                        stuMng.display(score);
                        break;
                    case '4':
                        double min, max;
                        cout << "Please input range (min,max):";
                        cin >> min >> max;
                        stuMng.display(min, max);
                        break;
                    default:
                        cout << "Illegal input!\n";
                        break;
                }
                cout << endl;
                break;
            }
            case 3: {
                cout << "Please input name of the student:";
                char name[20];
                cin >> name;
                if (stuMng.existByName(name)) {
                    cout << "Please input the score:";
                    double score;
                    cin >> score;
                    stuMng.getByName(name).set_score(score);
                    stuMng.display(name);
                } else cout << "The student you are searching:" << name << "doesn't exist!\n";
                break;
            }
            case 4: {
                cout << "Please input name and score of the student:";
                char name[20];
                double score;
                cin >> name >> score;
                if (stuMng.existByName(name)) stuMng.modifyScoreByName(name, score);
                else cout << "The student you are searching:" << name << "doesn't exist!\n";
                break;
            }
            case 5: {
                CStudentMng stuMngBak(stuMng);
                stuMngBak.display();
            }
            case 6: {
                CStudent stu(1, "ZhangSan", "CS", 100);
                CStudentMng stuMng(stu);
                stuMng.display();
            }
            case 7: {
                long ID;
                cout << "Please input the ID:\n";
                cin >> ID;
                if (stuMng.delete_student(ID) == -1)
                    cout << "Cannot find this element!" << endl;
                else
                    cout << "Delete success!" << endl;
                cout << "All information now:\n";
                stuMng.display();
                break;
            }
            case 0:
                break;
            default:
                cout << "Wrong choice! choose again!\n";
        }
    }
    return 0;
}