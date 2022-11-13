//
// Created by Dmitry Morozov on 20/9/22.
//

#include <iostream>
#include <vector>

std::vector<std::string> SplitIntoWords(const std::string &s) {

    std::vector<std::string> result;

    auto it = s.begin();
    while (it != s.end()) {
        auto it2 = std::find(it, end(s), ' ');
        result.push_back(std::string(it, it2));
        it = it2;

        if (it != end(s)) {
            it++;
        }
    }


    return result;
}


int main() {

    std::string s = "C Cpp Java Python";

    std::vector<std::string> words = SplitIntoWords(s);
    std::cout << words.size() << " ";
    for (auto it = begin(words); it != end(words); ++it) {
        if (it != begin(words)) {
            std::cout << "/";
        }
        std::cout << *it;
    }
    std::cout << std::endl;

    return 0;
}
