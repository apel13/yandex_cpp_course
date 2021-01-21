//
// Created by apel on 16.01.2021.
//

#ifndef YANDEX_CPP_COURSE_BUS_MANAGER_H
#define YANDEX_CPP_COURSE_BUS_MANAGER_H


#include <iostream>
#include <vector>
#include <fstream>
#include <map>

#include "responses.h"

class BusManager {
public:
    void AddBus(const std::string& bus, const std::vector<std::string>& stops);

    BusesForStopResponse GetBusesForStop(const std::string& stop) const;

    StopsForBusResponse GetStopsForBus(const std::string& bus) const;

    AllBusesResponse GetAllBuses() const;

    std::map<std::string, std::vector<std::string>> buses_to_stops, stops_to_buses;
};


#endif //YANDEX_CPP_COURSE_BUS_MANAGER_H
