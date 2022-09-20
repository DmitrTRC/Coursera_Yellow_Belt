//
// Created by Dmitry Morozov on 20/9/22.
//

#include <iostream>
#include <map>


/// @brief Get reference to value by key
template<typename Key, typename Value>
Value &GetRefStrict (std::map<Key, Value> &, Key);


template<typename Key, typename Value>
Value &GetRefStrict (std::map<Key, Value> &m, Key k) {
    if (m.count (k) == 0) {
        throw std::runtime_error ("Key not found");
    }
    return m[k];
}

int main () {
    std::map<int, std::string> m = {{0, "value"}};
    std::string &item = GetRefStrict (m, 0);
    item = "newvalue";
    std::cout << m[0] << std::endl; // выведет newvalue
    return 0;
}