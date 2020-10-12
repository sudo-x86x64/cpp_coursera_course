#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Person {
    string firs_name;
    string surname;
    unsigned age;
};

int main () {
    vector<Person> staff;
    staff.push_back({"Harry", "Potter", 25});
    staff.push_back({"Hagrid", "Rubeus", 65});

    cout << staff[0].firs_name << " " << staff[0].surname << " is " << staff[0].age << " years old" << endl;

    return 0;
}
