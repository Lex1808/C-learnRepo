#include <algorithm>
#include <iostream>
#include <vector>
#include <limits>


void moda(std::vector<int>& v) {
    int digit = 0;
    int count = 0;
    std::vector<int> counting;
    std::vector<int> digits;

    for (size_t i = 0; i < v.size(); ++i) {
        if (v[i] == digit) {
            continue;
        }

        digit = v[i];
        for (size_t j = 0; j < v.size(); ++j) {
            if (v[j] == v[i]) {
                count++;
            } 
        }
        counting.push_back(count);
        digits.push_back(digit);

        count = 0;
    }
    
    bool repeat;
    for (size_t i = 0; i < counting.size(); ++i) {
        if (counting[i] > 1) {
            repeat = true;
            break;
        } else {
            repeat = false;
        }
    }

    int max_size = counting[0];
    int moda = 0;
    size_t index;
    if (!repeat) {
        std::cout << "Moda not find" << std::endl;
    } else {        
        for (index = 0; index < counting.size(); index++) {
            if (counting[index] > max_size) {
                max_size = counting[index];
                moda = digits[index];
            }
        }

        std::cout << "Moda: " << moda << " repeat: " << max_size << std::endl;
    }
}

int main()
{
    std::vector<int> num;

    for (int digits; std::cin >> digits; ) {
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        num.push_back(digits);
    }
    std::ranges::sort(num);

    moda(num);

    return 0;
}
