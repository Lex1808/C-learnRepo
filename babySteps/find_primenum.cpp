#include <iostream>
#include <vector>
#include <cmath>

void search_prime(std::vector<int>& v) {
    v.push_back(2);

    for (int i = 3; i <= 100; ++i) {
        bool is_prime = true;
        for (int j = 0; v[j] <= std::sqrt(i); ++j) {
            if (i % v[j] == 0) {
                is_prime = false;
                break;
            }
        }
        if (is_prime == true) {
            v.push_back(i);
        }    
    }
} 

int main()
{
    std::vector<int> prime;

    search_prime(prime);

    for (size_t i = 0; i < prime.size(); ++i) {
        std::cout << prime[i] << " " << std::endl;
    }

    return 0; 
}
