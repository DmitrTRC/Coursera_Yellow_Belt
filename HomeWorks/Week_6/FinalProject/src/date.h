//
// Created by Dmitry Morozov on 26/11/22.
//

#ifndef COURSERA_YELLOW_BELT_DEV_DATE_H
#define COURSERA_YELLOW_BELT_DEV_DATE_H

#include <ostream>

class Date {
public:

    Date(int, int, int);

    [[nodiscard]] int GetYear() const;

    [[nodiscard]] int GetMonth() const;

    [[nodiscard]] int GetDay() const;

private:
    int year_;
    int month_;
    int day_;
};

bool operator<(const Date &lhs, const Date &rhs);

std::ostream &operator<<(std::ostream &stream, const Date &date);

#endif //COURSERA_YELLOW_BELT_DEV_DATE_H
