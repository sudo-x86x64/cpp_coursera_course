#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main () {
    vector<int> v;
    int numberOfElements = 0;
    int i = 0;

    cin >> numberOfElements;

    while (numberOfElements) {
        cin >> i;
        v.push_back(i);
        numberOfElements--;
    }

    sort(begin(v), end(v), [](int i, int j){return (abs(i)<abs(j));});
    for(auto &x : v) {
        cout << " " << x;
    }
    cout << endl;
}