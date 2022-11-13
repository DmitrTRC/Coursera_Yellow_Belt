//
// Created by Dmitry Morozov on 20/9/22.
//

#include <algorithm>
#include <iostream>
#include <vector>


auto getPermutations(int n) {

    std::vector<std::vector<int>> permutations;
    std::vector<int> permutation(n);
    for (int i = 0; i < n; ++i) {
        permutation[i] = i + 1;
    }
    do {
        permutations.push_back(permutation);
    } while (std::prev_permutation(permutation.begin(), permutation.end()));
    return permutations;
}

int main() {

    int N;
    std::cin >> N;


    return 0;
}