//
// Created by 王子龙 on 2019/10/29.
//

#ifndef V_1_SWIMMINGPOOL_H
#define V_1_SWIMMINGPOOL_H

#include "Rectangle.h"
#include "Alley.h"
class SwimmingPool {
public:
    double compute_cost() { return FENCE_COST * rec.perimeter() + ALLEY_COST * rec.area(); };
    SwimmingPool(const Rectangle& rec,double width,double alley_cost, double fence_cost): rec(rec),
        WIDTH(width),ALLEY_COST(alley_cost),FENCE_COST(fence_cost){};
private:
    Rectangle rec;
    const double WIDTH;
    const double ALLEY_COST;
    const double FENCE_COST;
};


#endif //V_1_SWIMMINGPOOL_H
