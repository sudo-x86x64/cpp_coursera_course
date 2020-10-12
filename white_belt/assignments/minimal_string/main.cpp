#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define MAX_INPUT_STRING_LENGTH 30
int main () {
    string a, b ,c;

    cin >> a >> b >> c;

    if (a < b) {
        if (a < c)  cout << a;
        else        cout << c;
    } else {
        if (b < c)  cout << b;
        else        cout << c;
    }

    return 0;
}
