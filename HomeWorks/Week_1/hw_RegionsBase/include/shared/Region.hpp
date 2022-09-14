//
// Created by Dmitry Morozov on 15/9/22.
//

#ifndef COURSERA_YELLOW_BELT_MAIN_REGION_HPP
#define COURSERA_YELLOW_BELT_MAIN_REGION_HPP

#include <map>
#include <string>


enum class Lang {
    DE, FR, IT
};


struct Region {
    std::string std_name;
    std::string parent_std_name;
    std::map<Lang, std::string> names;
    int64_t population;
};


#endif //COURSERA_YELLOW_BELT_MAIN_REGION_HPP
