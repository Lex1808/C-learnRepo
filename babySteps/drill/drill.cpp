#include <iostream>
#include <limits>

int main()
{
    double point1;
    double point2;
    char terminator;
    do
    {
        std::cout << "Enter two integers: ";
        std::cin >> terminator;
        if (terminator == '|') {
            break;
        }
        std::cin.putback(terminator);

        std::cin >> point1 >> point2;
        if(std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        double large = point1 > point2 ? point1: point2;
        double smaller = point1 < point2 ? point1: point2;
        if (point1 == point2) {
            std::cout << "The numbers: " << point1 << " and " << point2 << " are equel" << std::endl;
        } else {
            std::cout << "The larger value is: " << large << std::endl;
            std::cout << "The smaller value is: " << smaller << std::endl;
            if ((large - smaller) <= (1.0/100)) {
                std::cout << "The numbers: " << point1 << " and " << point2 << " are almost equal" << std::endl;
            } 
        }

    } while (true);

    return 0;
}
