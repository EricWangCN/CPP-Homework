//
// Created by 王子龙 on 2019/10/14.
//

#ifndef V_1_MYSTRING_H
#define V_1_MYSTRING_H


#include <iostream>
class MyString {
public:
    int get_length();
    MyString();
    MyString(const char *p);
    MyString(const MyString & str);
    MyString & operator=(const MyString & s);
    const char * get_string() const;
    void set_string(const char *str);
    const char * append(const char * p = NULL);
    MyString & append(const MyString &s);
    ~MyString();
private:
    char * m_pbuf;
};



#endif //V_1_MYSTRING_H
