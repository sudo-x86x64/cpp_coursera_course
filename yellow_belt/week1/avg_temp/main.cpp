#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<double> temperature;
    vector<unsigned> days_numbers;
    int days = 0;
    double temp = 0;
    double avg = 0;
    size_t i = 0;

    cin >> days;

    while (days) {
        cin >> temp;

        avg += temp;
        temperature.push_back(temp);

        days--;
    }
    
    avg /= static_cast<double>(temperature.size());

    for (i = 0; i < temperature.size(); i++) {
        if (temperature[i] > avg) days_numbers.push_back(i);
    }

    cout << days_numbers.size() << endl;
    for (auto x:days_numbers)   cout << x << " ";
    
    return 0;
}