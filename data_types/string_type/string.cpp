#include <iostream>
#include <string>

using namespace std;

int main () {
    string a = "This is string a!";
    string b = "This is string b!";

    if (a == b) cout << "Strings are equal" << endl;
    else        cout << "Strings are not equal" << endl;

    // Strings in C++ are compared lexicographically
    if (a > b)  cout << "String a has higher value" << endl;
    else        cout << "String a has lower or similar value" << endl;

    return 0;
}
