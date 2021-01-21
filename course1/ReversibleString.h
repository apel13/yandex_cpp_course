//
// Created by apel on 14.01.2021.
//

#ifndef YANDEX_CPP_COURSE_REVERSIBLESTRING_H
#define YANDEX_CPP_COURSE_REVERSIBLESTRING_H

class ReversibleString {
public:
    ReversibleString() = default;
    explicit ReversibleString(string str)
            : s(std::move(str)) {}

    void Reverse() {
        std::reverse(s.begin(), s.end());
    }

    string ToString() const {
        return s;
    }

private:
    string s;
};

#endif //YANDEX_CPP_COURSE_REVERSIBLESTRING_H
