//
// Created by apel on 16.01.2021.
//

#ifndef YANDEX_CPP_COURSE_PERSON_H
#define YANDEX_CPP_COURSE_PERSON_H

#include <iostream>
#include <string>
#include <utility>
#include <vector>

class Person {
public:
    Person(const std::string &name, const std::string &occupation);

    virtual void Walk(const std::string &destination) const = 0;

    std::string getName() const;

    std::string getOccupation() const;

private:
    const std::string _name;
    const std::string _occupation;
};

void VisitPlaces(const Person &person, const std::vector<std::string> &places);

#endif //YANDEX_CPP_COURSE_PERSON_H
