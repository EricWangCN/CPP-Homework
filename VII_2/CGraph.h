//
// Created by 王子龙 on 2019/11/25.
//

#ifndef VII_2_CGRAPH_H
#define VII_2_CGRAPH_H

#include "MyString.h"
#include <cmath>
#define PI 3.1415926535


class CGraph {
public:
    virtual double perimeter() const;

    virtual double area() const;

    void setName(MyString name);
    MyString& getName();
private:
    MyString name;
};

class CCircle : public CGraph {
public:
    double perimeter() const;
    double area() const;

    CCircle(double R);
private:
    double R;
};

class CRectangle : public CGraph {
public:
    double perimeter() const;
    double area() const;

    CRectangle(double Len, double Width);
private:
    double Len, Width;
};


#endif //VII_2_CGRAPH_H
