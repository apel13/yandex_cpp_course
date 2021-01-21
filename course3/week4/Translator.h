//
// Created by apel on 19.01.2021.
//

#ifndef YANDEX_CPP_COURSE_TRANSLATOR_H
#define YANDEX_CPP_COURSE_TRANSLATOR_H

#include <string_view>
#include <deque>
#include <map>

class Translator {
public:
    void Add(std::string_view source,
             std::string_view target) {
        std::string_view source_copy = find_if_exist(source);
        std::string_view target_copy = find_if_exist(target);
        _forward[source_copy] = target_copy;
        _backward[target_copy] = source_copy;
    }

    std::string_view TranslateForward(std::string_view source) const {
        return _forward.find(source) != _forward.end()
               ? _forward.at(source) : "";
    }

    std::string_view TranslateBackward(std::string_view target) const {
        return _backward.find(target) != _backward.end()
               ? _backward.at(target) : "";
    }

private:
    std::deque<std::string> _words;
    std::map<std::string_view, std::string_view> _forward;
    std::map<std::string_view, std::string_view> _backward;

    std::string_view find_if_exist(std::string_view sv) {
        const auto itf = _forward.find(sv);
        if (itf != _forward.end())
            return itf->first;
        const auto itb = _backward.find(sv);
        if (itb != _backward.end())
            return itb->first;
        return _words.emplace_back(sv);
    }
};

#endif //YANDEX_CPP_COURSE_TRANSLATOR_H
