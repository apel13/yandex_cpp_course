//
// Created by apel on 17.01.2021.
//

#ifndef YANDEX_CPP_COURSE_NODE_H
#define YANDEX_CPP_COURSE_NODE_H

#include "../Date/date.h"

struct Node {
    virtual bool Evaluate(const Date &, const std::string &) const = 0;
};

#endif //YANDEX_CPP_COURSE_NODE_H
