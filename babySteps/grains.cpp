#include <iostream>
#include <vector>

#define TOTAL_SQUARE 64

int main()
{
    int cur_squere;
    unsigned long long grains_num = 1;
    unsigned long long total_grains = 1;

    for (cur_squere = 1; cur_squere <= TOTAL_SQUARE; ++cur_squere) {
        if (total_grains >= 1000 && cur_squere <= 10) {
            std::cout << "To get at least 1000 grains you need " << cur_squere << " squeres" << std::endl;
        }
        if (total_grains >= 1000000 && cur_squere <= 20) {
            std::cout << "To get at least 1,000,000 grains you need " << cur_squere << " squeres" << std::endl;
        }
        if (total_grains >= 1000000000 && cur_squere <= 30) {
            std::cout << "To get at least 1,000,000,000 grains you need " << cur_squere << " squeres" << std::endl;
        }
        
        grains_num *= 2;
        total_grains += grains_num;
    }

    return 0;
}
