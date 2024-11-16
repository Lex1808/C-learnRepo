#include <iostream>
#include <vector>
#include <limits>

#define MAX 101

bool searchNumGame(const std::vector<int>& v, int num) {
    size_t first = 0;
    size_t last = v.size() - 1;
    size_t middle;
    int count = 7;
    char choose;

    while (first <= last) {
        middle = first + (last - first) / 2;

        if (v[middle] == num) {
            break;
        }
        std::cout << "Is the number you are thinking of less than " << v[middle] << "?: ";

        do {
            std::cin >> choose;

        } while (choose != 'y' && choose != 'n');

        if (choose == 'y') {
            last = middle - 1;
        } else if (choose == 'n') {
            first = middle + 1;
        } else {
            break;
        }

        count--;
        if (count == 0) {
            std::cout << "Ohh, I'm lose =(. You win! Congratulation" << std::endl;
            return false;
        }
    }

    std::cout << "\nI'm win! Your number is: " << v[middle] << std::endl;
    return true;
}

int main()
{
    std::vector<int> values;
    int user_input;
    char user_choose;

    std::cout << "Do you want to bet that I can guess your number?:)" << std::endl;
    std::cout << "Let's start! And enjoy =)" << std::endl;

    for (int i = 0; i < MAX; ++i) {
        values.push_back(i);
    }
    
    do
    {
        std::cout << "Enter your number(or 'q' for exit): ";
        std::cin >> user_choose;
        if (user_choose == 'q') {
            break;
        }
        std::cin.putback(user_choose);

        std::cin >> user_input;
        if (std::cin.fail() || user_input < 0 || user_input > 100) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Enter only digits 0 - 100: " << std::endl;
            continue;
        }

        searchNumGame(values, user_input);

    } while (true);
    
}
