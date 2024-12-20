// Find a pair of values so that the precondition of this version of area holds, but the postcondition doesn’t.
#include <stdexcept>
#include <limits>
#include <iostream>

#define MAXAREA 100

void check_condition(bool condition, const std::string& message) {
    if (!condition) {
        throw std::runtime_error(message);
    }
}

int area(int length, int width) {
    int result;

    check_condition(0 < width && 0 < length, "Arguments must be positive");
    result = length * width;
    check_condition(result <= MAXAREA, "The area must not be larger than MAXAREA");

    return result;
}

int main()
{
    int length;
    int width;
    char terminate = 'e';

    std::cout << "The program calculates the standard building area" << std::endl;
    do
    {
        std::cout << "Enter length and with('e' for exit): ";
        std::cin >> terminate;
        if (terminate == 'e') {
            break;
        }
        std::cin.putback(terminate);

        std::cin >> length >> width;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Bad value. Enter only digit" << std::endl;
        } else {
            try
            {
                int area_result = area(length, width);
                std::cout << "The territory of the area of " << area_result << " m**2" << std::endl;
            }
            catch(const std::runtime_error& error)
            {
                std::cerr << "ERROR: " << error.what() << std::endl; 
                std::cerr << "Failed calculate area for length " << length << " and width " << width  << std::endl;
                return 1;
            }            
        }
    } while (1);
    
   return 0;
}
