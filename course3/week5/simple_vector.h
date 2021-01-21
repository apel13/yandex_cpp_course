//
// Created by apel on 21.01.2021.
//

#ifndef YANDEX_CPP_COURSE_SIMPLE_VECTOR_H
#define YANDEX_CPP_COURSE_SIMPLE_VECTOR_H

#include <cstdlib>
#include <utility>
#include <algorithm>

template <typename T>
class SimpleVector {
public:
    SimpleVector() = default;
    explicit SimpleVector(size_t size);
    SimpleVector(const SimpleVector& rhs);
    ~SimpleVector();

    void operator=(const SimpleVector& rhs) {
        if (rhs.size <= capacity) {
            std::copy(rhs.begin(), rhs.end(), begin());
            size = rhs.size;
        } else {
            SimpleVector<T> tmp(rhs);
            std::swap(tmp.data, data);
            std::swap(tmp.size, size);
            std::swap(tmp.capacity, capacity);
        }
    }

    T& operator[](size_t index);

    T* begin();
    T* end();

    const T* begin() const;
    const T* end() const;

    size_t Size() const;
    size_t Capacity() const;
    void PushBack(const T& value);

private:
    T* data = nullptr;
    size_t size = 0;
    size_t capacity = 0;
};


#endif //YANDEX_CPP_COURSE_SIMPLE_VECTOR_H
