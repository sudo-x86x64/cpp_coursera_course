#include <iostream>
#include <vector>

using namespace std;

void printVector(const vector<int> &v) {
    for (const auto &i : v)    cout << i << " ";
    cout << endl;
}


int main() {
    vector<int> v = {1, 5, 2, 4, 1, 91};

    cout << "Original vector: "; 
    printVector(v);

    // variable "i" will contain a reference to v's objects instead of deep copy of specific element
    // if we specify "i" as reference
    for (auto &i : v)  i++;

    cout << "Modified vector: "; 
    printVector(v);
    
    return 0;
}
