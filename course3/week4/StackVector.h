//
// Created by apel on 19.01.2021.
//

#ifndef YANDEX_CPP_COURSE_STACKVECTOR_H
#define YANDEX_CPP_COURSE_STACKVECTOR_H

#include <array>

template<typename T, size_t N>
class StackVector {
public:
    explicit StackVector(size_t a_size = 0) {
        if (a_size > _capacity)
            throw std::invalid_argument("max capacity");
        _size = a_size;
    }

    T &operator[](size_t index) {
        return _data.at(index);
    }

    const T &operator[](size_t index) const {
        return _data.at(index);
    }

    auto begin() {
        return _data.begin();
    }

    auto end() {
        return _data.begin() + _size;
    }

    auto begin() const {
        return _data.cbegin();
    }

    auto end() const {
        return _data.cbegin() + _size;
    }

    size_t Size() const {
        return _size;
    }

    size_t Capacity() const {
        return _capacity;
    }

    void PushBack(const T &value) {
        if (_size == _capacity)
            throw std::overflow_error("max capacity");
        _data.at(_size++) = value;
    }

    T PopBack() {
        if (_size == 0)
            throw std::underflow_error("PopBack from empty vector");
        T ret = _data[--_size];
        return ret;
    }

private:
    size_t _size;
    std::array<T, N> _data;
    const size_t _capacity = N;
};

#endif //YANDEX_CPP_COURSE_STACKVECTOR_H
