//
// Created by Dmitry Morozov on 20/9/22.
//

#include <iostream>
#include <vector>
#include <map>


template<typename T>
T Sqr (T x);

template<typename T>
std::vector<T> Sqr (const std::vector<T> &x);

template<typename Key, typename Value>
std::map<Key, Value> Sqr (const std::map<Key, Value> &x);

template<typename First, typename Second>
std::pair<First, Second> Sqr (const std::pair<First, Second> &x);

int main () {

    std::vector<int> v = {1, 2, 3};
    std::cout << "vector:";
    for (int x: Sqr (v)) {
        std::cout << ' ' << x;
    }
    std::cout << std::endl;

    std::map<int, std::pair<int, int>> map_of_pairs = {
            {4, {2, 2}},
            {7, {4, 3}}
    };
    std::cout << "map of pairs:" << std::endl;
    for (const auto &x: Sqr (map_of_pairs)) {
        std::cout << x.first << ' ' << x.second.first << ' ' << x.second.second << std::endl;
    }
    return 0;
}

template<typename T>
T Sqr (T x) {
    return x * x;
}

template<typename T>
std::vector<T> Sqr (const std::vector<T> &x) {
    std::vector<T> result;
    for (const auto &item: x) {
        result.push_back (Sqr (item));
    }
    return result;
}

template<typename Key, typename Value>
std::map<Key, Value> Sqr (const std::map<Key, Value> &x) {
    std::map<Key, Value> result;
    for (const auto &[key, value]: x) {
        result[key] = Sqr (value);
    }
    return result;
}

template<typename First, typename Second>
std::pair<First, Second> Sqr (const std::pair<First, Second> &x) {
    return {Sqr (x.first), Sqr (x.second)};
}