//
// Created by 王子龙 on 2019/10/29.
//

#include "Alley.h"

Alley::Alley(const Rectangle& rec): rec(rec), WIDTH(3), ALLEY_COST(20), FENCE_COST(35) {}

double Alley::fence_cost() {
    return (rec.get_length() + 2 * WIDTH + rec.get_width() + 2 * WIDTH) * FENCE_COST * 2;
}

double Alley::alley_cost() {
    return ((rec.get_length() + 2 * WIDTH) * (rec.get_width() + 2 * WIDTH)
            - rec.get_length() * rec.get_width()) * ALLEY_COST;
}
