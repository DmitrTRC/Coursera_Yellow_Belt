//
// Created by Dmitry Morozov on 20/9/22.
//

#include <iostream>
#include <iterator>


void add_operation(std::string &expression, std::string &next_operation) {
    // Set front bracket
    expression.insert(expression.begin(), '(');
    expression.append(") ");

    // Add operation
    expression += next_operation;

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

    std::string expression = std::to_string(x);
    std::cin.ignore();

    for (int i = 0; i < N; ++i) {
        std::string operation;

        std::getline(std::cin, operation);

        add_operation(expression, operation);
    }

    std::cout << expression << std::endl;


    return 0;
}