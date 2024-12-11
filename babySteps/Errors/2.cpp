#include <iostream>
#include <vector>
#include <stdexcept>


int main()
{
    try
    {
        std::vector<int> v;

        for (int num; std::cin >> num; ) {
            v.push_back(num);
        }

        size_t index = v.size(); 
        std::cout << "[" << index << "]" << " == " << v.at(index) << std::endl;
    }
    catch(std::out_of_range& e)
    {
        std::cerr << "Oops! Out of range: " << e.what() << '\n';
        return 1;
    }

  return 0;
}
