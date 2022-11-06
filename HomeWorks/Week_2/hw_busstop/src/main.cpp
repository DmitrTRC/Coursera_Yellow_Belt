//
// Created by Dmitry Morozov on 20/9/22.
//
#include <string>
#include <iostream>
#include <cassert>
#include <vector>
#include <map>

/*

 Condition of the problem "Bus stops - 1" :
 Implement a storage system for bus routes.
 You need to process the following queries:
 NEW_BUS busstop_countstop1stop2 ... - add a bus route named bus and stop_count stops named stop1, stop2, ...
 BUSES_FOR_STOP stop - display the names of all bus routes passing through the stop stop.
 STOPS_FOR_BUS bus - display the names of all stops on the bus route with a list of buses that can be transferred to at each of the stops.
 ALL_BUSES - List all routes with stops. Input format The first line of the input contains the number of requests Q, then the Q lines are followed by descriptions of the requests.
 It is guaranteed that all names of routes and stops consist only of Latin letters, numbers and underscores.
 For each NEW_BUS bus stop_count stop1stop2 ... request, it is guaranteed that there is no bus route, the number of stops is greater than 0, and the stop_count number is followed by that many stop names, with all names in each list different.
 Output Format For each query, except for NEW_BUS, print the corresponding response to it:
 For the BUSES_FOR_STOP stop query, output a space-separated list of buses passing through this stop, in the order in which they were created by the NEW_BUS commands.
 If stop does not exist, print No stop.
 For the STOPS_FOR_BUS bus query, print the descriptions of the bus route's stops on separate lines in the order in which they were specified in the corresponding NEW_BUS command.
 The description of each stop must be of the form Stop stop: bus1bus2 ..., where bus1bus2 ... is the list of buses passing through the stop, in the order in which they were created by the NEW_BUS commands, excluding the original bus route.
 If no bus other than bus passes through the stop, print no interchange instead of the list of buses for it.
 If the route bus does not exist, print No bus.
 For the ALL_BUSES query, print descriptions of all buses in alphabetical order.
 The description of each bus route must be of the form Bus bus: stop1stop2 ..., where stop1stop2 ... is a list of bus stops in the order in which they were specified in the corresponding NEW_BUS command.
 If there are no buses, print No buses.

*/

/*
Input:
10
ALL_BUSES
BUSES_FOR_STOP Marushkino
STOPS_FOR_BUS 32K
NEW_BUS 32 3 Tolstopaltsevo Marushkino Vnukovo
NEW_BUS 32K 6 Tolstopaltsevo Marushkino Vnukovo Peredelkino Solntsevo Skolkovo
BUSES_FOR_STOP Vnukovo
NEW_BUS 950 6 Kokoshkino Marushkino Vnukovo Peredelkino Solntsevo Troparyovo
NEW_BUS 272 4 Vnukovo Moskovsky Rumyantsevo Troparyovo
STOPS_FOR_BUS 272
ALL_BUSES

Output:
No buses
No stop
No bus
32 32K
Stop Vnukovo: 32 32K 950
Stop Moskovsky: no interchange
Stop Rumyantsevo: no interchange
Stop Troparyovo: 950
Bus 272: Vnukovo Moskovsky Rumyantsevo Troparyovo
Bus 32: Tolstopaltsevo Marushkino Vnukovo
Bus 32K: Tolstopaltsevo Marushkino Vnukovo Peredelkino Solntsevo Skolkovo
Bus 950: Kokoshkino Marushkino Vnukovo Peredelkino Solntsevo Troparyovo
 */

using namespace std;

enum class QueryType {
    NewBus,
    BusesForStop,
    StopsForBus,
    AllBuses
};

struct Query {
    QueryType type;
    string bus;
    string stop;
    vector<string> stops;
};

istream &operator>> (istream &is, Query &q) {

    return is;
}


struct BusesForStopResponse {

};

ostream &operator<< (ostream &os, const BusesForStopResponse &r) {
    // implementation
    return os;
}

struct StopsForBusResponse {
    // add necessary fields
};

ostream &operator<< (ostream &os, const StopsForBusResponse &r) {
    // implementation
    return os;
}

struct AllBusesResponse {
    // add necessary fields
};

ostream &operator<< (ostream &os, const AllBusesResponse &r) {
    // implementation
    return os;
}

class BusManager {
public:
    void AddBus (const string &bus, const vector<string> &stops) {

    }
    // implementation

    BusesForStopResponse GetBusesForStop (const string &stop) const {
        // implementation
    }

    StopsForBusResponse GetStopsForBus (const string &bus) const {
        // implementation

        AllBusesResponse GetAllBuses () const {
            // implementation
        }
    };

// Con not be changed
    int main () {
        int query_count;
        Query q;

        cin >> query_count;

        BusManager bm;

        for (int i = 0; i < query_count; ++i) {
            cin >> q;

            switch (q.type) {
                case QueryType::NewBus:
                    bm.AddBus (q.bus, q.stops);
                    break;
                case QueryType::BusesForStop:
                    cout << bm.GetBusesForStop (q.stop) << endl;
                    break;
                case QueryType::StopsForBus:
                    cout << bm.GetStopsForBus (q.bus) << endl;
                    break;
                case QueryType::AllBuses:
                    cout << bm.GetAllBuses () << endl;
                    break;
            }
        }

        return 0;
    }