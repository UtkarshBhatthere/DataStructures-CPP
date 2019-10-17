/**
 * Author : Utkarsh Bhatt
 * Date   : 10/10/2019  (10th October 2019)
 * Struct : Singular Queue
 * Using  : Struct Nodes
 * Type   : Generic (Templated)
 */
#include <sstream>
#include <iostream>

template <typename T>
class heap
{
    enum heap_type{
        max_heap,
        min_heap
    };

    protected:
        // Data Members
        int capacity;
        int size;
        T* root_node;
        heap_type type;
        
        // Methods
        int left_child(int index)
        {
            return 2*index+1;
        }

        int right_child(int index)
        {
            return 2*index+2;
        }

        int parent(int index)
        {
            return (index - 1)/2;
        }

        bool swap(int index1, int index2)       // Constant time. O(1)
        {
            if(index1 == index2)
                return true;

            if(index1 < this -> size && index2 < this -> size){
                T temp = this -> root_node[index1];
                this -> root_node[index1] = this -> root_node[index2];
                this -> root_node[index2] = temp;
                return true;
            }
            else
                return false;
        }
        // Checks if the element at the given index is not the largest and then floats it down if found smaller.
        bool heapify_max(int index)     //logrithmic time. O(log(n)) Makes the given node and its children a heap (following heap invariant.)
        {
            if(index > this -> size)
                return false;

            int left_child = this -> left_child(index);
            int right_child = this -> right_child(index);
            int largest = index;

            if(this -> root_node[index] < left_child && left_child < this -> size)
                largest = left_child;
            
            if(largest < right_child && right_child < this -> size)
                largest = right_child;

            this -> swap(index, largest);

            // Recursively float down.
            this -> heapify_max(index);
            return true;
        }
        
        bool heapify_min(int index)     //logrithmic time. O(log(n)). Makes the given node and its children a heap (following heap invariant.)
        {
            if(index > this -> size)
                return false;

            int left_child = this -> left_child(index);
            int right_child = this -> right_child(index);
            int smallest = index;

            if(this -> root_node[index] > left_child && left_child < this -> size)
                smallest = left_child;
            
            if(smallest > right_child && right_child < this -> size)
                smallest = right_child;

            this -> swap(index, smallest);

            this -> heapify_min(smallest);
            return true;
        }

        void make_heap(heap_type type)       //linear time. O(n)
        {
            if(type == max_heap)
                bool (*heapify) = this -> heapify_max;
            else
                bool (*heapify) = this -> heapify_min;

            for (int i = this -> size; i >= 0; i--){
                this -> heapify(i);
            }    
        }

        bool float_up(int index)
        {
            if(index == 0)
                return false;

            int parent = this->parent(index);

            if (this -> type == max_heap){
                // Check if the child is greater than the parent itself.
                if(this -> root_node[index] > this -> root_node[parent])
                    swap(parent, index);
                
            }else{
                // Check if the child is smaller than the parent itself.
                if(this -> root_node[index] < this -> root_node[parent])
                    swap(parent, index);

            }
            
            //Recursively floats up the swappeelement if required.
            this -> float_up(parent);
            return true;
        }

    public:
        heap(int required_capacity, heap_type type) // For empty heap initialisation.
        {
            this -> capacity = required_capacity;
            this -> size = 0;
            this -> type = type;
            this -> root_node = new T[this -> capacity];
        }

        heap(T* arr, int arr_size, heap_type type)  // Heap initialisation from array.
        {
            this -> size = arr_size;
            this -> capacity = 3*arr_size/2;
            this -> type = type;
            this -> root_node = new T[this -> capacity];

            // Copying the passed array.
            for(int i = 0; i < arr_size; i++){
                this -> root_node[i] == arr[i];
            }

            this -> make_heap(type);
        }

        ~heap(void)
        {
            delete[] this -> root_node;
        }

        bool isEmpty(void)
        {
            return (this -> size == 0);
        }

        T peek(void)
        {
            if(this -> size == 0)
                return (T)NULL;
            return this-> root_node;
        }

        bool insert(T object)
        {
            if(this -> size == this -> capacity)
                return false;
            
            int last_index = this -> size++;
            this -> root_node[last_index] = object; // Adding an object to the size(th) index and then increasing heap size.

            this -> float_up(last_index);
        }

        void remove(int index)
        {
            int last_index = this -> size;
            this -> swap(index, last_index);
            this -> size--;

            if(this -> type == max_heap)
                bool (*heapify) = heapify_max;
            else
                bool (*heapify) = heapify_min;
            
            this -> heapify(index); // Sifting down the swapped element.
        }

        void pop(void)
        {
            this -> remove(0);  // removing the index 0 element.
        }

        std::string flatten(void);
};