// deque::push_back
#include <iostream>
#include <deque>
#include <sstream>
int main ()
{
 std::deque<int> mydeque;
 int myint;
	std::istringstream iss("10 15 20 88 42 4757 785 277 2782 8728 45 245 245 0");
 std::cout << "Please enter some integers (enter 0 to end):\n";

 do {
 iss >> myint;
 mydeque.push_back (myint);
 } while (myint);

 std::cout << "mydeque stores " << (int) mydeque.size() << " numbers.\n";

 return 0;
}