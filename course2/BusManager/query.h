//
// Created by apel on 16.01.2021.
//

#ifndef YANDEX_CPP_COURSE_QUERY_H
#define YANDEX_CPP_COURSE_QUERY_H

#include <iostream>
#include <vector>
#include <fstream>

enum class QueryType {
    NewBus,
    BusesForStop,
    StopsForBus,
    AllBuses
};

struct Query {
    QueryType type;
    std::string bus;
    std::string stop;
    std::vector<std::string> stops;
};

std::istream& operator >> (std::istream& is, Query& q);

#endif //YANDEX_CPP_COURSE_QUERY_H
