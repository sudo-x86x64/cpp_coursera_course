#include <iostream>
#include <map>
#include <set>

using namespace std;

class PersonRecord {
public:
    string FirstName;
    string LastName;
};

class Person {
public:
    void ChangeFirstName(int year, const string& first_name) {
        PersonRecord tmpRecord;
        if (!records.count(year)) {
            tmpRecord.FirstName = first_name;
            records[year] = tmpRecord;
            return;
        }
        tmpRecord = records[year];
        tmpRecord.FirstName = first_name;
        records[year] = tmpRecord;
    }
    void ChangeLastName(int year, const string& last_name) {
        PersonRecord tmpRecord;
        if(!records.count(year)) {
            tmpRecord.LastName  = last_name;
            records[year] = tmpRecord;
            return;
        }
        tmpRecord = records[year];
        tmpRecord.LastName = last_name;
        records[year] = tmpRecord;
    }
    
    string GetFullName(int year) {
        int i = 0;
        string name = "";
        string surname = "";
    
        if(!records.count(year)) {
            if (records.begin()->first > year)  return "Incognito";  
        }

        for(i = year; i >= records.begin()->first; i--) {
            if(!records.count(i)) continue;
            PersonRecord tmp = records[i];
            if (!tmp.FirstName.length()) continue;
            name = tmp.FirstName;
            break;
        }

        for(i = year; i >= records.begin()->first; i--) {
            if(!records.count(i)) continue;
            PersonRecord tmp = records[i];
            if (!tmp.LastName.length()) continue;
            surname = tmp.LastName;
            break;
        }

        if (name.length() && surname.length()) return name + " " + surname;
        else if (name.length() && !surname.length()) return name + " with unknown last name";
        else if (!name.length() && surname.length()) return surname + " with unknown first name";
        else return "ERROR";
    }
    
    string GetFullNameWithHistory(int year) {
        int i = 0;
        string name = "";
        string surname = "";
        map<int, string> allNames;
        map<int, string> allSurnames;
         
        if(!records.count(year)) {
            if (records.begin()->first > year)  return "Incognito";  
        }

        for(i = year; i >= records.begin()->first; i--) {
            if(!records.count(i)) continue;
            PersonRecord tmp = records[i];
            if (!name.length() && tmp.FirstName.length()) {
                name = tmp.FirstName;
                continue;
            }
            if (tmp.FirstName.length()) {
                if (tmp.FirstName == name && !allNames.size()) continue;
                allNames[i]= tmp.FirstName;
            }
        }

        for(i = year; i >= records.begin()->first; i--) {
            if(!records.count(i)) continue;
            PersonRecord tmp = records[i];
            if (!surname.length() && tmp.LastName.length()) {
                surname = tmp.LastName;
                continue;
            }
            if (tmp.LastName.length()) {
                if (tmp.LastName == surname && !allSurnames.size()) continue;
                allSurnames[i] = tmp.LastName;
            }
        }

        if (allNames.size()) {
            name = name + " (";
            for (auto iter = allNames.rbegin(); iter != allNames.rend(); ++iter) {
                name += iter->second + ", ";
            }

            name.resize(name.length() -2);
            name = name + ")";
        }

        if (allSurnames.size()) {
            surname = surname + " (";
            for (auto iter = allSurnames.rbegin(); iter != allSurnames.rend(); ++iter) {
                surname += iter->second + ", ";
            }
            surname.resize(surname.length() -2);
            surname = surname + ")";
        }

        if (name.length() && surname.length()) return name + " " + surname;
        else if (name.length() && !surname.length()) return name + " with unknown last name";
        else if (!name.length() && surname.length()) return surname + " with unknown first name";
        else return "ERROR";
    }

private:
    string currentFirstName = "";
    string currentLastName =  "";
    map<int, PersonRecord> records;
};

