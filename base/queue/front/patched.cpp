// queue::front
#include <iostream> // std::cout
#include "queue.hpp" // ft::queue

int main ()
{
 ft::queue<int> myqueue;

 myqueue.push(77);
 myqueue.push(16);

 myqueue.front() -= myqueue.back(); // 77-16=61

 std::cout << "myqueue.front() is now " << myqueue.front() << '\n';

 return 0;
}