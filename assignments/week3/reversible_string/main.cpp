#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class ReversibleString {
    string str;
public:
    ReversibleString() {str = "";}
    ReversibleString(const string& initializationString) {
        str = initializationString;
    }
    void Reverse() {
        reverse(str.begin(), str.end());
    }
    const string& ToString() const {
        return str;
    }
};

