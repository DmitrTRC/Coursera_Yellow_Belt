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
Demo implementation of the problem "Bus stops - 1" :

using namespace std;

int main() {
    int q;
    cin >> q;

    map<string, vector<string>> buses_to_stops, stops_to_buses;

    for (int i = 0; i < q; ++i) {
        string operation_code;
        cin >> operation_code;

        if (operation_code == "NEW_BUS") {

            string bus;
            cin >> bus;
            int stop_count;
            cin >> stop_count;
            vector<string>& stops = buses_to_stops[bus];
            stops.resize(stop_count);
            for (string& stop : stops) {
                cin >> stop;
                stops_to_buses[stop].push_back(bus);
            }

        } else if (operation_code == "BUSES_FOR_STOP") {

            string stop;
            cin >> stop;
            if (stops_to_buses.count(stop) == 0) {
                cout << "No stop" << endl;
            } else {
                for (const string& bus : stops_to_buses[stop]) {
                    cout << bus << " ";
                }
                cout << endl;
            }

        } else if (operation_code == "STOPS_FOR_BUS") {

            string bus;
            cin >> bus;
            if (buses_to_stops.count(bus) == 0) {
                cout << "No bus" << endl;
            } else {
                for (const string& stop : buses_to_stops[bus]) {
                    cout << "Stop " << stop << ": ";
                    if (stops_to_buses[stop].size() == 1) {
                        cout << "no interchange";
                    } else {
                        for (const string& other_bus : stops_to_buses[stop]) {
                            if (bus != other_bus) {
                                cout << other_bus << " ";
                            }
                        }
                    }
                    cout << endl;
                }
            }

        } else if (operation_code == "ALL_BUSES") {

            if (buses_to_stops.empty()) {
                cout << "No buses" << endl;
            } else {
                for (const auto& bus_item : buses_to_stops) {
                    cout << "Bus " << bus_item.first << ": ";
                    for (const string& stop : bus_item.second) {
                        cout << stop << " ";
                    }
                    cout << endl;
                }
            }

        }
    }

    return 0;
}
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