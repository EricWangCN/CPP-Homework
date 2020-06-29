//
// Created by 王子龙 on 2019/11/1.
//

#ifndef V_2_MYSTRING_H
#define V_2_MYSTRING_H

#include <iostream>
class MyString {
    static int total;
public:
    MyString();
    MyString(const char *p);
    MyString(const MyString & str);
    ~MyString();

    static int get_total() { return total; }

    int get_length() const;
    MyString & operator=(const MyString & s);
    const char * get_string() const;
    void set_string(const char *str = nullptr);
    const char * append(const char * p = nullptr);
    MyString & append(const MyString &s);

    MyString & read_text(std::istream & in);
    MyString & read_binary(std::istream & in);
    void write_text(std::ostream & o);
    void write_binary(std::ostream & o);

    friend std::ostream & operator<< (std::ostream & o, const MyString & s);
private:
    char * m_pbuf;
    static int count;
};


#endif //V_2_MYSTRING_H
