#include "../include/Stack.hpp"
#include <iostream>

using namespace std;


int main(void)
{
    stack<int> stk1(10);
    stk1.push(10);
    stk1.push(40);
    stk1.pop();
    stk1.push(12);
    stk1.push(45);
    stk1.push(78);
    stk1.push(34);
    std::cout << stk1.flatten();
}