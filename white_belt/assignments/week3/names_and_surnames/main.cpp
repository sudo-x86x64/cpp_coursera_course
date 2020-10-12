#include <iostream>
#include <map>

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

private:
    string currentFirstName = "";
    string currentLastName =  "";
    map<int, PersonRecord> records;
};
