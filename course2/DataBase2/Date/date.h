//
// Created by apel on 17.01.2021.
//

#ifndef YANDEX_CPP_COURSE_DATE_H
#define YANDEX_CPP_COURSE_DATE_H

#include <sstream>


class Date {
public:
    Date();

    Date(int, int, int);

    int GetYear() const;
    int GetMonth() const;
    int GetDay() const;

private:
    int _year, _month, _day;
};

Date ParseDate(std::istream &is);

bool operator<(const Date &lhs, const Date &rhs);

bool operator==(const Date &lhs, const Date &rhs);

bool operator!=(const Date &lhs, const Date &rhs);

bool operator<=(const Date &lhs, const Date &rhs);

bool operator>(const Date &lhs, const Date &rhs);

bool operator>=(const Date &lhs, const Date &rhs);

std::ostream &operator<<(std::ostream &stream, const Date &date);

#endif //YANDEX_CPP_COURSE_DATE_H
