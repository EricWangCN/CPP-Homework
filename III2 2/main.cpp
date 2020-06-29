//
// Created by 王子龙 on 2019/10/27.
//
#include "Student.h"
using namespace std;
int main()
{
    CStudent stu;
    CStudent *stu2 = new CStudent[2];
    delete[] stu2;
    MyString name("zhangsan"),major("computer");
    CStudent stu3(1324,name,major,100);
    CStudent stu4(stu3);
    const CStudent stu5 = stu4;

    cout << stu4.get_name().get_string() << endl;
    cout << stu4.get_major().get_string() << endl;
    cout << stu4.get_score() << endl;
    cout << stu5.get_name().get_string() << endl;
    cout << stu5.get_major().get_string() << endl;
    cout << stu5.get_score() << endl;
    stu = stu4;

    return 0;
}