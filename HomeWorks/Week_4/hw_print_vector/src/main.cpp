//
// Created by Dmitry Morozov on 20/9/22.
//

#include <algorithm>
#include <iostream>
#include <vector>

void PrintVectorPart(const std::vector<int>& numbers){
    auto it = std::find_if(numbers.begin(), numbers.end(), [](int x){return x < 0;});
    while (it != numbers.begin()){
        std::cout << *(--it) << " ";
    }
}

