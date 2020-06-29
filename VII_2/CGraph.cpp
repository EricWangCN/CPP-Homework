//
// Created by 王子龙 on 2019/11/25.
//

#include "CGraph.h"

double CGraph::perimeter() const
{
    return 0;
}
double CGraph::area() const
{
    return 0;
}
void CGraph::setName(MyString name)
{
    this->name = name;
}
MyString& CGraph::getName()
{
    return name;
}

CCircle::CCircle(double R) :R(R)
{
}
double CCircle::perimeter() const
{
    return 2 * PI * R;
}
double CCircle::area() const
{
    return PI * R * R;
}


CRectangle::CRectangle(double Len, double Width) :Len(Len), Width(Width)
{
}
double CRectangle::perimeter() const
{
    return 2 * (Len + Width);
}
double CRectangle::area() const
{
    return Len * Width;
}