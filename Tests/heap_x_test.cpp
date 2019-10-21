#include "../include/Heap.hpp"
#include <iostream>

using namespace std;


int main(void)
{
    int i = 1;
    auto a = 20;
    heap<int> h(10, max_heap);
    for(int i = 1; i < 170; i+=10){
        h.insert(i);
    }

    cout << endl << h.flatten() << endl;
    int tar = h.heap_size();
    for (int i = 0; i < tar; i++){
        h.pop();
        cout << endl << h.flatten() << endl;
    }

}