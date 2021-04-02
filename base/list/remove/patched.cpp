// remove from list
#include <iostream>
#include "list.hpp"

int main ()
{
 int myints[]= {17,89,7,14};
 ft::list<int> mylist (myints,myints+4);

 mylist.remove(89);

 std::cout << "mylist contains:";
 for (ft::list<int>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
 std::cout << ' ' << *it;
 std::cout << '\n';

 return 0;
}