//
// Created by 王子龙 on 2019/11/29.
//

#ifndef VIII_1_SWIMPOOL_H
#define VIII_1_SWIMPOOL_H


#include "CGraph.h"

// 简化起见，我们只设计一个游泳池类，并设计计算其面积和周长的函数
class CSwimPool
{
public:
// 将形参p指向的空间(必须在堆中分配)交给CSwimPool类管理，此时该类的g指针指向上述内存
    CSwimPool(CGraph * p) { g = p; }
/* 类似于这个的写法是错误的，原因是CGraph应是抽象类，不能定义其对象;memcpy函数也只能实现浅 复制，且只能复制CGraph类中的数据
     CSwimPool::CSwimPool(const CGraph * p)
     {g = new CGraph;
memcpy(g, p, sizeof(CGraph));
}
*/
    virtual ~CSwimPool() { if (g != NULL) delete g; }
    double area() { return g != NULL ? g->area() : -1; }
    double perimeter() { return g != NULL ? g->perimeter() : -1; }
//对于文件读写，由于无法预测其图形类到底是什么，所以只能通过调用对应的虚函数完成读写 //对于指示具体图形类型的标记，应该在类的外部确定
    std::ostream & write_text(std::ostream & o)
    {
        g->write_text(o);
        return o;
    }
    std::ifstream & read_text(std::ifstream & in) {
        g->read_text(in);
        return in;
    }
    std::ostream & write_binary(std::ostream & o) {
        g->write_binary(o);
    }

private:
    CSwimPool(const CSwimPool & pool);
    CSwimPool & operator=(const CSwimPool & pool); //声明为私有函数，防止对象调用该函数
    CGraph * g;
};

#endif //VIII_1_SWIMPOOL_H
