//
// Created by apel on 15.01.2021.
//

#ifndef YANDEX_CPP_COURSE_DATABASE_H
#define YANDEX_CPP_COURSE_DATABASE_H

class Date {
public:
    Date(int year, int month, int day) {
        if (month < 1 || month > 12)
            throw std::out_of_range("Month value is invalid: " + std::to_string(month));
        if (day < 1 || day > 31)
            throw std::out_of_range("Day value is invalid: " + std::to_string(day));
        _year = year;
        _month = month;
        _day = day;
    }

    int GetYear() const {
        return _year;
    };

    int GetMonth() const {
        return _month;
    };

    int GetDay() const {
        return _day;
    };

    static Date ParseDate(const std::string &date) {
        std::istringstream ss(date);

        std::smatch base_match;
        const std::regex base_regex("([+-]?[0-9]+)-([+-]?[0-9]+)-([+-]?[0-9]+)");

        if (!regex_match(date, base_match, base_regex))
            throw std::logic_error("Wrong date format: " + date);

        return Date(stoi(base_match[1]),
                    stoi(base_match[2]),
                    stoi(base_match[3]));
    }

private:
    int _year, _month, _day;
};

std::ostream &operator<<(std::ostream &os, const Date &date) {
    return os << std::setfill('0')
              << std::setw(4)
              << std::to_string(date.GetYear())
              << "-"
              << std::setfill('0')
              << std::setw(2)
              << std::to_string(date.GetMonth())
              << "-"
              << std::setfill('0')
              << std::setw(2)
              << std::to_string(date.GetDay());
}

bool operator<(const Date &lhs, const Date &rhs) {
    if (lhs.GetYear() != rhs.GetYear())
        return lhs.GetYear() < rhs.GetYear();
    else if (lhs.GetMonth() != rhs.GetMonth())
        return lhs.GetMonth() < rhs.GetMonth();
    return lhs.GetDay() < rhs.GetDay();
}

class Database {
public:
    void AddEvent(const Date &date, const std::string &event) {
        if (!event.empty())
            _records[date].insert(event);
    }

    bool DeleteEvent(const Date &date, const std::string &event) {
        if (_records.count(date) > 0 && _records[date].count(event) > 0) {
            _records[date].erase(event);
            return true;
        }
        return false;
    }

    int DeleteDate(const Date &date) {
        int del = 0;
        if (_records.count(date) > 0) {
            del = _records.at(date).size();
            _records.erase(date);
        }
        return del;
    }

    std::set<std::string> Find(const Date &date) const {
        std::set<std::string> result;
        if (_records.count(date) > 0)
            result = _records.at(date);
        return result;
    }

    void Print() const {
        for (const auto &r : _records)
            for (const auto &s : r.second)
                std::cout << r.first << ' ' << s << std::endl;
    }

private:
    std::map<Date, std::set<std::string>> _records;
};

#endif //YANDEX_CPP_COURSE_DATABASE_H
