//
// Created by 王子龙 on 2019/11/5.
//

#ifndef V_1_CSWIMPOOL_H
#define V_1_CSWIMPOOL_H


#include "Rectangle.h"
class CSwimPool
{
public:
    CSwimPool(Rectangle & p, double width, double alley_cost, double fence_cost) : g(p), WIDTH(width), ALLEY_COST(alley_cost), FENCE_COST(fence_cost)
    { }
    double cost() const{ return FENCE_COST * g.perimeter(WIDTH) + ALLEY_COST * g.area(WIDTH); }
private:
    Rectangle &g;
    const double WIDTH;
    const double ALLEY_COST;
    const double FENCE_COST;
};


#endif //V_1_CSWIMPOOL_H