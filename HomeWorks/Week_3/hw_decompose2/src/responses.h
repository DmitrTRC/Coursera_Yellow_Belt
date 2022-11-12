//
// Created by Dmitry Morozov on 12/11/22.
//

#ifndef COURSERA_YELLOW_BELT_MAIN_RESPONSES_H
#define COURSERA_YELLOW_BELT_MAIN_RESPONSES_H

#include <map>
#include <string>
#include <vector>

struct BusesForStopResponse {

    std::vector<std::string> buses;
};

std::ostream &operator<<(std::ostream &os, const BusesForStopResponse &r);

struct StopsForBusResponse {

    std::string bus;
    std::vector<std::pair<std::string, std::vector<std::string>>> stops;

};

std::ostream &operator<<(std::ostream &os, const StopsForBusResponse &r);

struct AllBusesResponse {

    std::map<std::string, std::vector<std::string>> buses;
};


#endif //COURSERA_YELLOW_BELT_MAIN_RESPONSES_H
