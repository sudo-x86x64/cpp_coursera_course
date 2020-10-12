#include <iostream>
#include <vector>

using namespace std;

int main() {

    int n = 0;
    int i = 0;
    int inputTemperature = 0;
    int averageTemperature = 0;
    vector<int> temperatureValues;
    vector<int> higherThanAverageTemp;

    cin >> n;

    if (!n || n < 0) {
        return -1;
    }

    for (i = 0; i < n; i++) {
        cin >> inputTemperature;
        temperatureValues.push_back(inputTemperature);
        averageTemperature += inputTemperature;
    }

    averageTemperature /= temperatureValues.size();

    for (i = 0; i < temperatureValues.size(); i++) {
        if (temperatureValues[i] > averageTemperature) {
            higherThanAverageTemp.push_back(i);
        }
    }

    cout << higherThanAverageTemp.size() << endl;
    for (auto x:higherThanAverageTemp) {
        cout << x << " ";
    }

    return 0;
}