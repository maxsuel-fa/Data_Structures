/*
 * Impementation of the Stack data structure using an array representation.
 * @Authon maxsuel-fa
 */
#ifndef STACK_H
#define STACK_H
#include <iostream>
#include <stdexcept>

#define EMPTY_INDEX -1

template <typename T>
class Stack
{
private:
    long long _top;
    std::size_t _capacity;
    T *_data;

public:
    Stack(std::size_t capacity)
        : _top (EMPTY_INDEX)
        , _capacity (capacity)
        , _data (new T[_capacity]) {}

    ~Stack() { delete _data; }

    void push(const T &elem)
    {
        if (is_full())
            throw std::runtime_error("Overflow: the stack is full");
        _top++;
        _data[_top] = elem;
    }

    T pop()
    {
        if (is_empty())
            throw std::runtime_error("Underflow: the stack is empty");
        _top--;
        return _data[_top + 1];
    }

    bool is_full(){ return _top == _capacity - 1; }

    bool is_empty() { return _top == EMPTY_INDEX; }

    std::size_t capacity() { return _capacity; }

    std::size_t size() { return _top + 1; }

    void print() 
    {
        for(int i = 0; i < size(); ++i) 
            std::cout << _data[i] << " ";
        std::cout << std::endl;
    }
}; // class Stack
#endif //STACK_H
