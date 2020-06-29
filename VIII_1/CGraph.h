//
// Created by 王子龙 on 2019/11/29.
//

#ifndef VIII_1_CGRAPH_H
#define VIII_1_CGRAPH_H
#include <iostream>
#include <math.h>
#include <fstream>
#include "MyString.h"

#define PI 3.1415926535

class CGraph
{
public:
    CGraph() : name("graph") { }
    CGraph(const char * p) : name(p) { } //即使没有使用堆上的内存也应该为基类提供虚析构函数
    virtual ~CGraph() { std::cout << "~CGraph" << std::endl; }
    virtual double area() = 0;
    virtual double perimeter() = 0;
//以文本模式保存和读取文件(二进制模式的请大家自行实现)
    virtual std::ostream & write_text(std::ostream & o) {
        name.write_text(o);
        return o;
    }
    virtual std::ifstream & read_text(std::ifstream & in) {
        name.read_text(in);
        return in;
    }
    virtual std::ostream & write_binary(std::ostream & o) {
        name.write_binary(o);
        return o;
    }
    virtual std::ifstream & read_binary(std::ifstream & in) {
        name.read_binary(in);
        return in;
    }
private:
    MyString name;
};

class CRectangle : public CGraph {
//提供默认构造函数
public:
    CRectangle() : CGraph("rectangle"), height(0), width(0) { }
    CRectangle(const char * p, double h,double w);
    CRectangle(const CRectangle & r); //由于基类的析构函数是虚的，所以即使这里不声明为虚的，它也是虚的
    ~CRectangle() { std::cout << "~CRectangle" << std::endl; }
    double area();
    double perimeter();
//文本模式的文件读写
    virtual std::ostream & write_text(std::ostream & o) {
        CGraph::write_text(o);
        o << " " << height << " " << width << " " << std::endl; return o;
    }
    virtual std::ifstream & read_text(std::ifstream & in) {
        CGraph::read_text(in);
        in.get();
        in >> height >> width;
        in.get();
        return in;
    }
    virtual std::ostream & write_binary(std::ostream & o) {
        CGraph::write_binary(o);
        o.write((char*)&height, sizeof(double));
        o.write((char*)&width, sizeof(double));
        return o;
    }
    virtual std::ifstream & read_binary(std::ifstream & in) {
        CGraph::read_binary(in);
        in.get((char*)&height, sizeof(double));
        in.get((char*)&width, sizeof(double));
        return in;
    }
private:
    double height;
    double width;
};

class CCircle : public CGraph
{
public:
    CCircle() : CGraph("circle"), radius(0) { }
    CCircle(const char * p, double r);
    CCircle(const CCircle & c);
    ~CCircle() { std::cout << "~CCircle" << std::endl; }
    double area();
    double perimeter();
//文本模式的文件读写
    virtual std::ostream & write_text(std::ostream & o) {
        CGraph::write_text(o);
        o << " " << radius << " " << std::endl;
        return o;
    }
    virtual std::ifstream & read_text(std::ifstream & in) {
        CGraph::read_text(in);
        in.get();
        in >> radius;
        in.get();
        return in;
    }
    virtual std::ostream & write_binary(std::ostream & o) {
        CGraph::write_binary(o);
        o.write((char*)&radius, sizeof(double));
        return o;
    }
    virtual std::ifstream & read_binary(std::ifstream & in) {
        CGraph::read_binary(in);
        in.get((char*)&radius, sizeof(double));
        return in;
    }
private:
    double radius;
};

class CTriangle : public CGraph
{
public:
    CTriangle() : CGraph("triangle"), s1(0), s2(0), s3(0) { }
    CTriangle(const char * p, double a, double b, double c);
    CTriangle(const CTriangle & t);
    ~CTriangle() { std::cout << "~CTriangle" << std::endl; }
    double area();
    double perimeter();
//文本模式的文件读写
    virtual std::ostream & write_text(std::ostream & o) {
        CGraph::write_text(o);
        o << " " << s1 << " " << s2 << " " << s3 << " " << std::endl; return o;
    }
    virtual std::ifstream & read_text(std::ifstream & in) {
        CGraph::read_text(in); in.get();
        in >> s1 >> s2 >> s3; in.get();
        return in;
    }
    virtual std::ostream & write_binary(std::ostream & o) {
        CGraph::write_binary(o);
        o.write((char*)&s1, sizeof(double));
        o.write((char*)&s2, sizeof(double));
        o.write((char*)&s3, sizeof(double));
        return o;
    }
    virtual std::ifstream & read_binary(std::ifstream & in) {
        CGraph::read_binary(in);
        in.get((char*)&s1, sizeof(double));
        in.get((char*)&s2, sizeof(double));
        in.get((char*)&s3, sizeof(double));
        return in;
    }
private:
    double s1, s2, s3;
};


#endif //VIII_1_CGRAPH_H