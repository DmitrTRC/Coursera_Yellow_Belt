//
// Created by Dmitry Morozov on 20/9/22.
//


#include <chrono>
#include <iostream>
#include <map>
#include <utility>
#include <vector>
#include <numeric>
#include <sstream>
#include <iomanip>

///Convert string "YYYY-MM-DD" to date

std::chrono::system_clock::time_point convertStringToDate(const std::string &date) {

    std::tm tm = {};
    std::istringstream ss(date);
    ss >> std::get_time(&tm, "%Y-%m-%d");
    if (ss.fail()) {
        throw std::runtime_error("Wrong date format");
    }

//    return std::chrono::year_month_day(std::chrono::year(tm.tm_year + 1900), std::chrono::month(tm.tm_mon + 1),
//                                       std::chrono::day(tm.tm_mday));

    return std::chrono::system_clock::from_time_t(std::mktime(&tm));
}

class Earn {
public:
    Earn(std::chrono::system_clock::time_point from, std::chrono::system_clock::time_point to, int value) : value_(
            value) {

        if (from > to) {
            throw std::invalid_argument("from > to");
        }

        from_ = from;
        to_ = to;

    }


    [[nodiscard]] int value() const { return value_; }

    [[nodiscard]] std::chrono::system_clock::time_point from() const { return from_; }

    [[nodiscard]] std::chrono::system_clock::time_point to() const { return to_; }

private:

//    std::chrono::year_month_day from_;
//    std::chrono::year_month_day to_;
    std::chrono::system_clock::time_point from_;
    std::chrono::system_clock::time_point to_;


    double value_;
};


class Balance {

public:
    Balance() = default;

    void addEarn(const Earn &earn) {

        earns_.push_back(earn);

        std::cout << "Earn added: " << earn.value() << std::endl;
        std::cout << "Value per day: " << earn.value() / getEarnPerDay(earn) << std::endl;


    }


    [[nodiscard]] double computeIncome(const std::string &from, const std::string &to) const {

        auto from_date = convertStringToDate(from);
        auto to_date = convertStringToDate(to);

        if (from_date > to_date) {
            throw std::invalid_argument("from > to");
        }

        double income = 0;

        for (const auto &earn: earns_) {
            if (earn.from() <= from_date && earn.to() >= to_date) {
                income += getEarnPerDay(earn) * getDaysBetweenDates(from_date, to_date);
            } else if (earn.from() <= from_date && earn.to() >= from_date) {
                income += getEarnPerDay(earn) * getDaysBetweenDates(from_date, earn.to());
            } else if (earn.from() <= to_date && earn.to() >= to_date) {
                income += getEarnPerDay(earn) * getDaysBetweenDates(earn.from(), to_date);
            } else if (earn.from() >= from_date && earn.to() <= to_date) {
                income += getEarnPerDay(earn) * getDaysBetweenDates(earn.from(), earn.to());
            }
        }

        return income;

    }

    [[nodiscard]] static double getEarnPerDay(const Earn &earn) {

      long long  days = getDaysBetweenDates(earn.from(), earn.to());
        return earn.value() / days;
    }

private:
    std::vector<Earn> earns_;


    static long
    getDaysBetweenDates(std::chrono::system_clock::time_point from, std::chrono::system_clock::time_point to) {

//        if (from == to) {
//            return 1;
//        }
//        return ((std::chrono::sys_days(to)).time_since_epoch() -
//                (std::chrono::sys_days(from)).time_since_epoch()).count() + 1;

        return ((to - from).count() / 86400) + 1;
    }


};


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
            auto t_from = convertStringToDate(from);
            auto t_to = convertStringToDate(to);
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