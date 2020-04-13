#include <iostream>
#include <map>

using namespace std;

void countSymbols(map<char, unsigned>& m, const string& word) {
    for (char x : word) {
        m[x]++;
    }
}

int main() {
    map<char, unsigned> firstMap;
    map<char, unsigned> secondMap;
    string str1;
    string str2;
    int n = 0;
    int i = 0;

    cin >> n;
    if (n <= 0) {
        return -1;
    }

    for (i = 0; i < n; i++) {
        cin >> str1 >> str2;

        countSymbols(firstMap, str1);
        countSymbols(secondMap, str2);
       
        if (firstMap == secondMap)  cout << "YES" << endl;
        else                        cout << "NO" << endl;
        
        firstMap.clear();
        secondMap.clear();
    }

    return 0;
}