//
// Created by apel on 18.01.2021.
//

#ifndef YANDEX_CPP_COURSE_PAGINATOR_H
#define YANDEX_CPP_COURSE_PAGINATOR_H


template<typename Iterator>
class IteratorRange {
public:
    IteratorRange(Iterator first, Iterator last)
            : _first(first), _last(last) {}

    Iterator begin() const {
        return _first;
    }

    Iterator end() const {
        return _last;
    }

    size_t size() const {
        return distance(_first, _last);
    }

private:
    Iterator _first, _last;
};


template<typename Iterator>
class Paginator {
public:
    Paginator(Iterator begin, Iterator end, size_t page_size) {
        Iterator last = begin;
        size_t cur = 0;
        while (begin != end) {
            begin = std::next(begin);
            cur++;
            if (cur == page_size) {
                cur = 0;
                _pages.emplace_back(last, begin);
                last = begin;
            }
        }
        if (cur)
            _pages.emplace_back(last, end);
    }

    auto begin() const {
        return _pages.begin();
    }

    auto end() const {
        return _pages.end();
    }

    size_t size() const {
        return _pages.size();
//        size_t dist = std::distance(_begin, _end);
//        return dist / _size + ((dist % _size == 0) ? 0 : 1);
    }

private:
    vector<IteratorRange<Iterator>> _pages;
};

template<typename C>
auto Paginate(C &c, size_t page_size) {
    return Paginator(c.begin(), c.end(), page_size);
}



#endif //YANDEX_CPP_COURSE_PAGINATOR_H
