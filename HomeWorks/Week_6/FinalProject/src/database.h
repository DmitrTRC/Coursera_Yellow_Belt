//
// Created by Dmitry Morozov on 26/11/22.
//

#ifndef COURSERA_YELLOW_BELT_DEV_DATABASE_H
#define COURSERA_YELLOW_BELT_DEV_DATABASE_H

#include "date.h"

#include <iostream>
#include <map>
#include <set>
#include <vector>

class Database {

public:
    void Add(const Date &date, const std::string &event);

    void Print(std::ostream &os) const;

    template<typename Predicate>
    int RemoveIf(Predicate predicate);

    template<typename Predicate>
    std::vector<std::string> FindIf(Predicate predicate) const;

    std::string Last(const Date &date) const;

private:

    std::map <Date, std::set<std::string>> storage_;
};


#endif //COURSERA_YELLOW_BELT_DEV_DATABASE_H
