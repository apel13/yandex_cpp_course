//
// Created by apel on 19.01.2021.
//

#ifndef YANDEX_CPP_COURSE_SIMPLEVECTOR_H
#define YANDEX_CPP_COURSE_SIMPLEVECTOR_H

#include <cstdint>


template<typename T>
class SimpleVector {
public:
    SimpleVector() = default;

    explicit SimpleVector(std::size_t size) {
        _data = new T[size];
        _size = _capacity = size;
    }

    ~SimpleVector() {
        delete[] _data;
    }

    T &operator[](std::size_t index) {
        return *(_data + index);
    }

    T *begin() {
        return _data;
    }

    T *end() {
        return (_data + _size);
    }

    std::size_t Size() const {
        return _size;
    }

    std::size_t Capacity() const {
        return _capacity;
    }

    void PushBack(const T &value) {
        if (_size == _capacity) {
            _capacity = _capacity ? 2 * _capacity : 1;
            T* new_data = new T[_capacity];
            copy(_data, _data + size, new_data);
            delete[] _data;
            _data = new_data;
        }
        _data[_size++] = value;
    }

private:
    T *_data = nullptr;
    std::size_t _size = 0u;
    std::size_t _capacity = 0u;
};


#endif //YANDEX_CPP_COURSE_SIMPLEVECTOR_H
