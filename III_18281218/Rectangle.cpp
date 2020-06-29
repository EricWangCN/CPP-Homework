//
// Created by 王子龙 on 2019/10/15.
//

#include "Rectangle.h"
#include "MyString.h"

Rectangle::Rectangle(double m, double n, const char* s): a(m), b(n), name(s) {
}

Rectangle::Rectangle() {

}

void Rectangle::display() {
    std::cout << "a: " << a << "b: " << b << "name: " << name.get_string() << std::endl;
}

Rectangle::Rectangle(double m, double n, MyString &s) : a(m), b(n), name(s) {
}

Rectangle::~Rectangle() = default;;