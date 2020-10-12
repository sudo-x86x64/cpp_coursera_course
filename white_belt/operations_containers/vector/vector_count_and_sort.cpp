#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main () {
    vector<unsigned> numbers = { 1, 2 , 3, 5 , 5, 0, 5};
    unsigned repetitions = 0;

    repetitions = count (begin(numbers), end(numbers), 5);
    cout << repetitions << endl;

    sort(begin(numbers), end(numbers));
    for (auto x: numbers) cout << x << " ";
    cout << endl;

    return 0;
}
