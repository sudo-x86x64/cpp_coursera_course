#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

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

vector<string> PalindromFilter (vector<string> words, int minLength) {
    vector<string> result;

    for (auto w : words) {
        if (w.size() < minLength)   continue;
        if (IsPalindrom(w))         result.push_back(w);
    }

    return result;
}
