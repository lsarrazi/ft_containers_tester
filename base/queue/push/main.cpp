// queue::push/pop
#include <iostream> // std::cin, std::cout
#include <queue> // std::queue
#include <sstream>
int main ()
{
 std::queue<int> myqueue;
 int myint;

 std::cout << "Please enter some integers (enter 0 to end):\n";
 std::istringstream iss("10 15 20 88 42 4757 785 277 2782 8728 45 245 245 0");
 do {
 iss >> myint;
 myqueue.push (myint);
 } while (myint);

 std::cout << "myqueue contains: ";
 while (!myqueue.empty())
 {
 std::cout << ' ' << myqueue.front();
 myqueue.pop();
 }
 std::cout << '\n';

 return 0;
}