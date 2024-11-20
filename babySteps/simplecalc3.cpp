#include <iostream>
#include <limits>
#include <vector>
#include <string>
#include <algorithm>

int calculate(std::vector<std::string>& num, std::string a, std::string b, char op) {
    int number1;
    int number2;

    //Processing for the first argument
    try
    {
        number1 = std::stoi(a);
        if (number1 < 0 || number1 > 9) {
            std::cout << "Invalid input" << std::endl;
            return 0;
        } 
    } catch(const std::invalid_argument& e) {
        bool find1 = false;
        for (size_t i = 0; i < num.size(); ++i) {
            if (a == num[i]) {
                number1 = i;
                find1 = true;
            }
        }
        if (!find1) {
            std::cout << "Invalid input" << std::endl;
            return 0;
        }
    }

    //Processing for the second argument
    try
    {
        number2 = std::stoi(b);
        if (number2 < 0 || number2 > 9) {
            std::cout << "Invalid input" << std::endl;
            return 0;
        } 
    } catch(const std::invalid_argument& e) {
        bool find2 = false;
        for (size_t i = 0; i < num.size(); ++i) {
            if (b == num[i]) {
                number2 = i;
                find2 = true;
            }
        }
        if (!find2) {
            std::cout << "Invalid input" << std::endl;
            return 0;
        }
    }

    // Total calculate
    switch (op)
    {
        case '+': return number1 + number2; break;
        case '-': return number1 - number2; break;
        case '*': return number1 * number2; break;
        case '/': 
                    if (number2 == 0) {
                        std::cout << "division by 0!" << std::endl;
                        return 0;
                    } else {    
                        return number1 / number2;
                    } 
                break;
    }

    return 0;
}


int main()
{
    std::vector<std::string> numbers = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    std::string value1;
    std::string value2;
    char operators;
    char terminate;

    std::cout << "It's simple calculator" << std::endl;
    do
    {
        std::cout << "Enter your statement in format a b +-*/('q' for exit): ";
        std::cin >> terminate;
        if (terminate == 'q') {
            break;
        }
        std::cin.putback(terminate);

        std::cin >> value1 >> value2 >> operators;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        int result = calculate(numbers, value1, value2, operators);
        if (result != 0 || (value1 == "zero" && value2 == "zero" && operators == '+')) { 
            std::cout << "Result: " << result << std::endl; 
        }

    } while (true);
    
    return 0;

} 
