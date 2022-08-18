/*
 * @file Queue.hpp
 * @brief Implementation of the Queue data structure using a circular array representation.
 * @author maxsuel-fa
 */
#ifdef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <stdexcept>

template<typename T>
class Queue
{
private:
    int _head;
    int _tail;
    std::size_t _capacity;
    T *_data;

public:
    Queue(const std::size_t &capacity)
        : _head(0)
        , _tail(0)
        , _capacity(capacity)
        , _data(new T[_capacity]) {}

    ~Queue() { delete _data; }

    void enqueue(const T &elem) 
    {
        if (is_full())
            throw std::runtime_error("Overflow: the queue is full");
        _data[_tail] = elem;
        _circular_increment(_tail);
    }

    T dequeue()
    {
        if(is_empty())
            throw std::runtime_error("Underflow: the queue is empty");
        T elem = _data[_head];
        _circular_increment(_head);
        return elem;
    }
    
    bool is_full()
    {
        int tail = _tail;
        _circular_increment(tail);
        return _head == tail;
    }

    bool is_empty() { return _head == _tail; }

    std::size_t capacity() { return _capacity; }

private:
    void _circular_increment(int &entity)
    {
        entity++;
        entity = entity % (_capacity + 1);
    }
}; // class Queue
#endif // QUEUE_H
