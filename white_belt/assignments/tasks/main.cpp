#include <iostream>
#include <vector>

using namespace std;

class Calendar {
public:
    unsigned days_in_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30 , 31, 30, 31};
    unsigned currentMonthNumber = 0;

    Calendar() {
    }

    void setCurrentMonthToNext () {
        this->currentMonthNumber = (this->currentMonthNumber + 1) % 12; 
    }

    unsigned getCurrentMonthNumnber() {
        return this->currentMonthNumber;
    }

    unsigned getNumberOfDaysInPrevMonth () {
        if (!this->currentMonthNumber) return this->days_in_month[11];
        return this->days_in_month[this->currentMonthNumber - 1];
    }

    unsigned getNumberOfDaysInCurrentMonth() {
        return this->days_in_month[this->currentMonthNumber];
    }
};

bool checkIfInputIsNumneric() {
    if (cin.fail()) {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return false;
    }
 
    return true;
}

int main () {
    int numberOfCommands = 0;
    int i = 0;
    int differenceOfDays = 0;
    int dayNumber = 0;
    string taskName;
    string operation;
    Calendar calendar;
    vector<vector<string>> currentMonth(calendar.getNumberOfDaysInCurrentMonth());
    vector<vector<string>> tmp;

    cin >> numberOfCommands;
    if (!checkIfInputIsNumneric())  return -1;

    while (i < numberOfCommands) {
        cin >> operation;

        if (operation == "ADD") {
            cin >> dayNumber;
            
            if (dayNumber > calendar.getNumberOfDaysInCurrentMonth()) {
                cin >> taskName;
                i++;
                continue;
            }

            cin >> taskName;
            currentMonth[dayNumber - 1].push_back(taskName);
        } else if (operation == "DUMP") {
            cin >> dayNumber;
            
            if (dayNumber > calendar.getNumberOfDaysInCurrentMonth()) {
                cin >> taskName;
                i++;
                continue;
            }

            cout << currentMonth[dayNumber - 1].size() << " ";
            for (auto x:currentMonth[dayNumber - 1]) cout << x << " ";
            cout << endl;
        } else if (operation == "NEXT") {
            calendar.setCurrentMonthToNext();
            if (calendar.getNumberOfDaysInPrevMonth() == calendar.getNumberOfDaysInCurrentMonth()) {
                i++;
                continue;
            }
            tmp = currentMonth;
            currentMonth.resize(calendar.getNumberOfDaysInCurrentMonth());

            if (calendar.getNumberOfDaysInCurrentMonth() < calendar.getNumberOfDaysInPrevMonth()) {
                differenceOfDays = calendar.getNumberOfDaysInPrevMonth() - calendar.getNumberOfDaysInCurrentMonth();

                for (differenceOfDays; differenceOfDays > 0; differenceOfDays--) {
                    for (auto x:tmp[currentMonth.size() + differenceOfDays -  1]) {
                        currentMonth[currentMonth.size() - 1].push_back(x);
                    }
                 }
            }

            tmp.clear();
        }

        i++;
    }

    currentMonth.clear();
    tmp.clear();

    return 0;
}