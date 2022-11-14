//
// Created by Dmitry Morozov on 20/9/22.
//

#include <iostream>
#include <algorithm>
#include <vector>

enum class Gender {
    FEMALE,
    MALE
};

struct Person {
    int age;  // возраст
    Gender gender;  // пол
    bool is_employed;  // имеет ли работу
};

template<typename InputIt>
int ComputeMedianAge(InputIt range_begin, InputIt range_end);

///output
//Median age = 40
//Median age for females = 40
//Median age for males = 55
//Median age for employed females = 40
//Median age for unemployed females = 80
//Median age for employed males = 55
//Median age for unemployed males = 78
void PrintStats(std::vector<Person> persons) {





}

int main() {

    std::vector<Person> persons = {
            {31, Gender::MALE,   false},
            {40, Gender::FEMALE, true},
            {24, Gender::MALE,   true},
            {20, Gender::FEMALE, true},
            {80, Gender::FEMALE, false},
            {78, Gender::MALE,   false},
            {10, Gender::FEMALE, false},
            {55, Gender::MALE,   true},
    };

    PrintStats(persons);

    return 0;
}