#include <iostream>
#include <vector>

void searchPrime(int n) {
    std::vector<bool> prime(n + 1, true);

    for (int p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            for (int i = p * p; i <= n; i += p) {
                prime[i] = false;
            }
        } 
    }

    for (int p = 2; p <= n; p++) {
        if (prime[p]) {
            std::cout << p << " ";
        }
    }
}

int main()
{
    int n = 100;
    std::cout << "Following are the prime numbers smaller "
         << " than or equal to " << n << std::endl;
    searchPrime(n);

    return 0;
}
