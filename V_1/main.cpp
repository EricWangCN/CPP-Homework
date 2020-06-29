#include <iostream>
#include "SwimmingPool.h"
#include "CSwimpool.h"

int main(int argc, char **argv) {
    char ch = '\0';
    MyString a("1");
    std::cout << a.append("b");
    while (ch != 'e') {
        char name[1000];
        double a, b;
        std::cout << "Enter length, width and name in order.\n";
        std::cin >> a >> b >> name;
        Rectangle r(a, b, name);
        std::cout << "egiruye\n";
        CSwimPool pool(r, 3, 5, 10);
        std::cout << "Cost: " << pool.cost() << "\n\nPress \"e\" to exit, press any other key to continue.\n";
        std::cin >> ch;
    }
    return 0;
}