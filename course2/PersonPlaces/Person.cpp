//
// Created by apel on 17.01.2021.
//

#include "Person.h"

Person::Person(const std::string &name, const std::string &occupation)
        : _name(name), _occupation(occupation) {}

std::string Person::getName() const {
    return _name;
}

std::string Person::getOccupation() const {
    return _occupation;
}

void VisitPlaces(const Person &person, const std::vector<std::string> &places) {
    for (const auto &place : places) {
        person.Walk(place);
    }
}