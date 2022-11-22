//
// Created by Dmitry Morozov on 20/9/22.
//

#include <iostream>
#include <map>

std::string FindNameByYear(const std::map<int, std::string> &names, int year) {

    std::string name;  // изначально имя неизвестно

    // перебираем всю историю по возрастанию ключа словаря, то есть в хронологическом порядке
    for (const auto &item: names) {
        // если очередной год не больше данного, обновляем имя
        if (item.first <= year) {
            name = item.second;
        } else {
            // иначе пора остановиться, так как эта запись и все последующие относятся к будущему
            break;
        }
    }

    return name;
}

class Person {
public:
    void ChangeFirstName(int year, const std::string &first_name) {

        first_names[year] = first_name;
    }

    void ChangeLastName(int year, const std::string &last_name) {

        last_names[year] = last_name;
    }

    std::string GetFullName(int year) {
        // получаем имя и фамилию по состоянию на год year
        const std::string first_name = FindNameByYear(first_names, year);
        const std::string last_name = FindNameByYear(last_names, year);

        // если и имя, и фамилия неизвестны
        if (first_name.empty() && last_name.empty()) {
            return "Incognito";

            // если неизвестно только имя
        } else if (first_name.empty()) {
            return last_name + " with unknown first name";

            // если неизвестна только фамилия
        } else if (last_name.empty()) {
            return first_name + " with unknown last name";

            // если известны и имя, и фамилия
        } else {
            return first_name + " " + last_name;
        }
    }

private:
    std::map<int, std::string> first_names;
    std::map<int, std::string> last_names;
};

int main() {

    return 0;
}