#include <iostream>
#include <limits>

double read_number() {
    double num;
    while (!(std::cin >> num)) { 
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please enter a number: ";
    }
    return num;
}

int main()
{
    double number;
    char terminator;
    double small_num;
    double large_num;

    std::cout << "Enter number: ";
    number = read_number();
    small_num = large_num = number;
    do
    {
        std::cout << "Enter two integers: ";
        std::cin >> terminator;
        if (terminator == '|') {
            break;
        }
        std::cin.putback(terminator);

        number = read_number();

        if(number < small_num) {
            small_num = number;
            std::cout << small_num << " the smallest so far" << std::endl;
        } else if(number > large_num) {
            large_num = number;
            std::cout << large_num << " the largest so far" << std::endl;
        } else {
            std::cout << number << std::endl;
        }

    } while (true);

    if (small_num == large_num) {
        std::cout << "The numbers: " << small_num << " and " << large_num << " are equel" << std::endl;
    } else {
        std::cout << "The larger value is: " << large_num << std::endl;
        std::cout << "The smaller value is: " << small_num << std::endl;
        if ((large_num - small_num) <= (1.0/100)) {
            std::cout << "The numbers: " << large_num << " and " << small_num << " are almost equal" << std::endl;
        } 
    }

    return 0;
}
