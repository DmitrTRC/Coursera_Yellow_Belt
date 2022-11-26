//
// Created by Dmitry Morozov on 26/11/22.
//

#include "database.h"
#include "date.h"

#include <iostream>
#include <map>
#include <set>

void Database::Add(const Date &date, const std::string &event) {

    storage_[date].insert(event);
}

void Database::Print(std::ostream &os) const {

    for (const auto &item: storage_) {
        for (const std::string &event: item.second) {
            std::cout << item.first << " " << event << std::endl;
        }
    }
}

template<typename Predicate>
int Database::RemoveIf(Predicate predicate) {

    return 0;
}
