//
// Created by apel on 17.01.2021.
//

#include "database.h"

void Database::Add(const Date &date, const std::string &event) {
    if (_event_to_dates.count(event) == 0 ||
        _event_to_dates[event].count(date) == 0) {
        _date_to_events[date].push_back(event);
        _event_to_dates[event].insert(date);
    }
}

int Database::RemoveIf(const Database::predType &pred) {
    int deleted = 0;

    for (auto it = _date_to_events.begin(); it != _date_to_events.end();) {
        for (auto &event : it->second) {
            if (pred(it->first, event)) {
                ++deleted;
                _event_to_dates[event].erase(it->first);
                if (_event_to_dates[event].empty())
                    _event_to_dates.erase(event);
            }
        }
        it->second.erase(
                std::remove_if(it->second.begin(), it->second.end(),
                               [&pred, &it](const std::string &str) {
                                   return pred(it->first, str);
                               }), it->second.end());
        if (it->second.empty())
            it = _date_to_events.erase(it);
        else
            ++it;
    }
    return deleted;
}

std::vector<Database::retType> Database::FindIf(const Database::predType &pred) const {
    std::vector<Database::retType> ans;
    for (const auto &date_events : _date_to_events) {
        for (const auto &event : date_events.second) {
            if (pred(date_events.first, event))
                ans.emplace_back(date_events.first, event);
        }
    }
    return ans;
}

Database::retType Database::Last(const Date &date) const {
    auto it = _date_to_events.upper_bound(date);
    if (it == _date_to_events.begin())
        throw std::invalid_argument("No entries");
    it = std::prev(it);
    return std::make_pair(it->first, it->second.back());
}

void Database::Print(std::ostream &os) const {
    for (const auto &item : _date_to_events)
        for (const std::string &event : item.second)
            os << item.first << ' ' << event << std::endl;
}

std::ostream &operator<<(std::ostream &os, const Database::retType &pair) {
    os << pair.first << ' ' << pair.second;
    return os;
}

std::string ParseEvent(std::istringstream &is) {
    std::string line;
    is >> std::ws;
    getline(is, line);
    return line;
}
