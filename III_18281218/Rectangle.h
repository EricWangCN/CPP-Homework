//
// Created by 王子龙 on 2019/10/15.
//

#ifndef II_18281218_MYSTRING_RECTANGLE_H
#define II_18281218_MYSTRING_RECTANGLE_H

#include "MyString.h"

class Rectangle {
private:
    double a = 0;
    double b = 0;
    MyString name;
public:
    Rectangle ();
    Rectangle (double m, double n, MyString &s);
    Rectangle (double m, double n, const char* s);
    ~Rectangle();
    void display();
};

#endif //II_18281218_MYSTRING_RECTANGLE_H
