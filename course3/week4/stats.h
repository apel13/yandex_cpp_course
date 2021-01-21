//
// Created by apel on 21.01.2021.
//

#ifndef YANDEX_CPP_COURSE_STATS_H
#define YANDEX_CPP_COURSE_STATS_H

#include "http_request.h"

#include <string_view>
#include <map>

using namespace std;

class Stats {
public:
    Stats();

    void AddMethod(std::string_view method);

    void AddUri(std::string_view uri);

    const std::map<std::string_view, int> &GetMethodStats() const;

    const std::map<std::string_view, int> &GetUriStats() const;

private:
    std::map<std::string_view, int> _methods;
    std::map<std::string_view, int> _uris;
};

HttpRequest ParseRequest(std::string_view line);

#endif //YANDEX_CPP_COURSE_STATS_H
