#include <stdio.h>

int add(int i, int j);

double add(double m , double n);

int main() {
    add(1, 2);
    add(1.0, 2.0);
    return 0;
}
int add(int i = 0, int j = 0){ return i + j; }
double add(double m, double n){ return m + n; }