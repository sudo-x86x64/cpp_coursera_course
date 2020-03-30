#include <iostream>
#include <string>
#include <map>

using namespace std;

int main () {

    map<string, int> string_to_int_map;
    
    string_to_int_map["one"] = 1;
    string_to_int_map["two"] = 2;

    cout << "String two is associated with int number: " << string_to_int_map["two"] << endl;

    return 0;
}
