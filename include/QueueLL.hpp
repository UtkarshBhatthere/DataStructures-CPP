/**
 * Author : Utkarsh Bhatt
 * Date   : 09/10/2019  (9th October 2019)
 * Struct : Singular Queue
 * Using  : Internal Linked List
 * Type   : Generic (Templated)
 */
#include <sstream>
#include <iostream>

template <typename T>
class queueLL
{
    struct QueueLL
    {
        T   data;
        QueueLL*  next;
    };
    

    protected:
        QueueLL* queue_root;
        QueueLL* front;
        QueueLL* back;
        int size;
        int capacity;

    public:
        queueLL(int required_capacity)
        {
            this -> capacity = required_capacity;
            this -> size = 0;
            this -> queue_root = NULL;
            this -> front = NULL;
            this -> back  = NULL;
        }

        ~queueLL(void)
        {
            QueueLL* del_ptr = NULL;
            for(int i = 0; i < this -> size; i++){
                del_ptr = this -> front;
                this -> front = this -> front -> next;
                delete del_ptr;
            }
        }

        bool enqueue(T data)    // Emplaces the data.
        {
            if (this -> size == this -> capacity)
                return false;
            
            if(this -> size != 0){
                this -> back -> next = new QueueLL{data, NULL};
                this -> back = this -> back -> next;
            }else{
                this -> queue_root = new QueueLL{data, NULL};
                this -> front = this -> queue_root;
                this -> back  = this -> queue_root;
            }
            
            this -> size ++;
            return true;
            
        }

        T dequeue(void)
        {
            if(this -> size == 0){
                return (T)NULL;
            }

            this -> size--;
            QueueLL out = *this -> front;
            delete this -> front;
            this -> front = out.next;
            // TODO: The size counter is not functioning properlly.

            return out.data;    
        }

        T peek(void)
        {
            // TODO : Fixing the size counter will fix the peek error.
            if(this -> size == 0)
                return (T)NULL;

            return this -> front -> data;
        }

        int queue_size(void)
        {
            return this -> size;
        }

        std::string flatten()
        {
            QueueLL* object_ptr = this -> front;
            std::stringstream queue_str;

            queue_str << "Queue Size : " << this -> size << std::endl;
            queue_str << "Queue Content : " << std::endl;

            if(this -> size == 0){
                queue_str << "NULL" << std::endl;
                return queue_str.str();
            }

            try
            {
                queue_str << "--> " << object_ptr -> data << " <-- Front" << std::endl;
                object_ptr = object_ptr -> next;
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
                return e.what();
            }

            for(int i = 2; i < this -> size; i++){    // Since this is the secondth element to be printed.
                queue_str << "--> " << object_ptr -> data << std::endl;
                object_ptr = object_ptr -> next;
            }

            if(this -> size > 1)
                queue_str << "--> " << object_ptr -> data << " <-- Back" << std::endl;
            
            return queue_str.str();
        }
};