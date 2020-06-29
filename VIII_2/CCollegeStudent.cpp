//
// Created by 王子龙 on 2019/12/2.
//

#include "CCollegeStudent.h"

ostream &operator<<(ostream &o, const CCollegeStudent &s) {
    o << s.number << " " << s.name << s.major << s.score;
    o << " "; //再输出一个空格，以防止两个学生的信息连在一起无法区分
    return o;
}
