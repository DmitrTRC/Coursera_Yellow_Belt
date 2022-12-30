//
// Created by Dmitry Morozov on 30/12/22.
//

#include "Helper.h"

#include <sstream>


#pragma clang diagnostic push
#pragma ide diagnostic ignored "ConstantConditionsOC"

Date ParseDate(std::istringstream &date_stream) {

    bool ok = true;
    int year;

    ok = ok && (date_stream >> year);
    ok = ok && (date_stream.peek() == '-');
    date_stream.ignore(1);

    int month;
    ok = ok && (date_stream >> month);
    ok = ok && (date_stream.peek() == '-');
    date_stream.ignore(1);

    int day;
    ok = ok && (date_stream >> day);
    ok = ok && date_stream.eof();

    if (!ok) {
        throw std::logic_error("Wrong date format: " + date_stream.str());
    }
    return Date(year, month, day);
}

#pragma clang diagnostic pop