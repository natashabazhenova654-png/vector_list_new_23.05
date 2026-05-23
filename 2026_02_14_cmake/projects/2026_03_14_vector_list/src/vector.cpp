#include "vector.hpp"

#include <iostream>

using biv::Vector;

template <typename T>
Vector<T>::Vector() {
    arr = new T[capacity];
}

template <typename T>
Vector<T>::~Vector() {
    delete[] arr;
}

template <typename T>
std::size_t Vector<T>::get_size() const noexcept {
    return size;
}

template <typename T>
bool Vector<T>::has_item(const T& value) const noexcept {
    for (std::size_t index = 0; index < size; ++index) {

        if (arr[index] == value) {
            return true;
        }
    }

    return false;
}

template <typename T>
void Vector<T>::increase_capacity() {
    capacity *= 2;

    T* new_arr = new T[capacity];

    for (std::size_t index = 0; index < size; ++index) {
        new_arr[index] = arr[index];
    }

    delete[] arr;

    arr = new_arr;
}

template <typename T>
bool Vector<T>::insert(
    const std::size_t position,
    const T& value
) {
    if (position > size) {
        return false;
    }

    if (size == capacity) {
        increase_capacity();
    }

    for (std::size_t index = size; index > position; --index) {
        arr[index] = arr[index - 1];
    }

    arr[position] = value;

    ++size;

    return true;
}

template <typename T>
void Vector<T>::print() const noexcept {
    for (std::size_t index = 0; index < size; ++index) {
        std::cout << arr[index] << ' ';
    }

    std::cout << '\n';
}

template <typename T>
void Vector<T>::push_back(const T& value) {
    insert(size, value);
}

template <typename T>
bool Vector<T>::remove_first(const T& value) {
    for (std::size_t index = 0; index < size; ++index) {

        if (arr[index] == value) {

            for (
                std::size_t shift_index = index;
                shift_index + 1 < size;
                ++shift_index
            ) {
                arr[shift_index] = arr[shift_index + 1];
            }

            --size;

            return true;
        }
    }

    return false;
}

