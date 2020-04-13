#include <iostream>
#include <vector>

using namespace std;

#define WORRY 1
#define QUITE 0

class person {
public:
    unsigned state;
    person () {
        this->state = QUITE;
    }
};

unsigned worryCout (vector<person *>& q) {
    unsigned count = 0;
    for (auto x:q)  if (x->state == WORRY) count++;
    return count;
}

void addPersonToQueue(vector<person *>& q, int numberOfPersons) {
    int i = 0;
    for (i = 0; i < numberOfPersons; i++) {
        q.push_back(new person());
    }
}

void markPersonAsWorried(vector<person *>& q, int index) {
    q[index]->state = WORRY;
}

void markPersonAsQuite(vector<person *>& q, int index) {
    q[index]->state = QUITE;   
}

void removePersonFromQueue(vector<person *>& q, int n) {
    int i = 0;
    n *= -1;
    if (!q.size()) return;
    if (q.size() < n) return;

    for (i = 0; i < n; i++) {
        delete q[q.size() - 1];
        q.pop_back();
    }
}

bool checkIfInputIsNumneric() {
    if(cin.fail()) {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return false;
    }
    return true;
}

void clearQueue(vector<person *>& q) {
    for (auto p : q) {
        delete p;
    } 
    q.clear();
}

int main () {
    int numberOfOperations = 0;
    int i = 0;
    int comeOperationValue = 0;
    int personIndex  = 0;
    string operation;
    vector<person *>  queue;

    cin >> numberOfOperations;
    if (!checkIfInputIsNumneric()) return -1;
    if (!numberOfOperations || numberOfOperations <= 0) return -2;

    while (i < numberOfOperations) {
        cin >> operation;

       if (operation == "WORRY_COUNT") {
           cout << endl;
           cout << worryCout(queue) << endl;
       } else if (operation == "COME") {
            cin >> comeOperationValue;
            if (!checkIfInputIsNumneric()) continue;

            if (comeOperationValue > 0) {
                addPersonToQueue(queue, comeOperationValue);
            }
            if (comeOperationValue < 0) {
                removePersonFromQueue(queue, comeOperationValue);
            }
       } else if (operation == "WORRY") {
            cin >> personIndex;
            if (!checkIfInputIsNumneric()) continue;

            if (personIndex >= 0) {
                markPersonAsWorried(queue, personIndex);
            }
        } else if (operation == "QUIET") {
            cin >> personIndex;
            if (!checkIfInputIsNumneric()) continue;

            if (personIndex >= 0) {
                markPersonAsQuite(queue, personIndex);
            }
        } 

        i++;
    }

    clearQueue(queue);

    return 0;
}