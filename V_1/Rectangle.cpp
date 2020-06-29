//
// Created by 王子龙 on 2019/10/15.
//

#include "Rectangle.h"
#include "MyString.h"

Rectangle::Rectangle(double m, double n, const char* s): a(m), b(n), name(s) {
    std::cout<<"a";
}

Rectangle::Rectangle():a(1), b(1), name("default") {
    std::cout<<"b";
}

Rectangle::Rectangle(double m, double n, MyString &s) : a(m), b(n), name(s) {
    std::cout<<"c";
}

Rectangle::~Rectangle() = default;;