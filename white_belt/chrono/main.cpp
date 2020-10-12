#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

void vectorAsParameter(vector<unsigned> v) {
    cout << "vectorAsParameter " << v.size() << endl;
}

void vectorAsReference(const vector<unsigned>& v) {
    cout << "vectorAsReference: " << v.size() << endl;
}

int main() {
    vector<unsigned> v;
    unsigned i = 0;

    for (i = 0; i < 0xFFBEEF; i++) {
        v.push_back(i);
    }  

    cout << "Vector computed" << endl;

    auto start = steady_clock::now();
    vectorAsParameter (v);
    auto finish = steady_clock::now();

    cout << "vectorAsParameter took: " <<  duration_cast<milliseconds>(finish-start).count() << endl;

    start = steady_clock::now();
    vectorAsReference (v);
    finish = steady_clock::now();

    cout << "vectorAsParameter took: " <<  duration_cast<milliseconds>(finish-start).count() << endl;

    return 0;
}