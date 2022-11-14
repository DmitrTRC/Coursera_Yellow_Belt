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
};

class Account {

public:
    Account() = default;

    void addEarn(const Earn &earn) {

        earns_.push_back(earn);
    }

    [[nodiscard]] double computeIncome(const std::string &from, const std::string &to) const {

        double income = 0;
        std::accumulate(earns_.begin(), earns_.end(), 0, [&income, &from, &to](int sum, const Earn &earn) {
            if (earn.from() <= from && earn.to() >= to) {
                income += earn.value();
            }
            return sum;
        });
        return income;
    }

private:
    std::vector<Earn> earns_;
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