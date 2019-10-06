#include "../include/Queue.hpp"
#include <iostream>

using namespace std;


int main(void)
{
    queue<int> q(10);
    q.enqueue(10);
    q.enqueue(40);
    cout <<  "1-" << q.flatten();
    q.dequeue();
    // cout <<  "2-" << q.flatten();
    q.dequeue();
    cout <<  "3-" << q.flatten();
    q.peek();
    cout <<  "4-" << q.flatten();
    q.enqueue(12);
    cout <<  "5-" << q.flatten();
    q.enqueue(45);
    cout <<  "6-" << q.flatten();
    q.enqueue(78);
    cout <<  "7-" << q.flatten();
    q.enqueue(34);
    cout <<  "8-" << q.flatten();
}