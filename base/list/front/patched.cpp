// list::front
#include <iostream>
#include "list.hpp"

int main ()
{
 ft::list<int> mylist;

 mylist.push_back(77);
 mylist.push_back(22);

 // now front equals 77, and back 22

 mylist.front() -= mylist.back();

 std::cout << "mylist.front() is now " << mylist.front() << '\n';

 return 0;
}