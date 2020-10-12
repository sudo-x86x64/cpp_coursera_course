#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

class SortedStrings {
public:
    void AddString(const string& s) {
        this->str.push_back(s);    
    }
    vector<string> GetSortedStrings() {
        sort(begin(this->str), end(this->str));
        return this->str;
    }
private:
    vector<string> str;
};

void PrintSortedStrings(SortedStrings& strings) {
    for (const string& s : strings.GetSortedStrings()) {
        cout << s << " ";
    }
    cout << endl;
}

int main() {
    SortedStrings strings;
  
    strings.AddString("first");
    strings.AddString("third");
    strings.AddString("second");
    PrintSortedStrings(strings);
  
    strings.AddString("second");
    PrintSortedStrings(strings);
  
    return 0;
}