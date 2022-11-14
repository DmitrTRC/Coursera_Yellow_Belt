//
// Created by Dmitry Morozov on 20/9/22.
//

#include <algorithm>
#include <iostream>
#include <vector>


auto getPermutations(int n) {

    std::vector<std::vector<int>> permutations;
    std::vector<int> permutation(n);

    for (int i = n; i != 0; --i) {
        permutation[n - i] = i;
    }

    do {
        permutations.push_back(permutation);
    } while (std::prev_permutation(permutation.begin(), permutation.end()));

    return permutations;
}

int main() {

    int N;
    std::cin >> N;

    auto permutations = getPermutations(N);
    for (const auto &permutation: permutations) {
        for (int x: permutation) {
            std::cout << x << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}