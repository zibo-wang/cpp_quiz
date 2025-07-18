#pragma once

#include <vector>
#include <stdexcept>

namespace cpp_quiz {

/**
 * A simple stack implementation using std::vector as the underlying container
 */
template<typename T>
class SimpleStack {
public:
    SimpleStack() = default;
    ~SimpleStack() = default;

    // Stack operations
    void push(const T& item);
    void push(T&& item);
    T pop();
    const T& top() const;
    T& top();
    
    // Stack state
    bool empty() const;
    size_t size() const;
    void clear();
    
    // Capacity
    size_t capacity() const;
    void reserve(size_t new_capacity);
    void shrink_to_fit();

private:
    std::vector<T> data_;
};

// Template implementation
template<typename T>
void SimpleStack<T>::push(const T& item) {
    data_.push_back(item);
}

template<typename T>
void SimpleStack<T>::push(T&& item) {
    data_.push_back(std::move(item));
}

template<typename T>
T SimpleStack<T>::pop() {
    if (empty()) {
        throw std::runtime_error("Cannot pop from empty stack");
    }
    T item = std::move(data_.back());
    data_.pop_back();
    return item;
}

template<typename T>
const T& SimpleStack<T>::top() const {
    if (empty()) {
        throw std::runtime_error("Cannot access top of empty stack");
    }
    return data_.back();
}

template<typename T>
T& SimpleStack<T>::top() {
    if (empty()) {
        throw std::runtime_error("Cannot access top of empty stack");
    }
    return data_.back();
}

template<typename T>
bool SimpleStack<T>::empty() const {
    return data_.empty();
}

template<typename T>
size_t SimpleStack<T>::size() const {
    return data_.size();
}

template<typename T>
void SimpleStack<T>::clear() {
    data_.clear();
}

template<typename T>
size_t SimpleStack<T>::capacity() const {
    return data_.capacity();
}

template<typename T>
void SimpleStack<T>::reserve(size_t new_capacity) {
    data_.reserve(new_capacity);
}

template<typename T>
void SimpleStack<T>::shrink_to_fit() {
    data_.shrink_to_fit();
}

} // namespace cpp_quiz
