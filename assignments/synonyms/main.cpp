#include <iostream>
#include <set>
#include <map>
#include <vector>

using namespace std;

void addWords (map<string, set<string>> &m) {
    string firstWord;
    string secondWord;

    cin >> firstWord >> secondWord;

    m[firstWord].insert(secondWord);
    m[secondWord].insert(firstWord);
}

void countWord(map<string, set<string>> &m) {
    string word;
    set<string> synonyms;

    cin >> word;

    cout << m[word].size() << endl;
}

void checkSynonyms(map<string, set<string>> &m) {
    string firstWord;
    string secondWord;

    cin >> firstWord >> secondWord;

    if (m[firstWord].count(secondWord)) {
        cout << "YES" << endl;
        return;
    } 

    cout << "NO" << endl;
}

int main() {
    map<string, set<string>> synonyms;

    int numberOfOperations = 0;
    string operation;

    cin >> numberOfOperations;

    while (numberOfOperations) {
        cin >> operation;

        if (operation == "ADD") {
            addWords(synonyms);
        } else if (operation == "COUNT") {
            countWord(synonyms);
        } else if (operation == "CHECK") {
            checkSynonyms (synonyms);
        }
        numberOfOperations--;
    }
    return 0;
}