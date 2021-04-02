// list::max_size
#include <iostream>
#include <list>

int main ()
{
 std::list<int>::size_type i = 1000;
 std::list<int> mylist;

 std::cout << "Enter number of elements: ";

 if (i<mylist.max_size()) mylist.resize(i);
 else std::cout << "That size exceeds the limit.\n";

 return 0;
}