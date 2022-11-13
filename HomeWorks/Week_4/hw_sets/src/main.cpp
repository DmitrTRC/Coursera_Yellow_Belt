//
// Created by Dmitry Morozov on 20/9/22.
//

#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

template<typename T>
std::vector<T> FindGreaterElements(const std::set<T> &elements, const T &border) {

    auto it = std::find_if(elements.begin(), elements.end(), [border](T x) { return x > border; });

    return {it, elements.end()};
}

int main() {

    for (int x: FindGreaterElements(std::set<int>{1, 5, 7, 8}, 5)) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    std::string to_find = "Python";
    std::cout << FindGreaterElements(std::set<std::string>{"C", "C++"}, to_find).size() << std::endl;

    return 0;
}
