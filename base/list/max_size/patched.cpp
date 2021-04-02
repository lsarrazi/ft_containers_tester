// list::max_size
#include <iostream>
#include "list.hpp"

int main ()
{
 ft::list<int>::size_type i = 1000;
 ft::list<int> mylist;

 std::cout << "Enter number of elements: ";

 if (i<mylist.max_size()) mylist.resize(i);
 else std::cout << "That size exceeds the limit.\n";

 return 0;
}