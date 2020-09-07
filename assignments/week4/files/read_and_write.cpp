#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main () {
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");
    string line;
    
    if(!inputFile.is_open()) {
        cout << "File was not found!" << endl;
    }

    while (getline(inputFile, line)) {
        cout << line << endl;
        outputFile << line << endl;
    }

    inputFile.close();

    return 0;
}