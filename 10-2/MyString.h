//
// Created by 王子龙 on 2019/12/5.
//

#ifndef INC_8_2_MYSTRING_H
#define INC_8_2_MYSTRING_H

#include<iostream>
using namespace std;

class MyString
{
    static int total;    // 此处声明为私有数据成员
public:
    MyString();
    MyString(const char * p);
    MyString(const MyString & s);
    ~MyString();
    MyString & operator=(const MyString & s);

    const char * get_string() const { return m_pbuf; }	// 取得字符串的首地址
    const char * set_string(const char * p = NULL);	// 将p指向的字符串保存在MyString类中
    const char * append(const char * p = NULL);		// 将p指向的字符串追加到原有字符串之后
    MyString & append(MyString & s);					// 将s对象中的字符串追加到当前对象的字符串之后并返回对象
    int get_length() const { return strlen(m_pbuf); }	// 取得保存的字符串的长度

    static int get_total() { return total; }

    char & operator[](const int idx)
    {
        return m_pbuf[idx];
    }

    char operator[](const int idx) const
    {
        return m_pbuf[idx];
    }

    MyString & operator()(const char * p)
    {
        set_string(p);
        return *this;
    }

    operator const char * () const
    {
        return m_pbuf;
    }

    bool operator!=(const MyString & s)
    {
        if (strcmp(m_pbuf, s.m_pbuf) != 0)
            return true;
        else
            return false;
    }

    MyString & read_text(istream & in);		// 文本模式读取函数
    MyString & read_binary(istream & in);	// 二进制模式读取函数
    void write_text(ostream & o) const;			// 文本模式输出函数
    void write_binary(ostream & o) const;			// 二进制模式输出函数
    friend ostream & operator<< (ostream & o, const MyString & s);	// 插入符，文本模式
private:
    char * m_pbuf;
    static int count;
};



#endif //INC_8_2_MYSTRING_H
