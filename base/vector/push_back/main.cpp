// vector::push_back
#include <iostream>
#include <vector>
#include <sstream>

int main ()
{
 std::vector<int> myvector;
 int myint;

 std::cout << "Please enter some integers (enter 0 to end):\n";
 std::istringstream iss("10 15 20 88 42 4757 785 277 2782 8728 45 245 245 0");
 do {
 iss >> myint;
 myvector.push_back (myint);
 } while (myint);

 std::cout << "myvector stores " << int(myvector.size()) << " numbers.\n";

 return 0;
}