//
// Created by 王子龙 on 2019/10/29.
//

#ifndef V_1_ALLEY_H
#define V_1_ALLEY_H

#include "Rectangle.h"
class SwimmingPool;
class Alley {
public:
    Alley(const Rectangle& rec);
    double alley_cost();
    double fence_cost();
private:
    Rectangle rec;
    const double WIDTH;
    const double ALLEY_COST;
    const double FENCE_COST;
};


#endif //V_1_ALLEY_H
