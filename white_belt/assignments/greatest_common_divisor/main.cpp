#include <iostream>

using namespace std;

int main() {
    unsigned a = 0;
    unsigned b = 0;

    cin >> a >> b;

    while (a >0 && b > 0) {
        if (a > b) {
            a %= b;
        } else {
            b %= a;
        }
    }

    cout << a+b;
    
    return 0;
}