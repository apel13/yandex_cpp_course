//
// Created by apel on 19.01.2021.
//

#ifndef YANDEX_CPP_COURSE_READINGMANAGER_H
#define YANDEX_CPP_COURSE_READINGMANAGER_H

#include <vector>
#include <unordered_map>


class ReadingManager {
public:
    ReadingManager()
            : _page_before(std::vector<int>(1001, 0)) {}

    void Read(int user_id, int page_count) {
        if (_user_to_page.count(user_id) == 0)
            for (int i = page_count + 1; i < 1001; ++i)
                _page_before[i]++;

        else
            for (int i = _user_to_page[user_id] + 1; i <= page_count; ++i)
                _page_before[i]--;

        _user_to_page[user_id] = page_count;
    }

    double Cheer(int user_id) const {
        if (_user_to_page.count(user_id) == 0)
            return 0.0;
        if (_user_to_page.size() == 1) return 1.0;
        return static_cast<double>(
                       _page_before[_user_to_page.at(user_id)]) /
               (_user_to_page.size() - 1);
    }

private:
    int _MAX_PAGES = 1001;

    std::unordered_map<int, int> _user_to_page;
    std::vector<int> _page_before;
};




#endif //YANDEX_CPP_COURSE_READINGMANAGER_H
