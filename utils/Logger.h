#include <utility>

//
// Created by apel on 16.01.2021.
//

#ifndef YANDEX_CPP_COURSE_LOGGER_H
#define YANDEX_CPP_COURSE_LOGGER_H

class Logger {
public:
    explicit Logger(string name)
            : name_(std::move(name)) {
        cerr << "+ " << name_ << endl;
    }

    ~Logger() {
        cerr << "- " << name_ << endl;
    }

private:
    const string name_;
};

#endif //YANDEX_CPP_COURSE_LOGGER_H
