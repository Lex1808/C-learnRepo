#include <iostream>
#include <limits>

long long square_add(int num) {
    long long result = 0;
    for(int i = num; i > 0; --i) {
        result +=num;
    }
    return result;
}

int main()
{
    int user_input;
    char user_choise;
    
    std::cout << "Program to calculate the square of a number\n";

    do
    {
        std::cout << "Enter value: ";
        std::cin >> user_input;

        if(std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Wrong input. Enter only digit\n";
            continue;
        }
        std::cout << "Square number " << user_input << " is: " << square_add(user_input) << '\n';

        label:
        std::cout << "Would you like to continue?(Press 'y' or 'q' for exit): ";
        std::cin >> user_choise;
        if (user_choise != 'y' && user_choise != q) {
            continue;
        }
        else if(user_choise == 'q') {
            break;
        } else {
            goto label; 
        }


    } while (user_choise != 'q');
    
}
