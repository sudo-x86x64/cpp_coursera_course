#include <iostream>
#include <map>
#include <set>

using namespace std;

set<string> BuildMapValuesSet(const map<int, string>& m) {
    set<string> values;

    for (auto &x:m) {
        values.insert(x.second);
    }

    return values;
}