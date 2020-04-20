#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

void busesForStop(map<string, vector<string>> &stopsMap) {
    string stopName;

    cin >> stopName;

    if (!stopsMap.count(stopName)) {
        cout << "No stop" << endl;
        return;
    }
            
    for (auto const &bus:stopsMap[stopName]) {
        cout << bus << " ";
    }
    cout << endl;
}

void newBus(map<string, vector<string>> &routesMap, map<string, vector<string>> &stopsMap) {
    string busName;
    string stopName;
    int numberOfStops = 0;

    cin >> busName >> numberOfStops;

    while (numberOfStops > 0) {
        cin >> stopName;
        routesMap[busName].push_back(stopName);
        stopsMap[stopName].push_back(busName);
        numberOfStops--;
    }        
}

void allBuses(map<string, vector<string>> &routesMap) {
    if (!routesMap.size())   {
        cout << "No buses" << endl;
        return;
    }
    for (auto bus:routesMap) {
        cout << "Bus " << bus.first << ": ";
        for (auto stop:bus.second) {
            cout << " " << stop;
        }
        cout << endl;
    }
}

void stopsForBus(map<string, vector<string>> &routesMap,  map<string, vector<string>> &stopsMap) {
    string busName;

    cin >> busName;
    
    if (!routesMap.count(busName))  {
        cout << "No bus" << endl;
        return;
    }
    for (auto stop : routesMap[busName]) {
        cout << "Stop " << stop << ": ";
        if (stopsMap[stop].size() == 1){                    
            for (auto x:stopsMap[stop]) {
                if(x == busName){
                    cout << "no interchange" << endl;
                }
            }
            return;
        }
        for (auto bus : stopsMap[stop]) {
            if (bus == busName) return;
            cout << bus << " "; 
        }
        cout << endl;
    }
}

int main() {
    
    string operation;
    unsigned numberOfOperations = 0;
    unsigned i = 0;    

    map<string, vector<string>> routesMap;
    map<string, vector<string>> stopsMap;

    cin >> numberOfOperations;

    for (i = 0; i < numberOfOperations; i++) {

        cin >> operation;

        if (operation == "NEW_BUS") {            
            newBus (routesMap, stopsMap);
        } else if (operation == "ALL_BUSES") {
            allBuses(routesMap);
        } else if (operation == "BUSES_FOR_STOP") {
            busesForStop (stopsMap);    
        } else if (operation == "STOPS_FOR_BUS") {
            stopsForBus(routesMap, stopsMap);
        }
    }
    
    return 0;
}
