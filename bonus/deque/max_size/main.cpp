// deque::max_size
#include <iostream>
#include <deque>

int main ()
{
 unsigned int i = 1000;
 std::deque<int> mydeque;

 std::cout << "Enter number of elements: ";

 if (i<mydeque.max_size()) mydeque.resize(i);
 else std::cout << "That size exceeds the limit.\n";

 return 0;
}