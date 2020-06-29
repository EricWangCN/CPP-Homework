//
// Created by 王子龙 on 2019/11/12.
//

#ifndef VI_1_MYSTRING_H
#define VI_1_MYSTRING_H

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

    //operator:
    MyString operator+(const MyString &str);
    friend MyString operator+(const MyString & str1, const MyString & str2);
    MyString &operator=(const char * p) {
        this->set_string(p);
        return *this;
    }
    char & operator[](unsigned int idx);
    char operator[] (unsigned int idx) const;
    explicit operator const char * () const { return m_pbuf; }
    bool operator<(const MyString &str){ return strcmp(this->get_string(), str.get_string()) < 0; };
    bool operator<=(const MyString &str){ return strcmp(this->get_string(), str.get_string()) <= 0; };
    bool operator>(const MyString &str){ return strcmp(this->get_string(), str.get_string()) > 0; };
    bool operator>=(const MyString &str){ return strcmp(this->get_string(), str.get_string()) >= 0; };
private:
    char * m_pbuf;
    static int count;
};


#endif //VI_1_MYSTRING_H
