//
// Created by apel on 16.01.2021.
//

#include "phone_number.h"

#include <iostream>
#include <regex>
#include <exception>

/* Принимает строку в формате +XXX-YYY-ZZZZZZ
   Часть от '+' до первого '-' - это код страны.
   Часть между первым и вторым символами '-' - код города
   Всё, что идёт после второго символа '-' - местный номер.
   Код страны, код города и местный номер не должны быть пустыми.
   Если строка не соответствует этому формату, нужно выбросить исключение invalid_argument. Проверять, что номер содержит только цифры, не нужно.

   Примеры:
   * +7-495-111-22-33
   * +7-495-1112233
   * +323-22-460002
   * +1-2-coursera-cpp
   * 1-2-333 - некорректный номер - не начинается на '+'
   * +7-1233 - некорректный номер - есть только код страны и города
*/
PhoneNumber::PhoneNumber(const string &international_number) {
    std::smatch base_match;
    const std::regex base_regex("\\+([0-9]+)-([0-9]+)-(.+)");
    if (!regex_match(international_number, base_match, base_regex))
        throw std::invalid_argument("");
    country_code_ = base_match[1];
    city_code_ = base_match[2];
    local_number_ = base_match[3];
}

string PhoneNumber::GetCountryCode() const {
    return this->country_code_;
}

string PhoneNumber::GetCityCode() const {
    return this->city_code_;
}

string PhoneNumber::GetLocalNumber() const {
    return this->local_number_;
}

string PhoneNumber::GetInternationalNumber() const {
    return '+' + country_code_ + '-' + city_code_ + '-' + local_number_;
}



