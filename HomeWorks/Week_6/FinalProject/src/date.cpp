//
// Created by Dmitry Morozov on 26/11/22.
//

#include "date.h"

#include <iomanip>
#include <vector>

Date::Date(int new_year, int new_month, int new_day) {

    year_ = new_year;
    if (new_month > 12 || new_month < 1) {
        throw std::logic_error("Month value is invalid: " + std::to_string(new_month));
    }
    month_ = new_month;
    if (new_day > 31 || new_day < 1) {
        throw std::logic_error("Day value is invalid: " + std::to_string(new_day));
    }
    day_ = new_day;
}

int Date::GetMonth() const {

    return month_;
}

int Date::GetYear() const {

    return year_;
}

int Date::GetDay() const {

    return day_;
}

bool operator<(const Date &lhs, const Date &rhs) {

    return std::vector<int>{lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()} <
           std::vector<int>{rhs.GetYear(), rhs.GetMonth(), rhs.GetDay()};
}

std::ostream &operator<<(std::ostream &stream, const Date &date) {

    stream << std::setw(4) << std::setfill('0') << date.GetYear() <<
           "-" << std::setw(2) << std::setfill('0') << date.GetMonth() <<
           "-" << std::setw(2) << std::setfill('0') << date.GetDay();
    return stream;
}
