#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool IsPalindrom(string word) {
    if (!word.size()) {
        return true;
    }

    string original_string = word;

    reverse(word.begin(), word.end());
    if (word == original_string)    return true;
    else                            return false;
}
