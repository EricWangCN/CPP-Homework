//
// Created by 王子龙 on 2019/11/12.
//

#include "MyString.h"
#include <iostream>
using namespace std;
int MyString::total = 0;

MyString::MyString()
{
    total++;
    m_pbuf = new char('\0');
}

MyString::MyString(const char *p)
{
    total++;
    if (nullptr == p)
        m_pbuf = new char('\0');
    else
    {
        m_pbuf = new char[strlen(p) + 1];
        strcpy(m_pbuf, p);
    }
}

MyString::MyString(const MyString & str)
{
    total++;
    m_pbuf = new char[strlen(str.m_pbuf) + 1];
    strcpy(m_pbuf, str.m_pbuf);
}

MyString & MyString::operator=(const MyString & s)
{
    if (this != &s)
    {
        delete[] m_pbuf;
        int len = strlen(s.m_pbuf) + 1;
        m_pbuf = new char[len];
        strcpy(m_pbuf, s.m_pbuf);
    }
    return *this;
}

std::ostream &operator<<(std::ostream &o, const MyString &s) {
    o<<s.get_length()<<" "<<s.m_pbuf;
    return o; //在长度后面加一个空格作为分隔符
}

const char * MyString::get_string() const {
    return m_pbuf;
}

int MyString::get_length() const {
    return strlen(m_pbuf);
}

void MyString::set_string(const char *str)
{
    delete[] m_pbuf;
    if (nullptr == str)
        m_pbuf = new char('\0');
    else
    {
        m_pbuf = new char[strlen(str) + 1];
        strcpy(m_pbuf, str);
    }
}

const char *  MyString::append(const char * p)
{
    int len = strlen(m_pbuf) + strlen(p) + 1;
    char *tmp = new char[len];
    strcpy(tmp, m_pbuf);
    delete[] m_pbuf;
    m_pbuf = new char[len];
    strcpy(m_pbuf, tmp);
    delete[] tmp;
    strcat(m_pbuf, p);
    return m_pbuf;
}

MyString & MyString::append(const MyString & s)
{
    int len = strlen(m_pbuf) + strlen(s.m_pbuf) + 1;
    char *tmp = new char[len];
    strcpy(tmp, m_pbuf);
    delete[] m_pbuf;
    m_pbuf = new char[len];
    strcpy(m_pbuf, tmp);
    strcpy(tmp, s.m_pbuf);
    strcat(m_pbuf, tmp);
    delete[] tmp;
    return *this;
}

MyString::~MyString()
{
    total--;
    delete [] m_pbuf;
}

MyString &MyString::read_text(std::istream &in) {
    delete[] m_pbuf; //首先回收之前的内存
    int len;
    in >> len;
    m_pbuf = new char[len + 1]; in.get();
    in.read(m_pbuf, len); m_pbuf[len] = '\0';
    return *this;
}

MyString &MyString::read_binary(std::istream &in) {
    delete[] m_pbuf; //首先回收之前的内存
    int len;
    in.read((char*)&len,sizeof(int)); //先读取将要读取的字符串的长度
    m_pbuf = new char[len + 1]; //准备接受数据的空间:要多一个字节用于保存零字符
    in.read(m_pbuf, len); //读取len个字节到m_pbuf指向的空间
    m_pbuf[len] = '\0'; //在最后加上结尾符号return *this;
    return *this;
}

void MyString::write_text(std::ostream &o) {
    o << *this;
}

void MyString::write_binary(std::ostream &o) {
    int len = strlen(m_pbuf); //取得字符串占用的空间的大小，即字符串的长度
    o.write((char *) &len, sizeof(int)); //在输出流中写入字符串所占空间的大小
    o.write(m_pbuf, len);//从m_pbuf开始写入len个字节;注意最后一个零字符并未写入
}

MyString MyString::operator+(const MyString &str) {
    MyString tmp(*this);
    tmp.append(str);
    return tmp;
}

MyString operator+(const MyString &str1, const MyString &str2) {
    MyString tmp(str1);
    tmp.append(str2);
    return tmp;
}

char &MyString::operator[](unsigned int idx) {
    if(idx >= strlen(m_pbuf)) exit(1);
    return m_pbuf[idx];
}

char MyString::operator[](unsigned int idx) const {
    if(idx >= strlen(m_pbuf)) exit(1);
    return m_pbuf[idx];
}
