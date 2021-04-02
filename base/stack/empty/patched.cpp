// stack::empty
#include <iostream> // std::cout
#include "stack.hpp" // ft::stack

int main ()
{
 ft::stack<int> mystack;
 int sum (0);

 for (int i=1;i<=10;i++) mystack.push(i);

 while (!mystack.empty())
 {
 sum += mystack.top();
 mystack.pop();
 }

 std::cout << "total: " << sum << '\n';

 return 0;
}