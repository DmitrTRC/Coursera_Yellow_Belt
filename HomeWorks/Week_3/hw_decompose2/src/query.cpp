//
// Created by Dmitry Morozov on 12/11/22.
//

#include "query.h"

#include <iostream>

std::istream &operator>>(std::istream &is, Query &q) {

    std::string query_type;
    is >> query_type;

    if (query_type == "NEW_BUS") {
        q.type = QueryType::NewBus;
        is >> q.bus;
        int stop_count;
        is >> stop_count;
        q.stops.resize(stop_count);
        for (std::string &stop: q.stops) {
            is >> stop;
        }
    } else if (query_type == "BUSES_FOR_STOP") {
        q.type = QueryType::BusesForStop;
        is >> q.stop;
    } else if (query_type == "STOPS_FOR_BUS") {
        q.type = QueryType::StopsForBus;
        is >> q.bus;
    } else if (query_type == "ALL_BUSES") {
        q.type = QueryType::AllBuses;
    }

    return is;
}

