#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Student {
public:
    Student(string other_firstname, string other_lastname, int other_day, int other_month, int other_year) {
        firstname = other_firstname;
        lastname = other_lastname;
        day = other_day;
        month = other_month;
        year = other_year;
    }
    string firstname = "";
    string lastname = "";
    int day = 0;
    int month = 0;
    int year = 0;
};

int main() {
    string firstname, lastname;
    int day, month, year;
    vector<Student> students;
    string operation;
    int k;
    int number_of_students;
    int number_of_entries;

    cin >> number_of_students;

    for (int i = 0; i < number_of_students; i++) {
        cin >> firstname >> lastname >> day >> month >> year;
        students.push_back(Student (firstname, lastname, day, month, year));
    }

    cin >> number_of_entries;

    for (int j = 0; j < number_of_entries; ++j) {
        cin >> operation >> k;
        if (operation == "name" && k > 0 && k <= students.size()) {
            cout << students[k-1].firstname << " " << students[k-1].lastname << endl;
        } else if (operation == "date" && k > 0 && k <= students.size()) {
            cout << students[k-1].day << "." << students[k-1].month << "." << students[k-1].year << endl;
        } else {
            cout << "bad request" << endl;
        }
    }

    return 0;
}