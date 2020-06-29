#include "stack.h"

using namespace std;

int main() {
    //Start test stack
    cout << "Start test stack\n";
    STACK<int> s;
    int *p;
    for(int i = 0; i < 10; i++) {
        p = new int(i);
        s.push(p);
    }
    STACKIterator<int> iter(s);
    for(int i = 0; i < 10; i++) {
        p = s.pop();
        cout << *p << ' ';
        delete p;
    }
    cout << endl;
    while(iter) {
        cout << *iter.current() << ' ';
        iter++;
    }
    cout << endl;
    //delete p;
    return 0;
}