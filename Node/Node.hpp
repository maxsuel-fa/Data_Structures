/*
 * @file Node.hpp
 * @author maxsuel-fa
 */
#ifndef NODE_H
#define NODE_H
#include <iostream>

template <typename T>
struct Node
{
    std::shared_ptr<Node> prev;
    std::shared_ptr<Node> next;
    T data;

    Node() = default;

    Node(const T& data_)
        : data(data_)
        , prev(nullptr)
        , next(nullptr) {}

    ~Node() {}
};
#endif //NODE_H
