//
// Created by Dmitry Morozov on 23/11/22.
//


#include <iostream>
#include <iterator>
#include <map>

std::map<char, int> opPriority = {
        {'+', 1},
        {'-', 1},
        {'*', 2},
        {'/', 2},
        {'^', 3},
        {'(', 0},
        {')', 0}
};


void add_operation(std::string &expression, std::string &next_operation) {

    // Set front bracket
    static char last_operation = ' ';

    if (opPriority[last_operation] < opPriority[next_operation[0]]) {

        expression.insert(expression.begin(), '(');
        expression.append(") ");

        // Add operation
        expression += next_operation;
    } else {
        expression += next_operation;
    }

    last_operation = next_operation[0];

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