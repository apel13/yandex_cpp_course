//
// Created by apel on 16.01.2021.
//

#include "Student.h"

Student::Student(const std::string &name, const std::string &favouriteSong)
        : Person(name, "Student"), _favouriteSong(favouriteSong) {}

void Student::Learn() const {
    std::cout << "Student: " << getName() << " learns" << std::endl;
}

void Student::Walk(const std::string &destination) const {
    std::cout << "Student: " << getName() << " walks to: " << destination << std::endl;
    SingSong();
}

void Student::SingSong() const {
    std::cout << "Student: " << getName() << " sings a song: " << _favouriteSong << std::endl;
}
