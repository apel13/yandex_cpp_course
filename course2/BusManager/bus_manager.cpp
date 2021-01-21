//
// Created by apel on 16.01.2021.
//

#include "bus_manager.h"

using namespace std;

void BusManager::AddBus(const string &bus, const vector <string> &stops) {
    buses_to_stops[bus] = stops;
    for (const auto&el : stops) {
        stops_to_buses[el].push_back(bus);
    }
}

BusesForStopResponse BusManager::GetBusesForStop(const std::string &stop) const {
    if (stops_to_buses.count(stop) == 0)
        return {stop, {}};
    return BusesForStopResponse {stop, stops_to_buses.at(stop)};
}

StopsForBusResponse BusManager::GetStopsForBus(const string &bus) const {
    std::vector<std::string> stops;
    if (buses_to_stops.count(bus) > 0)
        stops = buses_to_stops.at(bus);
    else
        stops = {};

    std::map<std::string, BusesForStopResponse> buses;
    for (const std::string& stop : stops) {
        buses[stop] = GetBusesForStop(stop);
    }
    return StopsForBusResponse {bus, stops, buses};
}

AllBusesResponse BusManager::GetAllBuses() const {
    std::map<std::string, std::vector<std::string>> buses;
    if (!buses_to_stops.empty()) {
        buses = buses_to_stops;
    } else {
        buses = {};
    }
    return AllBusesResponse {buses};
}
