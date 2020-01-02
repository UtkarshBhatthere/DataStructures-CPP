/**
 * Copyright 2019 Utkarsh Bhatt
 * Author : Utkarsh Bhatt
 * Date   : 10/10/2019  (10th October 2019)
 * Struct : Singular Queue
 * Using  : Struct Nodes
 * Type   : Generic (Templated)
 */

#ifndef INCLUDE_HEAP_HPP_
#define INCLUDE_HEAP_HPP_

#include <sstream>
#include <iostream>
#include <string>

typedef enum {
    max_heap,
    min_heap
} heap_type;

template <typename T>
class heap {
 protected:
    // Data Members
    int capacity;
    int size;
    T* root_node;
    heap_type type;
    // Function Pointers.
    bool (heap<T>::*heapify)(int);

    // Methods
    int left_child(int index) {  return 2*index+1; }

    int right_child(int index) { return 2*index+2; }

    int parent(int index) {  return (index - 1)/2; }

    bool local_swap(int index1, int index2) {  // Constant time. O(1)
       if (index1 == index2)
            return false;

        if (index1 < this -> size && index2 < this -> size) {
            T temp = this -> root_node[index1];
            this -> root_node[index1] = this -> root_node[index2];
            this -> root_node[index2] = temp;
            return true;
        } else {
            return false;
        }
    }

    // Checks if the element at the given index is not the largest.
    // and then floats it down if found smaller.
    // logrithmic time. O(log(n))
    bool heapify_max(int index) {
        if (index > this -> size || this -> size <= 1)
            return false;

        int left_child = this -> left_child(index);
        int right_child = this -> right_child(index);
        int largest = index;
        T* heap_ptr = this -> root_node;

        if (this -> root_node[index] < heap_ptr[left_child] && \
            left_child < this -> size)
            largest = left_child;

        if (heap_ptr[largest] < heap_ptr[right_child] && \
            right_child < this -> size)
            largest = right_child;

        if (this -> local_swap(index, largest) == true)
            // Recursively float down.
            this -> heapify_max(largest);

        return true;
    }

    // logrithmic time. O(log(n)).
    // Makes the given node and its children a heap (following heap invariant.)
    bool heapify_min(int index) {
        if (index > this -> size)
            return false;

        int left_child = this -> left_child(index);
        int right_child = this -> right_child(index);
        int smallest = index;

        if (this -> root_node[index] > left_child && left_child < this -> size)
            smallest = left_child;

        if (smallest > right_child && right_child < this -> size)
            smallest = right_child;

        this -> local_swap(index, smallest);

        this -> heapify_min(smallest);
        return true;
    }

    void make_heap() {  // linear time. O(n)
       for (int i = this -> size; i >= 0; i--) {
            this -> heapify(i);
        }
    }

    bool float_up(int index) {
        if (index == 0)
            return false;

        int parent = this->parent(index);

        if (this -> type == max_heap) {
            // Check if the child is greater than the parent itself.
            if (this -> root_node[index] > this -> root_node[parent])
                local_swap(parent, index);
        } else {
            // Check if the child is smaller than the parent itself.
            if (this -> root_node[index] < this -> root_node[parent])
                local_swap(parent, index);
        }
        // Recursively floats up the swap element if required.
        this -> float_up(parent);
        return true;
    }

 public:
    // For empty heap initialisation.
    heap(int required_capacity, heap_type type) {
        this -> capacity = required_capacity;
        this -> size = 0;
        this -> type = type;
        this -> root_node = new T[this -> capacity];
        if (type == max_heap)
            this -> heapify = &heap<T>::heapify_max;
        else
            this -> heapify = &heap<T>::heapify_min;
    }

    // Heap initialisation from array.
    heap(T* arr, int arr_size, heap_type type) {
        this -> size = arr_size;
        this -> capacity = 3*arr_size/2;
        this -> type = type;
        this -> root_node = new T[this -> capacity];
        if (type == max_heap)
            this -> heapify = heap<T>::heapify_max;
        else
            this -> heapify = heap<T>::heapify_min;

        // Copying the passed array.
        for (int i = 0; i < arr_size; i++) {
            this -> root_node[i] == arr[i];
        }

        this -> make_heap();
    }

    ~heap(void) {
        delete[] this -> root_node;
    }

    bool isEmpty(void) {
        return (this -> size == 0);
    }

    T peek(void) {
        if (this -> size == 0)
            return (T)NULL;
        return *this-> root_node;
    }

    bool insert(T object) {
        if (this -> size == this -> capacity)
            return false;

        int last_index = this -> size++;
        // Adding an object to the size(th) index and then increasing heap size.
        this -> root_node[last_index] = object;
        this -> float_up(last_index);
    }

    void remove(int index) {
        int last_index = this -> size - 1;
        this -> local_swap(index, last_index);
        this -> size--;

        (this ->*heapify)(index);  // Sifting down the swapped element.
    }

    T pop(void) {
        T ret = this -> peek();
        this -> remove(0);  // removing the index 0 element.
        return ret;
    }

    int heap_size(void) {
        return this -> size;
    }

    std::string flatten(void) {   T* object = this -> root_node;
        std::stringstream heap_str;

        heap_str << "Heap Size : " << this ->size << std::endl;
        heap_str << "Heap Content : " << std::endl;
        if (this -> size == 0) {
            heap_str << "NULL" << std::endl;
            return heap_str.str();
        }

        heap_str << "|";

        for (int i = 0; i < this -> size; i++) {
            heap_str << " " << object[i] << " |";
        }

        return heap_str.str();
    }
};
#endif  // INCLUDE_HEAP_HPP_
