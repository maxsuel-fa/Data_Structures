/* @file List.hpp
 * @brief Implementation of a circular, doubly linked list with a sentinel
 * @author maxsuel-fa
 */
#ifndef LIST_H
#define LIST_H
#include <iostream>
#include <memory>

template<typename T>
class List
{
public:
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

    List() : sentinel {std::make_shared<Node>()}
    {
        sentinel->prev = sentinel;
        sentinel->next = sentinel;
    }

    void push_front(const T& data)
    {
        std::shared_ptr<Node> new_node{std::make_shared<Node>(data)};
        new_node->prev = sentinel;
        new_node->next = sentinel->next;
        sentinel->next->prev = new_node;
        sentinel->next = new_node;
    }

    void push_back(const T& data)
    {
        std::shared_ptr<Node> new_node{std::make_shared<Node>(data)};
        new_node->prev = sentinel->prev;
        new_node->next = sentinel;
        sentinel->prev->next = new_node;
        sentinel->prev = new_node;
    }

    void pop_front()
    {
        sentinel->next = sentinel->next->next;
        sentinel->next->prev->prev = nullptr;
        sentinel->next->prev->next = nullptr;
        sentinel->next->prev = sentinel;
    }

    void pop_back()
    {
        sentinel->prev = sentinel->prev->prev;
        sentinel->prev->next->prev = nullptr;
        sentinel->prev->next->next = nullptr;
        sentinel->prev->next = sentinel;
    }

    std::shared_ptr<Node> search(const T& target)
    {
        return search(target, sentinel->next);
    }

    void print()
    {
        print(sentinel->next);
        std::cout << std::endl;
    }

    const std::shared_ptr<Node>& get_sentinel()
    {
        return sentinel;
    }

private:
    std::shared_ptr<Node> sentinel;

    std::shared_ptr<Node> search(const T& target,
                                    std::shared_ptr<Node> curr_node)
    {
        if (curr_node != sentinel && curr_node->data != target)
            curr_node = search(target, curr_node->next);
        return curr_node;
    }

    void print(const std::shared_ptr<Node>& curr_node)
    {
        if (curr_node != sentinel)
        {
            std::cout << curr_node->data << " ";
            print(curr_node->next);
        }
    }
};
#endif
