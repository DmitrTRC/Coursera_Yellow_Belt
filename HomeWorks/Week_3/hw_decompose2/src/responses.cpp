//
// Created by Dmitry Morozov on 12/11/22.
//

#include "responses.h"

#include "iostream"

std::ostream &operator<<(std::ostream &os, const BusesForStopResponse &r) {

    if (r.buses.empty()) {
        os << "No stop";
    } else {
        for (const std::string &bus: r.buses) {
            os << bus << " ";
        }
    }

    return os;
}

std::ostream &operator<<(std::ostream &os, const StopsForBusResponse &r) {

    if (r.stops.empty()) {
        os << "No bus";
    } else {
        for (const auto &stop: r.stops) {
            os << "Stop " << stop.first << ": ";
            if (stop.second.size() == 1) {
                os << "no interchange";
            } else {
                for (const std::string &bus: stop.second) {
                    if (bus != r.bus) {
                        os << bus << " ";
                    }

                }
            }
            os << std::endl;
        }
    }

    return os;
}

std::ostream &operator<<(std::ostream &os, const AllBusesResponse &r) {

    if (r.buses.empty()) {
        os << "No buses";
    } else {
        for (const auto &bus_item: r.buses) {
            os << "Bus " << bus_item.first << ": ";
            for (const std::string &stop: bus_item.second) {
                os << stop << " ";
            }
            os << std::endl;
        }
    }

    return os;
}

