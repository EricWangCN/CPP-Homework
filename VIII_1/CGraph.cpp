//
// Created by 王子龙 on 2019/11/29.
//

#include "CGraph.h"

CRectangle::CRectangle(const char * p, double h, double w) : CGraph(p), height(h), width(w) {
}
CRectangle::CRectangle(const CRectangle & r) : CGraph(r), height(r.height), width(r.width) {
}
double CRectangle::area()
{
    return height * width;
}
double CRectangle::perimeter()
{
    return 2 * (height + width);
}
CCircle::CCircle(const char * p, double r) : CGraph(p), radius(r)
{
}
CCircle::CCircle(const CCircle & c) : CGraph(c), radius(c.radius) {
}
double CCircle::area()
{
    return PI * radius * radius;
}
double CCircle::perimeter()
{
    return 2 * PI * radius;
}
CTriangle::CTriangle(const char * p, double a, double b, double c) : CGraph(p), s1(a), s2(b), s3(c) {
}
CTriangle::CTriangle(const CTriangle & t) : CGraph(t), s1(t.s1), s2(t.s2), s3(t.s3) {
}
double CTriangle::area()
{
    double p = (s1 + s2 + s3) / 2;
    return pow(p * (p - s1) * (p - s2) * (p - s3), 0.5);
}
double CTriangle::perimeter()
{
    return s1 + s2 + s3;
}
