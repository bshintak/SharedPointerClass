#pragma once

#include <iostream>

template <typename T>
class Shared {
    public:
        Shared() {
            ptr = new T;
            count = new uint{1};
        };
        ~Shared() {
            (*count)--;
            if(*count == 0) {
                delete count;
                delete ptr;
            }
        };
        Shared(const Shared<T> & other) {
            if (this != &other) {
                ptr = other.ptr;
                count = other.count;
            }
            (*count)++;
        };
        Shared & operator=(const Shared<T> & other) {
            if (this == &other) {
                return *this;
            }
            (*count)--;
            if (*count == 0) {
                delete count;
                delete ptr;
            }
            count = other.count;
            ptr = other.ptr;
            (*count)++;
            return *this;
        };
        Shared(Shared<T> && other) {
            if (this != &other) {
                ptr = other.ptr;
                count = other.count;
            }
            (*count)++;
        };
        Shared & operator=(Shared<T> && other) {
            if (this == &other) {
                return *this;
            }
            (*count)--;
            if (*count == 0) {
                delete count;
                delete ptr;
            }
            count = std::move(other.count);
            ptr = std::move(other.ptr);
            (*count)++;
            return *this;
        };
        int getCount() {
            return *count;
        }

    private:
        T* ptr;
        uint* count;
};