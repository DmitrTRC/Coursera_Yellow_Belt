//
// Created by Dmitry Morozov on 26/11/22.
//

#ifndef COURSERA_YELLOW_BELT_DEV_DATE_H
#define COURSERA_YELLOW_BELT_DEV_DATE_H

#include <string>
#include <stdexcept>
#include <sstream>
#include <iomanip>
#include <memory>

class Date {
public:
    Date() noexcept;

    Date(int new_year, int new_month, int new_day);

    [[nodiscard]] int GetYear() const noexcept;

    [[nodiscard]] int GetMonth() const noexcept;

    [[nodiscard]] int GetDay() const noexcept;

    [[nodiscard]] std::string DateToStr() const;

private:
    int year;
    int month;
    int day;
};

Date ParseDate(std::istream &is);

std::ostream &operator<<(std::ostream &os, const Date &date);

std::ostream &operator<<(std::ostream &os, const std::pair<Date, std::string> &pair);

bool operator<(const Date &lsh, const Date &rhs) noexcept;

bool operator<=(const Date &lsh, const Date &rhs) noexcept;

bool operator>(const Date &lsh, const Date &rhs) noexcept;

bool operator>=(const Date &lsh, const Date &rhs) noexcept;

bool operator==(const Date &lsh, const Date &rhs) noexcept;

bool operator!=(const Date &lsh, const Date &rhs) noexcept;

#endif //COURSERA_YELLOW_BELT_DEV_DATE_H
