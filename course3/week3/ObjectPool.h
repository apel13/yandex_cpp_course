//
// Created by apel on 19.01.2021.
//

#ifndef YANDEX_CPP_COURSE_OBJECTPOOL_H
#define YANDEX_CPP_COURSE_OBJECTPOOL_H


#include <set>
#include <queue>


template<class T>
class ObjectPool {
public:
    T *Allocate() {
        if (!_deallocated.empty()) {
            T* ret = _deallocated.front();
            _deallocated.pop();
            return *_allocated.insert(ret).first;
        }
        return *_allocated.insert(new T).first;
    }

    T *TryAllocate() {
        if (!_deallocated.empty()) {
            T* ret = _deallocated.front();
            _deallocated.pop();
            return *_allocated.insert(ret).first;
        }
        return nullptr;
    }

    void Deallocate(T *object) {
        auto it = _allocated.find(object);
        if (it == _allocated.end())
            throw std::invalid_argument("cant find object");
        _deallocated.push(*it);
        _allocated.erase(it);
    }

    ~ObjectPool() {
        for (auto &mem : _allocated)
            delete mem;
        while (!_deallocated.empty()) {
            delete _deallocated.front();
            _deallocated.pop();
        }
    }

private:
    set<T *> _allocated;
    queue<T *> _deallocated;
};


#endif //YANDEX_CPP_COURSE_OBJECTPOOL_H
