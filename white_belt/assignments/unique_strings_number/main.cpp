#include <iostream>
#include <set>

using namespace std;

int main() {
    int numberOfStrings = 0;
    string inputString;
    set<string> strSet;

    cin >> numberOfStrings;

    while (numberOfStrings) {
        cin >> inputString;
        strSet.insert(inputString);
        numberOfStrings--;
    }

    cout << strSet.size() << endl;

    return 0;
}