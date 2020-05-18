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
    string  originalName;
    string  originalSurname;
    int     yearOfBirth;
    map<int, PersonRecord> records;

    string NameBuilder(const map<int, string> &m) const {
        if (!m.size()) return "";
        string str = " (";

        for (auto iter = m.rbegin(); iter != m.rend(); ++iter) {
            str += iter->second + ", ";
        }
        str.resize(str.length() -2);
        str += ")";
        return str;
    }

public:
    void ChangeFirstName(int year, const string& first_name) {
        PersonRecord tmpRecord;

        if (year < yearOfBirth) return;

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

        if (year < yearOfBirth) return;

        if(!records.count(year)) {
            tmpRecord.LastName  = last_name;
            records[year] = tmpRecord;
            return;
        }
        tmpRecord = records[year];
        tmpRecord.LastName = last_name;
        records[year] = tmpRecord;
    }
    
    string GetFullName(const int& year)  const {
        int i = 0;
        string name = "";
        string surname = "";
    
        if(!records.count(year)) {
            if (records.begin()->first > year)  return "Incognito";  
        }

        for(i = year; i >= records.begin()->first; i--) {
            if(!records.count(i)) continue;
            PersonRecord tmp = records.at(i);
            if (!tmp.FirstName.length()) continue;
            name = tmp.FirstName;
            break;
        }

        for(i = year; i >= records.begin()->first; i--) {
            if(!records.count(i)) continue;
            PersonRecord tmp = records.at(i);
            if (!tmp.LastName.length()) continue;
            surname = tmp.LastName;
            break;
        }

        if (name.length() && surname.length()) return name + " " + surname;
        else if (name.length() && !surname.length()) return name + " with unknown last name";
        else if (!name.length() && surname.length()) return surname + " with unknown first name";
        else return "ERROR";
    }

    string GetFullNameWithHistory(int year) const {
        int i = 0;
        string name = "";
        string surname = "";
        map<int, string> allNames;
        map<int, string> allSurnames;
        
        if (year < yearOfBirth) return "No person";

        if(!records.count(year)) {
            if (records.begin()->first > year)  return "Incognito";  
        }

        for(i = year; i >= records.begin()->first; i--) {
            if(!records.count(i)) continue;
            PersonRecord tmp = records.at(i);
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
            PersonRecord tmp = records.at(i);
            if (!surname.length() && tmp.LastName.length()) {
                surname = tmp.LastName;
                continue;
            }
            if (tmp.LastName.length()) {
                if (tmp.LastName == surname && !allSurnames.size()) continue;
                allSurnames[i] = tmp.LastName;
            }
        }

        name +=     NameBuilder(allNames);
        surname +=  NameBuilder(allSurnames);
    
        if (name.length() && surname.length()) return name + " " + surname;
        else if (name.length() && !surname.length()) return name + " with unknown last name";
        else if (!name.length() && surname.length()) return surname + " with unknown first name";
        else return "ERROR";
    }

    Person (const string& name, const string& surname, const int& year) {
        originalName    = name;
        originalSurname = surname;
        yearOfBirth     = year;
        records[year]   = {originalName, originalSurname};
    }
};


int main() {
  Person person("Polina", "Sergeeva", 1960);
  for (int year : {1959, 1960}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }
  
  person.ChangeFirstName(1965, "Appolinaria");
  person.ChangeLastName(1967, "Ivanova");
  for (int year : {1965, 1967}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }

  return 0;
}