//
// Created by 王子龙 on 2019/10/14.
//

#include "MyString.h"
#include <iostream>
using namespace std;
MyString::MyString()
{
    m_pbuf = new char('\0');
}

MyString::MyString(const char *p)
{
    if (NULL == p)
        m_pbuf = new char('\0');
    else
    {
        m_pbuf = new char[strlen(p) + 1];
        strcpy(m_pbuf, p);
    }
}

MyString::MyString(const MyString & str)
{
    {
        m_pbuf = new char[strlen(str.m_pbuf) + 1];
        strcpy(m_pbuf, str.m_pbuf);
    }
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

const char * MyString::get_string() const {
    return m_pbuf;
}

int MyString::get_length()
{
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

const char * MyString::append(const char * p)
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
    delete [] m_pbuf;
}