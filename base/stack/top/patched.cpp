// stack::top
#include <iostream> // std::cout
#include "stack.hpp" // ft::stack

int main ()
{
 ft::stack<int> mystack;

 mystack.push(10);
 mystack.push(20);

 mystack.top() -= 5;

 std::cout << "mystack.top() is now " << mystack.top() << '\n';

 return 0;
}