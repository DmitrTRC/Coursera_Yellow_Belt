//
// Created by Dmitry Morozov on 12/11/22.
//

#include "bus_manager.h"

#include <iostream>

void BusManager::AddBus(const std::string &bus, const std::vector<std::string> &stops) {

    for (const auto &stop: stops) {
        buses_to_stops[bus].push_back(stop);
        stops_to_buses[stop].push_back(bus);
    }

}

BusesForStopResponse BusManager::GetBusesForStop(const std::string &stop) const {

    BusesForStopResponse response;
    if (stops_to_buses.count(stop) > 0) {
        response.buses = stops_to_buses.at(stop);
    }

    return response;
}

StopsForBusResponse BusManager::GetStopsForBus(const std::string &bus) const {

    StopsForBusResponse response;
    if (buses_to_stops.count(bus) > 0) {
        response.bus = bus;
        for (const auto &stop: buses_to_stops.at(bus)) {
            response.stops.emplace_back(stop, stops_to_buses.at(stop));
        }
    }

    return response;
}

AllBusesResponse BusManager::GetAllBuses() const {

    AllBusesResponse response;
    response.buses = buses_to_stops;

    return response;
}
