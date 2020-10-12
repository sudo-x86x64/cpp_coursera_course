#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    string str;
    cin >> str;

    if (str.find('f') == string::npos) {
        cout << "-2";
        return 1;
    }

    if (count(str.begin(), str.end(), 'f') == 1) {
        cout << "-1";
        return 2;
    }

    str[str.find('f')] = 'a';
    cout << "" << str.find('f');
    
    return 0;
}