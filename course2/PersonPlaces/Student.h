//
// Created by apel on 16.01.2021.
//

#ifndef YANDEX_CPP_COURSE_STUDENT_H
#define YANDEX_CPP_COURSE_STUDENT_H

#include "Person.h"

#include <iostream>
#include <utility>

class Student : public Person {
public:
    Student(const std::string &name, const std::string &favouriteSong);

    void Learn() const;

    void Walk(const std::string &destination) const override;

    void SingSong() const;

private:
    const std::string _favouriteSong;
};

#endif //YANDEX_CPP_COURSE_STUDENT_H
