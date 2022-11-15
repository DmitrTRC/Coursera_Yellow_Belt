//
// Created by Dmitry Morozov on 20/9/22.
//

#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
#include <numeric>

/**
 * @brief Implement a personal budgeting system. You need to process requests of the following types:

ComputeIncome from to: Compute the net income for the given date range.

Earn from to value: take into account that for the specified period (evenly over the days) the amount value was earned.

Notes:

In all from to ranges, both from and to dates are included.

Input Format
The first line enters the number of requests Q, then the requests themselves are entered in the format described above, one per line.

Output Format
For each ComputeIncome query, on a separate line print a real number — profit for the specified date range.

Note:

use std::cout.precision(25) in your code for uniform output of real numbers

Restrictions
The number of requests Q is a natural number not exceeding 50.

All dates are entered in YYYY-MM-DD format. The dates are correct (including leap years) and belong to the interval from 2000 to 2099.

value are positive integers not exceeding 1000000.

1 second to process all requests.

Clue
Use std::accumulate to calculate sums.
*/
class Earn {
public:
    Earn(std::string from, std::string to, int value) : from_(std::move(from)), to_(std::move(to)), value_(value) {}

    [[nodiscard]] const std::string &from() const { return from_; }

    [[nodiscard]] const std::string &to() const { return to_; }

    [[nodiscard]] int value() const { return value_; }

private:
    std::string from_;
    std::string to_;
    int value_;
    double value_per_day_;
    void calculate_value_per_day() {
        value_per_day_ = value_ / days_between(from_, to_);
    }
};

class Date {
public:
    Date(std::string date) {

        year_ = std::stoi(date.substr(0, 4));
        month_ = std::stoi(date.substr(5, 2));
        day_ = std::stoi(date.substr(8, 2));
    }

    [[nodiscard]] int year() const { return year_; }

    [[nodiscard]] int month() const { return month_; }

    [[nodiscard]] int day() const { return day_; }

private:
    int year_;
    int month_;
    int day_;

    void _parseDate(std::string date) {

        year_ = std::stoi(date.substr(0, 4));
        month_ = std::stoi(date.substr(5, 2));
        day_ = std::stoi(date.substr(8, 2));

    }

};

bool operator<(const Date &lhs, const Date &rhs) {

    if (lhs.year() < rhs.year()) {
        return true;
    } else if (lhs.year() == rhs.year()) {
        if (lhs.month() < rhs.month()) {
            return true;
        } else if (lhs.month() == rhs.month()) {
            if (lhs.day() < rhs.day()) {
                return true;
            }
        }
    }
    return false;

}


class Account {

public:
    Account() = default;

    void addEarn(const Earn &earn) {

        earns_.push_back(earn);
    }

    [[nodiscard]] double computeIncome(const std::string &from, const std::string &to) const {

        double income = 0;

        for (const auto &earn: earns_) {

            if ((earn.from() <= from) && (earn.to() >= to)) {

                income += earn.value();
            }
        }


    }

private:
    std::vector<Earn> earns_;

    bool isDateInRange(const std::string &date, const std::string &from, const std::string &to) const {

        return date >= from && date <= to;
    }
};

void commander(int nCommands) {

    Account account;

    for (int i = 0; i < nCommands; ++i) {
        std::string command;
        std::cin >> command;
        if (command == "Earn") {
            std::string from;
            std::string to;
            int value;
            std::cin >> from >> to >> value;
            account.addEarn(Earn(from, to, value));
        } else if (command == "ComputeIncome") {
            std::string from;
            std::string to;
            std::cin >> from >> to;
            std::cout.precision(25);
            std::cout << account.computeIncome(from, to) << std::endl;
        }
    }


}

int main() {

    int nCommands;
    std::cin >> nCommands;
    commander(nCommands);

    return 0;
}