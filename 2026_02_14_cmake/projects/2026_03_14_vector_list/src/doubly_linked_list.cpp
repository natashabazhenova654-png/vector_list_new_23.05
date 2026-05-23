#include "doubly_linked_list.hpp"

#include <iostream>

using biv::DoublyLinkedList;

template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
    Node* current_node = begin;

    while (current_node != nullptr) {
        Node* next_node = current_node->next;
        delete current_node;
        current_node = next_node;
    }
}

template <typename T>
std::size_t DoublyLinkedList<T>::get_size() const noexcept {
    return size;
}

template <typename T>
bool DoublyLinkedList<T>::has_item(const T& value) const noexcept {
    Node* current_node = begin;

    while (current_node != nullptr) {
        if (current_node->value == value) {
            return true;
        }

        current_node = current_node->next;
    }

    return false;
}

template <typename T>
void DoublyLinkedList<T>::print() const noexcept {
    Node* current_node = begin;

    while (current_node != nullptr) {
        std::cout << current_node->value << ' ';
        current_node = current_node->next;
    }

    std::cout << '\n';
}

template <typename T>
void DoublyLinkedList<T>::push_back(const T& value) {
    Node* new_node = new Node(value);

    if (begin == nullptr) {
        begin = new_node;
        end = new_node;
    } else {
        new_node->prev = end;
        end->next = new_node;
        end = new_node;
    }

    ++size;
}

template <typename T>
bool DoublyLinkedList<T>::remove_first(const T& value) noexcept {
    Node* current_node = begin;

    while (current_node != nullptr) {
        if (current_node->value == value) {
            if (current_node->prev != nullptr) {
                current_node->prev->next = current_node->next;
            } else {
                begin = current_node->next;
            }

            if (current_node->next != nullptr) {
                current_node->next->prev = current_node->prev;
            } else {
                end = current_node->prev;
            }

            delete current_node;
            --size;

            return true;
        }

        current_node = current_node->next;
    }

    return false;
}
