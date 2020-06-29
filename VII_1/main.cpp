#include<iostream>

using namespace std;

class B
{
    int* p;
public:
    B()
    {
        p = new int[1024 * 1024];
        for (int i = 0; i < 1024 * 1024; i++)
            p[i] = i;
    }

    virtual ~B()
    {
        delete[] p;
    }
    B(const B& b)
    {
        p = new int[1024 * 1024];
        for (int i = 0; i < 1024 * 1024; i++)
            p[i] = b.p[i];
    }
    B& operator= (const B& b)
    {
        if (this != &b)
        {
            for (int i = 0; i < ; i++)
                p[i] = b.p[i];
        }
        return *this;
    }
};

class C : public B
{
    int* p;
public:
    C()
    {
        p = new int[1024 * 1024];
        for (int i = 0; i < 1024 * 1024; i++)
            p[i] = i;
    }

    virtual ~C()
    {
        delete[] p;
    }
    C(const C& c) : B(c)
    {
        p = new int[1024 * 1024];
        for (int i = 0; i < 1024 * 1024; i++)
            p[i] = i;
    }
    C& operator= (const C& c)
    {
        if (this != &c)
        {
            B::operator=(c);    // 调用基类的赋值运算符实现基类数据的赋值
            for (int i = 0; i < 1024 * 1024; i++)
                p[i] = c.p[i];
        }
        return *this;
    }
};

int main()
{
    {
        C c;
        C c3(c);
        c = c3;
    }
    B* p_B = new C;
    delete p_B;

    return 0;
}
