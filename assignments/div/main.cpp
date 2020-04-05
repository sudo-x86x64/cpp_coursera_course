#include <iostream>

using namespace std;

int main() {
    unsigned a = 0;
    unsigned b = 0;

    cin >> a >> b;

    if (!b) {
        cout << "Impossible" << endl;
        return -1;
    }

    cout << "" << a/b << endl;

    return 0;
}