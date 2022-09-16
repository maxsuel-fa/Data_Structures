/*
 * @file binary_search_tree.hpp
 * @brief Implementation of a simple binary search tree
 * @author maxsuel-fa
 */
#ifndef BINARY_SEARCH_TREE_HPP
#define BINARY_SEARCH_TREE_HPP
#include<iostream>
#include<memory>

template<typename T>

class BinarySearchTree
{
public:
    struct Node
    {
        std::shared_ptr<Node> left;
        std::shared_ptr<Node> right;
        T data;

        Node() = default;

        Node(const T& data_)
            : left{nullptr}
            , right{nullptr}
            , data{data_} {}

        ~Node() {}
    };

    BinarySearchTree() : _root{nullptr} {}

    void insert(const T& data)
    {
        insert(data, _root);
    }

    void inorder_print()
    {
        inorder_print(_root);
        std::cout << std::endl;
    }

private:
    std::shared_ptr<Node> _root;

    void insert(const T& data, std::shared_ptr<Node>& curr_node)
    {
        if (!curr_node)
        {
            curr_node = std::make_shared<Node>(data);
            return;
        }

        if (curr_node->data > data)
            insert(data, curr_node->left);
        else
            insert(data, curr_node->right);
    }

    void inorder_print(const std::shared_ptr<Node>& curr_node)
    {
        if (curr_node)
        {
            inorder_print(curr_node->left);
            std::cout << curr_node->data << " ";
            inorder_print(curr_node->right);
        }
    }

};
#endif
