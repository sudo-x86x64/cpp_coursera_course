#include <iostream>
#include <string>

using namespace std;

int main() {
    string a = "Hello";
    string b = a;

    b += ", world!";

    cout << "String a is " << a << endl;
    cout << "String b is " << b << endl;

    return 0;
}
