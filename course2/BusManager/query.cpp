//
// Created by apel on 16.01.2021.
//

#include "query.h"

#include <iostream>
#include <fstream>

using namespace std;

istream& operator >> (istream& is, Query& q) {
    string type;
    is >> type;
    if (type == "NEW_BUS") {
        q.type = QueryType::NewBus;
        int stop_count;
        is >> q.bus >> stop_count;
        q.stops.resize(stop_count);
        for (auto &el : q.stops)
            is >> el;

    } else if (type == "BUSES_FOR_STOP") {
        q.type = QueryType::BusesForStop;
        is >> q.stop;
    } else if (type == "STOPS_FOR_BUS") {
        q.type = QueryType::StopsForBus;
        is >> q.bus;
    } else if (type == "ALL_BUSES") {
        q.type = QueryType::AllBuses;
    }
    return is;
}