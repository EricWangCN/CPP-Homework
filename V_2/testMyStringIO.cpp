//
// Created by 王子龙 on 2019/11/1.
//

#include <fstream>
#include "MyString.h"

bool testMyStringIO() {
    MyString str("I love C++ programming!"), str2("haha");
    std::ofstream out("MyString.txt");
    out << str;
    out.close();

    std::ifstream in("MyString.txt");
    str2.read_text(in);
    in.close();

    if (strcmp(str2.get_string(), str.get_string()) != 0)
        return false;

    out.open("MyString.txt");
    str.write_text(out);
    out.close();

    in.open("MyString.txt");
    str2.read_text(in);
    in.close();
    if (strcmp(str2.get_string(), str.get_string()) != 0) return false;

    out.open("MyString.dat");
    str.write_binary(out);
    out.close();

    in.open("MyString.dat");
    str2.read_binary(in);
    in.close();

    return strcmp(str2.get_string(), str.get_string()) == 0;
}