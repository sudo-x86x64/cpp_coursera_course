#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printVector(const vector<int> &v) {
    for (auto i : v)    cout << i << " ";
    cout << endl;
}

int main() {
    int threshold = 0;
    vector<int> v = {1, 5, 2, 4, 1, 91};

    cin >> threshold;

    printVector(v);

    sort(begin(v), end(v));
    cout << "Sorted vector: ";
    printVector(v);

    cout << "Count of element \"1\": " << count (begin(v), end(v), 2) << endl;
    cout << "Count of elements greater then \"1\": " << 
            count_if(begin(v), end(v), [threshold](int x) 
                {return (x > threshold) ? true : false;}) << endl;

    return 0;
}