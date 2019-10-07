/**
 * Author : Utkarsh Bhatt
 * Date   : 06/10/2019  (6th October 2019)
 * Struct : Singular Queue
 * Using  : Dynamic Array
 * Type   : Generic (Templated)
 */
#include <sstream>
#include <iostream>

template <typename T>
class queue
{
    protected:
        T* queue_root;
        T* front;
        T* back;
        int size;
        int capacity;
    
    public:
        queue(int required_capacity)
        {
            this -> capacity = required_capacity;
            this -> queue_root = new T[this->capacity];
            this -> size = 0;
            this -> front   = this -> queue_root;
            this -> back    = this -> queue_root;
        }

        ~queue(void)
        {
            delete[] this -> queue_root;
        }

        void reset(void)
        {
            this -> front = this -> queue_root;
            this -> back  = this -> queue_root;
            this -> size  = 0;
        }

        bool enqueue(T object)
        {
            if(this -> size == this -> capacity){
                return false;
            }

            *this -> back++ = object;
            this -> size++;

            return true;
        }

        T dequeue(void)
        {
            if(this -> size == 0){
                return (T)NULL;
            }

            T ret = *this -> front++;

            this -> size--;

            if(this->size == 0)
                this -> reset();

            return ret;
        }

        T peek(void)
        {
            if(this -> size == 0){
                return (T)NULL;
            }

            T ret = *this -> front;
            return ret;
        }

        int queue_size(void)
        {
            return this -> size;
        }

        std::string flatten(void)   // TODO: When dequeing to size 1 we are printng one extra char.
        {
            T* object_ptr = this -> front;
            std::stringstream queue_str;
            int size = this ->size;
            queue_str << "Queue Size : " << size << std::endl;
            queue_str << "Queue Content : " << std::endl;
            if(this -> size == 0){
                queue_str << "NULL" << std::endl;
                return queue_str.str();
            }

            try
            {
                queue_str << "--> " << *object_ptr++ << " <-- Front" << std::endl;
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
                return e.what();
            }

            while(object_ptr < this->back - 1){    // Since back pointer stays one ahead.
                queue_str << "--> " << *object_ptr++ << std::endl;
            }

            queue_str << "--> " << *object_ptr << " <-- Back" << std::endl;
            
            return queue_str.str();
        }
};