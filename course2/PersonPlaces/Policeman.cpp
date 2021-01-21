//
// Created by apel on 16.01.2021.
//

#include "Policeman.h"

Policeman::Policeman(const std::string &name)
        : Person(name, "Policeman") {}

void Policeman::Check(const Person &person) const {
    std::cout << "Policeman: " << getName() << " checks " << person.getOccupation() << ". "
              << person.getOccupation() << "'s name is: " << person.getName() << std::endl;
}

void Policeman::Walk(const std::string &destination) const {
    std::cout << "Policeman: " << getName() << " walks to: " << destination << std::endl;
}
