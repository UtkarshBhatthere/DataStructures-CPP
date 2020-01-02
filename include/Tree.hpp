/**
 * Copyright 2019 Utkarsh Bhatt
 * Author : Utkarsh Bhatt
 * Date   : 26/10/2019  (9th October 2019)
 * Struct : Binary Search Tree (Unique Keys)
 * Using  : Dynamic Allocated Nodes
 * Type   : Generic (Templated)
 */

#ifndef INCLUDE_TREE_HPP_
#define INCLUDE_TREE_HPP_

#include <sstream>
#include <string>

template <typename T>
class tree_node {
 protected:
    // Data Members
    T data;
    tree_node* left_child;
    tree_node* right_child;

 public:
    explicit tree_node(T key) {
        this -> data = key;
        this -> left_child = nullptr;
        this -> right_child = nullptr;
    }

    tree_node(const tree_node &node) {
        this -> data  = node.data;
        this -> left_child = node.left_child;
        this -> right_child = node.right_child;
    }

    bool check(T key) {
        return (this -> data == key);
    }

    T get_key(void) {
        return this -> data;
    }

    tree_node<T>* get_left_child(void) {
        return this->left_child;
    }

    tree_node<T>* get_right_child(void) {
        return this->right_child;
    }
};

template <typename T>
class binary_search_tree {
 protected:
    int size;
    tree_node<T>* root_node;

 public:
    binary_search_tree(void) {
        this -> root_node = nullptr;
        this -> size = 0;
    }

    explicit binary_search_tree(tree_node<T> root) {
        this -> root_node = new tree_node<T>(root);
        this -> size = 1;
    }

    ~binary_search_tree(void);

    // Since level-wise search is done, the asymptotic complexity is O(h).
    // here h is height of the tree.
    bool search(const T &key) {
        if (this -> size == 0)
            return false;

        tree_node<T>* verif = this -> root_node;

        while (verif == nullptr) {
            if (verif -> data == key)
                return true;
        }

        return false;
    }

    // Return the node with the desired key,
    // or NULL value if the node is not found.
    tree_node<T> get_node(const T &key) {
        if (this -> size == 0)
            return (tree_node<T>)NULL;

        tree_node<T>* verif = this -> root_node;

        while (verif == nullptr) {
            if (verif -> data == key)
                return verif;
        }

        return (tree_node<T>)NULL;
    }

    bool insert(const tree_node<T> &node) {
        T node_key = node.data;

        if (this -> search(node_key) == true)
            return false;

        // TODO(@UtkarshBhatthere): Check if there's a better way to do it.
        tree_node<T>* in_node = new tree_node<T>(node);
        tree_node<T>* temp_ = this -> root_node;

        if (this -> size == 0) {
            temp_ = in_node;
        } else {
            while (temp_ != nullptr) {
                if (node_key < temp_ -> data )
                    temp_ = temp_ -> get_left_child();
                else
                    temp_ = temp_ -> get_right_child();
            }
            temp_ = in_node;
        }
        return true;
    }

    std::string in_order_traversal(tree_node<T>* ptr) {
        if (ptr == nullptr)
            return NULL;

        sstream tree_str;
        tree_str << this -> in_order_traversal(ptr -> get_left_child()) << " ";
        tree_str << ptr -> data << " ";
        tree_str << this -> in_order_traversal(ptr -> get_right_child()) << " ";

        return tree_str.str();
    }

    std::string pre_order_traversal(tree_node<T>* ptr) {
        if (ptr == nullptr)
            return NULL;

        sstream tree_str;
        tree_str<< ptr -> data<< " ";
        tree_str<< this -> pre_order_traversal(ptr -> get_left_child())<< " ";
        tree_str<< this -> pre_order_traversal(ptr -> get_right_child())<< " ";

        return tree_str.str();
    }

    std::string post_order_traversal(void) {
        if (ptr == nullptr)
            return NULL;

        sstream tree_str;
        tree_str<< this -> post_order_traversal(ptr -> get_left_child())<< " ";
        tree_str<< this -> post_order_traversal(ptr -> get_right_child())<< " ";
        tree_str<< ptr -> data<< " ";

        return tree_str.str();
    }

    // Overloaded methods for call with root node.
    std::string in_order_traversal(void) {
        return this -> in_order_traversal(this -> root_node);
    }

    std::string pre_order_traversal(void) {
        return this -> pre_order_traversal(this -> root_node);
    }

    std::string post_order_traversal(void) {
        return this -> post_order_traversal(this -> root_node);
    }

    // TODO(@UtkarshBhatthere): Deleting nodes.
};
#endif  // INCLUDE_TREE_HPP_
