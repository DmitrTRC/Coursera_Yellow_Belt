//
// Created by Dmitry Morozov on 14/11/22.
//
/// Merge sort algorithm divides the array into three parts, sorts the three parts

#include <algorithm>

template<typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end) {

    if (range_end - range_begin < 3) {
        return;
    }

    std::vector<typename RandomIt::value_type> elements(range_begin, range_end);

    auto it1 = elements.begin() + elements.size() / 3;
    auto it2 = elements.begin() + elements.size() * 2 / 3;
    auto it3 = elements.end();

    MergeSort(elements.begin(), it1);
    MergeSort(it1, it2);
    MergeSort(it2, it3);

    std::vector<typename RandomIt::value_type> temp;

    std::merge(elements.begin(), it1, it1, it2, std::back_inserter(temp));
    std::merge(temp.begin(), temp.end(), it2, it3, range_begin);

}
