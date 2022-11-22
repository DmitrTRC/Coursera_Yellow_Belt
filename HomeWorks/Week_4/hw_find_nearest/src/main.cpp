//
// Created by Dmitry Morozov on 20/9/22.
//

#include <iostream>
#include <set>

std::set<int>::const_iterator FindNearestElement(
        const std::set<int>& numbers,
        int border) {

    if (numbers.empty()) {
        return numbers.end();

    }

    auto it  = numbers.lower_bound(border);

if (it == numbers.begin()) {
        return it;
    }

    if (it == numbers.end()) {
        return std::prev(it);
    }

    auto left = std::prev(it);

    if (border - *left <= *it - border) {
        return left;
    }

    return it;

}
//int main () {
//    std::set<int> numbers = {1, 4, 8, 9, 7, 5};
//
//    std::cout << *FindNearestElement(numbers, 0) << std::endl;
//    std::cout << *FindNearestElement(numbers, 3) << std::endl;
//    std::cout << *FindNearestElement(numbers, 5) << std::endl;
//    std::cout << *FindNearestElement(numbers, 6) << std::endl;
//    std::cout << *FindNearestElement(numbers, 8) << std::endl;
//    std::cout << *FindNearestElement(numbers, 100) << std::endl;
//
//
//    return 0;
//}