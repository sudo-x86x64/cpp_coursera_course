#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main() {
    string stopName;
    unsigned numberOfOperations = 0;
    unsigned routeNumber = 1;
    unsigned numberOfStops = 0;
    unsigned i = 0;    

    vector<string> stopsOfRoute;
    map<vector<string>, int> routes;

    cin >> numberOfOperations;


    for (i = 0; i < numberOfOperations; i++) {

        cin >> numberOfStops;

        while (numberOfStops > 0) {
            cin >> stopName;
            stopsOfRoute.push_back(stopName);

            numberOfStops--;
        }

        if (!routes.count(stopsOfRoute)) {
            routes[stopsOfRoute] = routeNumber;
            cout << "New bus " << routeNumber << endl;
            routeNumber++;
        } else {
            cout << "Already exists for " << routes[stopsOfRoute] << endl;
        }

        stopsOfRoute.clear();
    }
    
    return 0;
}
