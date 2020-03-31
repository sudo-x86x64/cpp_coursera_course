#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string my_string = "Containers exercie";
    vector<unsigned> numbers = {1, 2, 3 ,5 , 99, 100};

    for (char c: my_string) {
        cout << c << " ";
    }
    cout << endl;

    for (auto i: numbers) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
