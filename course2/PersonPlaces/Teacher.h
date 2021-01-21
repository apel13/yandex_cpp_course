//
// Created by apel on 16.01.2021.
//

#ifndef YANDEX_CPP_COURSE_TEACHER_H
#define YANDEX_CPP_COURSE_TEACHER_H

#include "Person.h"

#include <utility>

class Teacher : public Person {
public:
    Teacher(const std::string &name, const std::string &subject);

    void Teach() const;

    void Walk(const std::string &destination) const override;

private:
    const std::string _subject;
};


#endif //YANDEX_CPP_COURSE_TEACHER_H
