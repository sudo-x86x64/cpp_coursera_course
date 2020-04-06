#include <iostream>

using namespace std;

int Factorial (int a) {
    if (a <= 0)  return 1;
    if (a == 1) return a;

    int res = 1;
    res *= a;

    res *= Factorial (a-1);

    return res;
}