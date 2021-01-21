//
// Created by apel on 17.01.2021.
//

#include "date.h"

#include <tuple>
#include <iomanip>

Date::Date()
        : _year(0), _month(0), _day(0) {}

Date::Date(int new_year, int new_month, int new_day)
        : _year(new_year), _month(new_month), _day(new_day) {
}

int Date::GetYear() const {
    return _year;
}

int Date::GetMonth() const {
    return _month;
}

int Date::GetDay() const {
    return _day;
}

Date ParseDate(std::istream &is) {
    int year, month, day;
    is >> year;
    is.ignore();
    is >> month;
    is.ignore();
    is >> day;
    return Date{year, month, day};
}

bool operator<(const Date &lhs, const Date &rhs) {
    return std::make_tuple(lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()) <
           std::make_tuple(rhs.GetYear(), rhs.GetMonth(), rhs.GetDay());
}

bool operator==(const Date &lhs, const Date &rhs) {
    return !(lhs < rhs) && !(rhs < lhs);
}

bool operator!=(const Date &lhs, const Date &rhs) {
    return !(lhs == rhs);
}

bool operator<=(const Date &lhs, const Date &rhs) {
    return !(rhs < lhs);
}

bool operator>(const Date &lhs, const Date &rhs) {
    return rhs < lhs;
}

bool operator>=(const Date &lhs, const Date &rhs) {
    return !(lhs < rhs);
}

std::ostream &operator<<(std::ostream &stream, const Date &date) {
    return stream << std::setw(4) << std::setfill('0') << date.GetYear() <<
                  "-" << std::setw(2) << std::setfill('0') << date.GetMonth() <<
                  "-" << std::setw(2) << std::setfill('0') << date.GetDay();
}