//
// Created by apel on 16.01.2021.
//

#ifndef YANDEX_CPP_COURSE_POLICEMAN_H
#define YANDEX_CPP_COURSE_POLICEMAN_H

#include <utility>

#include "Person.h"


class Policeman : public Person {
public:
    explicit Policeman(const std::string &name);

    void Check(const Person &person) const;

    void Walk(const std::string &destination) const override;
};

#endif //YANDEX_CPP_COURSE_POLICEMAN_H
