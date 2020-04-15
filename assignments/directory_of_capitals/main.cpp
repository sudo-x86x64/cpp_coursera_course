#include <iostream>
#include <map>

using namespace std;

int main() {
    int n = 0;
    int i = 0;
    map<string, string> capitals;
    string operation;
    string country;
    string oldCountry;
    string city;

    cin >> n;

    for(i = 0; i < n; i++) {
        cin >> operation;

        if (operation == "CHANGE_CAPITAL") {
            cin >> country >> city;
            
            if (!capitals.count(country)) {
                cout << "Introduce new country " << country << " with capital " << city << endl;
                capitals[country] = city;
            } else  if (capitals[country] == city) {
                cout << "Country " << country << " hasn't changed its capital" << endl;
            } else {
                cout << "Country " << country << " has changed its capital from " << capitals[country] << " to " << city << endl;
                capitals[country] = city;
            }
        } else if (operation == "RENAME") {
            cin >> oldCountry >> country;
            if (!capitals.count(oldCountry) 
                || capitals.count(country)
                ||(oldCountry == country) ) {
                    cout << "Incorrect rename, skip" << endl;
                    continue;
            }
            cout <<"Country "<< oldCountry << " with capital " << capitals[oldCountry] << " has been renamed to " << country << endl;
            capitals[country] = capitals[oldCountry];
            capitals.erase(oldCountry);
        } else if (operation == "ABOUT") {
            cin >> country;
            if (!capitals.count(country)) {
                cout << "Country " << country << " doesn't exist" << endl;
            } else {
                cout << "Country " << country << " has capital " << capitals[country] << endl;
            }   
        } else if (operation == "DUMP") {
            if(!capitals.size()) {
                cout << "There are no countries in the world" << endl;
            } else {
                for (auto x : capitals) {
                    cout << x.first << "/" << x.second << " ";
                }
                cout << endl;
            }
        }
    }

    return 0;
}