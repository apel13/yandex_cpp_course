//
// Created by apel on 21.01.2021.
//

#ifndef YANDEX_CPP_COURSE_HTTP_REQUEST_H
#define YANDEX_CPP_COURSE_HTTP_REQUEST_H

#include <string_view>

using namespace std;

struct HttpRequest {
    string_view method, uri, protocol;
};

#endif //YANDEX_CPP_COURSE_HTTP_REQUEST_H
