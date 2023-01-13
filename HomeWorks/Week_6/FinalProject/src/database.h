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

    void Print(std::ostream &is) const;

    [[nodiscard]] std::string Last(const Date &date) const;

    template<typename Functor>
    int RemoveIf(const Functor &func);

    template<typename Functor>
    std::vector<std::pair<Date, std::string>> FindIf(const Functor &func) const;

private:
    std::map<Date, std::pair<std::set<std::string>, std::vector<std::set<std::string>::iterator>>> db;
};

template<typename Functor>
int Database::RemoveIf(const Functor &functor) {

    int count = 0;

    for (auto &date_it: db) {
        auto itr = std::stable_partition(date_it.second.second.begin(), date_it.second.second.end(),
                                         [&](const auto &event) -> bool {
                                             if (functor(date_it.first, *event)) {
                                                 count++;
                                                 date_it.second.first.erase(*event);
                                                 return false;
                                             }
                                             return true;
                                         });
        date_it.second.second.erase(itr, date_it.second.second.end());
    }

    for (auto erase_it = db.cbegin(), next_it = erase_it; erase_it != db.cend(); erase_it = next_it) {
        ++next_it;
        if (erase_it->second.first.empty()) {
            db.erase(erase_it);
        }
    }
    return count;
}

template<typename Functor>
std::vector<std::pair<Date, std::string>> Database::FindIf(const Functor &functor) const {

    std::vector<std::pair<Date, std::string>> temp;

    for (const auto &date_it: db) {
        auto it = std::find_if(date_it.second.second.begin(), date_it.second.second.end(),
                               [&](const auto &event) -> bool {
                                   if (functor(date_it.first, *event)) {
                                       temp.push_back(std::make_pair(date_it.first, *event));
                                   }
                                   return false;
                               });
    }
    return temp;
}

#endif //COURSERA_YELLOW_BELT_DEV_DATABASE_H
