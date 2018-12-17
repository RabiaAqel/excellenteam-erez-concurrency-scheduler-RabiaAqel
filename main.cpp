#include <iostream>
#include <vector>
#include <algorithm>


int main ()
{
    std::cout << "Hello, World!" << std::endl;

    std::vector<int> v;
    std::make_heap (v.begin (), v.end ());
    v.push_back (99);
    v.push_back (104);
    v.push_back (33);
    v.push_back (2);


    std::cout << v.front () << std::endl;

    return 0;
}