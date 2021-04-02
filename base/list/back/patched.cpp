// list::back
#include <iostream>
#include "list.hpp"

int main ()
{
 ft::list<int> mylist;

 mylist.push_back(10);

 while (mylist.back() != 0)
 {
 mylist.push_back ( mylist.back() -1 );
 }

 std::cout << "mylist contains:";
 for (ft::list<int>::iterator it=mylist.begin(); it!=mylist.end() ; ++it)
 std::cout << ' ' << *it;

 std::cout << '\n';

 return 0;
}