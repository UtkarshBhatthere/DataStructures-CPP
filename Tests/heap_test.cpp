#include "../include/Heap.hpp"
#include <iostream>

using namespace std;


int main(void)
{
    int i = 1;
    auto a = 10;
    heap<int> h(10, max_heap);
    h.insert(10);
    h.insert(40);
    cout << i++ << endl << h.flatten() << endl;
    cout << h.pop() << endl;
    cout << i++ << endl << h.flatten() << endl;
    cout << h.pop() << endl;
    cout << i++ << endl << h.flatten() << endl;
    cout << h.peek() << endl;
    cout << i++ << endl << h.flatten() << endl;
    h.insert(12);
    h.insert(45);
    h.insert(78);
    h.insert(34);
    cout << i++ << endl << h.flatten() << endl;

}