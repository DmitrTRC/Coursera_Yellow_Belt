//
// Created by Dmitry Morozov on 20/9/22.
//

#include <iostream>


std::string add_operation(std::string &expression, std::string &next_operation) {

}

int main() {

    int x; // source number
    std::cin >> x;

    int N; // number of operations
    std::cin >> N;

    if (N == 0) {
        std::cout << x;
        return 0;
    }

    std::string expression;

    for (int i = 0; i < N; ++i) {
        std::string operation;
        std::getline(std::cin, operation);

        expression = add_operation(expression, operation);
    }

    std::cout << expression << std::endl;


    return 0;
}