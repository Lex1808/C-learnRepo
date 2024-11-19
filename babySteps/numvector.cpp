#include <iostream>
#include <limits>
#include <vector>
#include <string>
#include <algorithm>

int main()
{
    std::vector<std::string> numbers = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    std::string input;
    char terminate;

    do
    {
        std::cout << "Enter number(0-9) or word(and 'q' for exit): ";
        std::cin >> terminate;
        if (terminate == 'q') {
            break;  
        }
        std::cin.putback(terminate);

        std::cin >> input;
        std::transform(input.begin(), input.end(), input.begin(),
                       [](unsigned char ch) {return std::tolower(ch); });
        try
        {
            int number = std::stoi(input);
            if (number >= 0 && number <= 9) {
                std::cout << number << " is " << numbers[number] << std::endl;
            } else {
                std::cout << "Enter only digits 0 - 9" << std::endl;
            }
        }
        catch(const std::invalid_argument& e)
        {
            bool find = false;
            for (size_t i = 0; i < numbers.size(); ++i) {
                if (input == numbers[i]) {
                    std::cout << input << " is " << i << std::endl;
                    find = true;
                    break;
                }
            }
            if (!find) {
                std::cout << "Enter only digits 0 - 9" << std::endl;
            }
        }

    } while (true);
    
    return 0;
}
