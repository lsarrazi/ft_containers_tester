// list::begin/end
#include <iostream>
#include "list.hpp"

int main ()
{
 int myints[] = {75,23,65,42,13};
 ft::list<int> mylist (myints,myints+5);

 std::cout << "mylist contains:";
 for (ft::list<int>::iterator it=mylist.begin() ; it != mylist.end(); ++it)
 std::cout << ' ' << *it;

 std::cout << '\n';

 return 0;
}