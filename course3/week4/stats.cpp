//
// Created by apel on 21.01.2021.
//

#include "stats.h"

Stats::Stats() {
    _methods = {
            {"GET",     0},
            {"PUT",     0},
            {"POST",    0},
            {"DELETE",  0},
            {"UNKNOWN", 0}
    };

    _uris = {
            {"/",        0},
            {"/order",   0},
            {"/product", 0},
            {"/basket",  0},
            {"/help",    0},
            {"unknown",  0}
    };
}

void Stats::AddMethod(std::string_view method) {
    if (_methods.find(method) != _methods.end())
        _methods[method]++;
    else
        _methods[std::string_view("UNKNOWN")]++;
}

void Stats::AddUri(std::string_view uri) {
    if (_uris.find(uri) != _uris.end())
        _uris[uri]++;
    else
        _uris[std::string_view("unknown")]++;
}

const std::map<std::string_view, int> &Stats::GetMethodStats() const {
    return _methods;
}

const std::map<std::string_view, int> &Stats::GetUriStats() const {
    return _uris;
}


HttpRequest ParseRequest(std::string_view line) {
    HttpRequest ret;

    size_t pos = 0;
    while (line[pos] == ' ' && pos != std::string_view::npos) {
        ++pos;
    }
    line.remove_prefix(pos);

    size_t delimiter = line.find(' ');
    ret.method = line.substr(0, delimiter);

    line.remove_prefix(++delimiter);
    delimiter = line.find(' ');
    ret.uri = line.substr(0, delimiter);

    line.remove_prefix(++delimiter);
    ret.protocol = line;
    return ret;
}
