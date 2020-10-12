#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

bool is_number(const string& s) {
    string::const_iterator i = s.begin();
    while (i != s.end() && isdigit(*i)) ++i;
    return !s.empty() && i == s.end();
}

int main () {
    ifstream inputFile("input.txt");
    string number;
    string number_of_rows;
    string number_of_columns;

    if(!inputFile.is_open()) {
        cout << "File was not found!" << endl;
    }

    getline(inputFile, number_of_rows, ' ');
    getline(inputFile, number_of_columns);
    if (!is_number(number_of_rows) || !is_number(number_of_columns)) {
        cout << "input error" << endl;
        return -1;
    }
    
    for (int i = 0; i < stoi(number_of_rows); i++) {
        for (int j = 0; j < stoi(number_of_columns); j++) {
                if (j+1 >=stoi(number_of_columns))      getline(inputFile, number);
                else                                    getline(inputFile, number, ',');
                cout << setw(10) << number;
                if (!(j+1 >=stoi(number_of_columns)))   cout << " "; 
        }
        cout << endl;
    }

    return 0;
}