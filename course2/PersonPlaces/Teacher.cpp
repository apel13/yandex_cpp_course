//
// Created by apel on 16.01.2021.
//

#include "Teacher.h"

Teacher::Teacher(const std::string &name, const std::string &subject)
        : Person(name, "Teacher"), _subject(subject) {}

void Teacher::Teach() const {
    std::cout << "Teacher: " << getName() << " teaches: " << _subject << std::endl;
}

void Teacher::Walk(const std::string &destination) const {
    std::cout << "Teacher: " << getName() << " walks to: " << destination << std::endl;
}
