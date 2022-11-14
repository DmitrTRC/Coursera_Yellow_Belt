//
// Created by Dmitry Morozov on 20/9/22.
//
#include <algorithm>
#include <iostream>
#include <vector>

template<typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end) {

    if (range_end - range_begin < 2) {
        return;
    }

    std::vector<typename RandomIt::value_type> elements(range_begin, range_end);

    auto it = elements.begin() + elements.size() / 2;

    MergeSort(elements.begin(), it);
    MergeSort(it, elements.end());

    std::merge(elements.begin(), it, it, elements.end(), range_begin);

}


int main() {

    std::vector<int> v = {6, 4, 7, 6, 4, 4, 0, 1, 5};
    MergeSort(begin(v), end(v));
    for (int x: v) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
    return 0;
}