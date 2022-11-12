//
// Created by Dmitry Morozov on 12/11/22.
//

#include "phone_number.h"


PhoneNumber::PhoneNumber(const string &international_number) {

    if (international_number[0] != '+') {
        throw invalid_argument("Invalid number");
    }

    size_t first_dash = international_number.find('-');
    size_t second_dash = international_number.find('-', first_dash + 1);

    if (first_dash == string::npos || second_dash == string::npos) {
        throw invalid_argument("Invalid number");
    }

    country_code_ = international_number.substr(1, first_dash - 1);
    city_code_ = international_number.substr(first_dash + 1, second_dash - first_dash - 1);
    local_number_ = international_number.substr(second_dash + 1);

    if (country_code_.empty() || city_code_.empty() || local_number_.empty()) {
        throw invalid_argument("Invalid number");
    }

}

string PhoneNumber::GetCountryCode() const {

    return country_code_;

}

string PhoneNumber::GetCityCode() const {

    return city_code_;

}

string PhoneNumber::GetLocalNumber() const {

    return local_number_;

}

string PhoneNumber::GetInternationalNumber() const {

    return "+" + country_code_ + "-" + city_code_ + "-" + local_number_;


}

