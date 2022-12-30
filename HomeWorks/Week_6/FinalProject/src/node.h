//
// Created by Dmitry Morozov on 26/11/22.
//

#ifndef COURSERA_YELLOW_BELT_DEV_NODE_H
#define COURSERA_YELLOW_BELT_DEV_NODE_H

#include "date.h"
#include "sstream"

struct Node {

    [[nodiscard]] virtual bool Evaluate(const Date &date, const std::string &event) const = 0;

};


#endif //COURSERA_YELLOW_BELT_DEV_NODE_H
