//
// Created by apel on 16.01.2021.
//

#ifndef YANDEX_CPP_COURSE_RESPONSES_H
#define YANDEX_CPP_COURSE_RESPONSES_H

#include <iostream>
#include <vector>
#include <fstream>
#include <map>

struct BusesForStopResponse {
    std::string stop;
    std::vector <std::string> buses;
};

struct StopsForBusResponse {
    std::string bus;
    std::vector<std::string> stops;
    std::map<std::string, BusesForStopResponse> buses_for_stop;
};

struct AllBusesResponse {
    std::map<std::string, std::vector<std::string>> buses;
};

std::ostream& operator << (std::ostream& os, const BusesForStopResponse& r);

std::ostream& operator << (std::ostream& os, const StopsForBusResponse& r);

std::ostream& operator << (std::ostream& os, const AllBusesResponse& r);

#endif //YANDEX_CPP_COURSE_RESPONSES_H
