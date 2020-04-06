#include <iostream>

using namespace std;

int main() {
    int a = 1;
    int b = 0;
    int i = 0;

    cin >> a >> b;

    if (a > b || a < 1 || b > 30000) {
        return -1;
    }

    for (i = a; i <= b; i++) {
        if (!(i % 2)) {
            cout << "" << i;
            if ((i+1) <= b) cout << " ";
        }
    }

    return 0;
}