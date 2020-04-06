#include <iostream>
#include <vector>

using namespace std;

int main() {
    int num = 0;
    int i = 0;
    vector<unsigned> bits;
    
    cin >> num;

    while (num) {
        bits.push_back(num & 0x1);
        num >>= 1;
    }

    for (i = bits.size() - 1; i >=0; i--) {
        cout << bits[i];
    }

    return 0;
}