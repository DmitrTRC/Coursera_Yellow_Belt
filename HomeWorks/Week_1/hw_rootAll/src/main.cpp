//
// Created by Dmitry Morozov on 20/9/22.
//

#include <iostream>
#include <vector>
#include <map>
#include <tuple>


// Предварительное объявление шаблонных функций
template<typename T>
T FuncA (T x);

template<typename T>
void FuncB (T x);


int main () {
    // Пример вызова функции
    std::vector<int> v = {1, 2, 3};
    std::cout << "vector:";
    for (int x : Sqr(v)) {
        std::cout << ' ' << x;
    }
    std::cout << std::endl;

    std::map<int, std::pair<int, int>> map_of_pairs = {
            {4, {2, 2}},
            {7, {4, 3}}
    };
    std::cout << "map of pairs:" << std::endl;
    for (const auto& x : Sqr(map_of_pairs)) {
        std::cout << x.first << ' ' << x.second.first << ' ' << x.second.second << endl;
    }
    return 0;
}

// Объявляем шаблонные функции
template<typename T>
T FuncA (T x) { /*...*/ }

template<typename T>
void FuncB (T x) { /*...*/ }
