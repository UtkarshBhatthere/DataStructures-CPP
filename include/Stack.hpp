/**
 * Author : Utkarsh Bhatt
 * Date   : 05/10/2019  (5th October 2019)
 * Struct : Stack
 * Using  : Dynamic Array
 * Type   : Generic (Templated)
 */
#include <sstream>
#include <iostream>

template <typename T>
class stack
{
    private:
        T*  stack_root;
        T*  top_ptr;
        int size;
        int capacity;
    
    public:
        stack(int required_capacity)
        {
            this -> size       = 0;
            this -> capacity   = 0;
            this -> capacity   = required_capacity;
            this -> stack_root = new T[this->capacity];
            this -> top_ptr    = this -> stack_root;
        }

        ~stack(void)
        {
            delete[] this->stack_root;
        }

        bool push(T object)
        {
            if(this->size == this->capacity){
                throw "Stack Full!";
                return false;
            }
            
            *(this -> top_ptr++) = object;
            
            this -> size++;
            return true;
        }

        T pop(void)
        {
            if(this -> size == 0){
                throw "Stack already empty!";
                return NULL;
            }
            T ret = *this -> top_ptr--;
            this -> size--;
            return ret;
        }

        T top(void)
        {
            T ret = *this -> top_ptr;
            return ret;
        }

        bool isEmpty(void)
        {
            return (this -> size == 0);  
        }

        bool isFull(void)
        {
            return (this -> size == this -> capacity);
        }

        std::string flatten(void)
        {
            std::cout << "Entered\n";
            T* object_ptr = this->top_ptr;
            std::stringstream stack_str;
            stack_str << "Stack Size : "<< this -> size<< std::endl;
            stack_str << "Stack Content : "<< std::endl;
            std::cout << "Wrote something\n";
            try
            {
                stack_str << *object_ptr-- << " indexed at -> " << this->size << std::endl;
                std::cout << "Trying\n";
            }
            catch(const std::exception& e)
            {
                std::cout << "Catching\n";
                std::cerr << e.what() << '\n';
                return e.what();
            }
            int i = 1;
            for (T* ptr = this->top_ptr - 1; ptr != this->stack_root; ptr--){
                std::cout << "Flattening " << i++ << "\n";
                stack_str << *object_ptr-- << " indexed at -> " << i << std::endl;
            }
            std::cout << "returning\n";
            return stack_str.str();
        }

};