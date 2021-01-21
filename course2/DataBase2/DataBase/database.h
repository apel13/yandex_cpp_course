//
// Created by apel on 17.01.2021.
//

#ifndef YANDEX_CPP_COURSE_DATABASE_H
#define YANDEX_CPP_COURSE_DATABASE_H


#include "../Date/date.h"

#include <iostream>
#include <functional>
#include <set>
#include <map>


class Database {
public:
    using predType = std::function<bool(const Date &, const std::string &)>;
    using retType = std::pair<Date, std::string>;

    void Add(const Date &, const std::string &);

    int RemoveIf(const predType &);

    std::vector<retType> FindIf(const predType &) const;

    retType Last(const Date &) const;

    void Print(std::ostream &) const;

private:
    std::map<Date, std::vector<std::string>> _date_to_events;
    std::map<std::string, std::set<Date>> _event_to_dates;
};

std::ostream &operator<<(std::ostream &, const Database::retType &);

std::string ParseEvent(std::istringstream &is);

#endif //YANDEX_CPP_COURSE_DATABASE_H
