//
// Created by apel on 14.01.2021.
//

#ifndef YANDEX_CPP_COURSE_PERSON_H
#define YANDEX_CPP_COURSE_PERSON_H

#include <map>
#include <vector>

class Person {
public:
    Person(string firstName, string lastName, int year)
            : _birthDay(year),
              _first({{-1,   ""},
                      {year, std::move(firstName)}}),
              _last({{-1,   ""},
                     {year, std::move(lastName)}}) {}

    void ChangeFirstName(int year, const string &first_name) {
        if (year >= _birthDay)
            _first[year] = first_name;
    }

    void ChangeLastName(int year, const string &last_name) {
        if (year >= _birthDay)
            _last[year] = last_name;
    }

    string GetFullName(int year) const {
        string firstName = GetNameOnYear(year, _first);
        string lastName = GetNameOnYear(year, _last);
        return BuildFullName(firstName, lastName);
    }

    string GetFullNameWithHistory(int year) const {
        string firstName = GetHistoryOnYear(year, _first);
        string lastName = GetHistoryOnYear(year, _last);
        return BuildFullName(firstName, lastName);
    }


private:
    map<int, string> _first;
    map<int, string> _last;
    int _birthDay;

    string GetNameOnYear(int year, const map<int, string> &names) const {
        auto last = std::prev(names.upper_bound(year));
        if (last == names.begin()) return "";
        return last->second;
    }

    string GetHistoryOnYear(int year, const map<int, string> &names) const {
        std::stack<string> hist;
        for (auto &name : names) {
            if (name.second.empty()) continue;
            if (name.first > year) break;
            if (hist.empty() || (hist.top() != name.second))
                hist.push(name.second);
        }
        if (hist.empty()) return "";
        string realName = hist.top();
        hist.pop();
        if (hist.empty()) return realName;

        stringstream other;
        other << " (" << hist.top();
        hist.pop();
        while (!hist.empty()) {
            other << ", " << hist.top();
            hist.pop();
        }
        other << ')';

        return realName + other.str();
    }

    string BuildFullName(const string &firstName, const string &lastName) const {
        if (firstName.empty() && lastName.empty())
            return "No person";
        if (firstName.empty())
            return lastName + " with unknown first name";
        if (lastName.empty())
            return firstName + " with unknown last name";
        return firstName + ' ' + lastName;
    }
};


#endif //YANDEX_CPP_COURSE_PERSON_H
