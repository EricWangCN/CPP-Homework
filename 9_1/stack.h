//
// Created by 王子龙 on 2019/12/10.
//

#ifndef INC_9_1_STACK_H
#define INC_9_1_STACK_H
#include<iostream>
template <class T> class STACKIterator;

template<class T> class STACK {
    friend class STACKIterator<T>;
public:
    STACK() : head(NULL) { }
    ~STACK()
    {
        link * cur = head;
        while (NULL != head) {
            cur = cur->next;
            delete head->data;
            delete head;
            head = cur;
        }
    }
    void push(T * Data) { head = new link(Data, head); }
    T * pop()
    {
        if (NULL == head) return NULL;
        else {
            T * result = head->data;
            link * oldhead = head;
            head = head->next;
            delete oldhead;
            return result;
        }
    }
    T *peek() const { return head->data; }
private:
    struct link {
        link * next;
        T * data;
        link(T * Data, link * Next) {
            data = Data;
            next = Next;
        }
    }
    *head;
    /*
public:
     STACK() : head(NULL) {}
     ~STACK();
     void push(T *Data) { head = new link(Data, head); }
     T *pop();
     T *peek() const { return head->data; }
 private:
     struct link {
         link *next;
         T *data;

         link(T *Data, link *Next) {
             data = Data;
             next = Next;
         }
     }
     *head;*/
};

template<class T> class STACKIterator {
public:
    STACKIterator(const STACK<T> & t) : p(t.head) { }
    STACKIterator(const STACKIterator & t) : p(t.p) { }
    STACKIterator & operator++() // 前置++运算符
    {
        if(NULL != p->next) p = p->next;
        else p = NULL;
        return *this;
    }
    STACKIterator & operator++(int) // 后置++运算符
    {
        return operator++();
    }
    T * current() const
    {
        if(NULL == p)
            return NULL;
        return p->data;
    }
    operator bool() const // 自动类型转换
    {
        return NULL == p ? false : true;
    }
private:
    typename STACK<T>::link * p;
};
#endif //INC_9_1_STACK_H
