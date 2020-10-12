#include <iostream>
#include <vector>

using namespace std;

int main () {
    vector<string> w = { "a", "b", "c"};
    vector<string> v;

    v = w;
    v[0] = "d";

    for (auto x : w) {
        cout << x << " ";
    }

    cout << endl;

    for (auto x : v) {
        cout << x << " ";
    }

    return 0;
}