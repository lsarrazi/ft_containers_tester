// constructing queues
#include <iostream> // std::cout
#include <deque> // std::deque
#include <list> // std::list
#include "queue.hpp" // ft::queue

int main ()
{
 std::deque<int> mydeck (3,100); // deque with 3 elements
 std::list<int> mylist (2,200); // list with 2 elements

 ft::queue<int, std::deque<int> > first; // empty queue
 ft::queue<int, std::deque<int> > second (mydeck); // queue initialized to copy of deque

 ft::queue<int,std::list<int> > third; // empty queue with list as underlying container
 ft::queue<int,std::list<int> > fourth (mylist);

 std::cout << "size of first: " << first.size() << '\n';
 std::cout << "size of second: " << second.size() << '\n';
 std::cout << "size of third: " << third.size() << '\n';
 std::cout << "size of fourth: " << fourth.size() << '\n';

 return 0;
}