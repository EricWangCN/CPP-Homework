//
// Created by 王子龙 on 2019/10/15.
//

#ifndef V_1_RECTANGLE_H
#define V_1_RECTANGLE_H


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
    double get_length() {return a; }
    double get_width() { return b; }
    double area() const { return a * b; };
    double area(double ext) const {return (a + 2 * ext) * (a + 2 * ext); };
    double perimeter() const { return 2 * (a + b); };
    double perimeter(double ext) const { return 2 * (a + b + 4 * ext); };
};


#endif //V_1_RECTANGLE_H
