#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

 vector<int> Reversed(const vector<int>& v){
    vector<int> returnVector = v;
    std::reverse(returnVector.begin(),returnVector.end());
    return returnVector;
}
/*
int main() {
    vector<int> numbers = {1, 5, 3, 4, 2};
    vector<int> a = Reversed(numbers);

    for(auto x:a) {
        cout << x << endl;
    }

    return 0;
}*/