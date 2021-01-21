//
// Created by apel on 16.01.2021.
//

#include "responses.h"

using namespace std;

ostream& operator << (ostream& os, const BusesForStopResponse& r) {
    if (r.buses.empty()) {
        os << "No stop";
        return os;
    }
    for (int i = 0; i < r.buses.size(); ++i) {
        if (i != 0)
            os << " ";
        os << r.buses[i];
    }
    return os;
}


ostream& operator << (ostream& os, const StopsForBusResponse& r) {
    if (r.stops.empty()) {
        os << "No bus";
        return os;
    }
    for (int i = 0; i < r.stops.size(); ++i) {
        if (i != 0)
            os << endl;

        os << "Stop " << r.stops[i] << ": ";
        if (r.buses_for_stop.at(r.stops[i]).buses.size() == 1) {
            os << "no interchange";
        } else {
            for (int j = 0; j < r.buses_for_stop.at(r.stops[i]).buses.size(); ++j) {
                if (j != 0)
                    os << " ";
                if (r.bus != r.buses_for_stop.at(r.stops[i]).buses[j]) {
                    os << r.buses_for_stop.at(r.stops[i]).buses[j];
                }
            }
        }
    }
    return os;
}


ostream& operator << (ostream& os, const AllBusesResponse& r) {
    if (r.buses.empty()) {
        os << "No buses";
        return os;
    }
    bool first = true;
    for (const auto& bus_item : r.buses) {
        if (!first)
            os << endl;
        first = false;
        os << "Bus " << bus_item.first << ": ";
        for (int j = 0; j < bus_item.second.size(); ++j) {
            if (j != 0)
                os << " ";
            os << bus_item.second[j];
        }
    }
    return os;
}