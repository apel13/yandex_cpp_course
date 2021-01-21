//
// Created by apel on 15.01.2021.
//

#ifndef YANDEX_CPP_COURSE_REGION_H
#define YANDEX_CPP_COURSE_REGION_H

enum class Lang {
    DE, FR, IT
};

struct Region {
    string std_name;
    string parent_std_name;
    map<Lang, string> names;
    int64_t population;
};


bool operator<(const Region& lhs, const Region& rhs) {
    return tie(lhs.std_name, lhs.parent_std_name, lhs.names, lhs.population) <
           tie(rhs.std_name, rhs.parent_std_name, rhs.names, rhs.population);
}

int FindMaxRepetitionCount(const vector<Region>& regions) {
    int result = 0;
    map<Region, int> m;
    for (const auto& region : regions)
        result = std::max(result, ++m[region]);
    return result;
}

#endif //YANDEX_CPP_COURSE_REGION_H
