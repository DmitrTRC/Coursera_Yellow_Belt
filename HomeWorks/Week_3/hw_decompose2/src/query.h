//
// Created by Dmitry Morozov on 12/11/22.
//

#ifndef COURSERA_YELLOW_BELT_MAIN_QUERY_H
#define COURSERA_YELLOW_BELT_MAIN_QUERY_H

#include <string>
#include <vector>

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


#endif //COURSERA_YELLOW_BELT_MAIN_QUERY_H
