#include<vector>
#include<iostream>
#include<algorithm>
#include"MyString.h"
using namespace std;

bool _less(int a, int b)
{
    return a < b;
}
bool larger(int a, int b)
{
    return a > b;
}
template<class T>class CLarger // 函数对象
{
public:
    bool operator()(T & a, T & b) {
        return a > b;
    }
};


template<class T, class F>
void Sort(vector<T> & v, F f) {
// 演示 vector 和函数对象等
    cout << "Before:";
    typename vector<T>::iterator iter;
    for(iter = v.begin(); iter < v.end(); iter++)
        cout << " " << *iter; cout << endl;
    sort(v.begin(), v.end(), f); // 从大到小排序
    cout << "After:";
    for(iter = v.begin(); iter < v.end(); iter++)
        cout << " " << *iter; cout << endl;
}

int main() {
    vector<int> v;
    v.push_back(58);
    v.push_back(0);
    v.push_back(86);
    v.push_back(72);
    v.push_back(55);

    cout << "排序前: ";
    vector<int>::iterator iter;
    for(iter = v.begin(); iter < v.end(); iter++)
        cout << " " << *iter; cout << endl;

    sort(v.begin(), v.end(), larger); // 从大到小排序

    cout << "排序后: ";
    for(iter = v.begin(); iter < v.end(); iter++)
        cout << " " << *iter; cout << endl;

    Sort(v, _less);
    Sort(v, CLarger<int>());

    vector<MyString> v2;
    v2.push_back(MyString("58"));
    v2.push_back(MyString("00"));
    v2.push_back(MyString("86"));
    v2.push_back(MyString("72"));
    v2.push_back(MyString("55"));
    Sort(v2, CLarger<MyString>());
    return 0;
}