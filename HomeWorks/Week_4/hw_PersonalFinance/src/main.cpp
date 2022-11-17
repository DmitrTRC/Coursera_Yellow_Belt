//
// Created by Dmitry Morozov on 20/9/22.
//

#include <algorithm>
#include <chrono>
#include <iostream>
#include <map>
#include <utility>
#include <vector>
#include <numeric>
#include <sstream>
#include <ctime>
#include <iomanip>

///Convert string "YYYY-MM-DD" to date


class Earn {
public:
    Earn(std::tm from, std::tm to, int value) : value_(value) {

        from_ = std::chrono::system_clock::from_time_t(std::mktime(&from));
        to_ = std::chrono::system_clock::from_time_t(std::mktime(&to));


    }


    [[nodiscard]] int value() const { return value_; }

private:
    std::chrono::system_clock::time_point from_;
    std::chrono::system_clock::time_point to_;

    int value_;
};


class Balance {

public:
    Balance() = default;

    void addEarn(const Earn &earn) {
        earns_.push_back(earn);
    }


    [[nodiscard]] double computeIncome(const std::string &from, const std::string &to) const {

    }

private:
    std::vector<Earn> earns_;

    double getEarnPerDay(const Earn &earn) {

//        return earn.value() / getDaysBetween(earn.from(), earn.to());
    }

    int getDaysBetween(const std::string &from, const std::string &to) const {
    }


};

std::tm convertStringToTm(const std::string &date) {

    std::tm tm = {};
    std::istringstream ss(date);
    ss >> std::get_time(&tm, "%Y-%m-%d");
    return tm;
}

void commander(int nCommands) {

    Balance balance;

    for (int i = 0; i < nCommands; ++i) {
        std::string command;
        std::cin >> command;
        if (command == "Earn") {
            std::string from;
            std::string to;
            int value;
            std::cin >> from >> to >> value;
            auto t_from = convertStringToTm(from);
            auto t_to = convertStringToTm(to);
            balance.addEarn(Earn(t_from, t_to, value));
        } else if (command == "ComputeIncome") {
            std::string from;
            std::string to;
            std::cin >> from >> to;
            std::cout.precision(25);
            std::cout << balance.computeIncome(from, to) << std::endl;
        }
    }


}

int main() {

    int nCommands;
    std::cin >> nCommands;
    commander(nCommands);

    return 0;
}