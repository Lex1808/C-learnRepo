#include <iostream>
#include <stdexcept>

class Calculator {
    public:
        double calculate(double x, double y, char symbol) {
            double result = 0;
            switch (symbol)
            {
                case '+': result = x + y; break;
                case '-': result = x - y; break;
                case '/': result = x / y;
                        if(x == 0 || y == 0) {
                            throw std::runtime_error("Devide on ZERO");
                        }
                    break;
                case '*': result = x * y; break;
                default: fprintf(stderr, "Error value\n"); break;
            }
            return result;
        }
    
};

class FactorialCalculate {
    public:
        int factorial(int number) {
            if (number == 1) {
                return 1;
            } else {
                return number * factorial(number - 1);
            }
        }            
};

void startClalculator(void) {
    Calculator calc;
    double result;
    char symb;
    double number1, number2;
    while(1) {
        std::cout << "Enter expression: ";
        std::cin >> number1 >> symb >> number2;
        if (symb != '+' && symb != '-' && symb != '/' && symb != '*') {
            fprintf(stderr, "Invalid symbols\n");
            return;
        }

        try {
            result = calc.calculate(number1, number2, symb);
            std::cout << "Result equel " << result << std::endl;
        } catch(const std::exception& e) {
            std::cerr << "ERROR: " << e.what() << std::endl;
        }
    }     
}

int main(void) {
    FactorialCalculate calculate;
    int number;
    double number1, number2;
    int chose;

    std::cout << "Chose function(1 - calculate factorial, 2 - Calculator): ";
    std::cin >> chose;

    if (chose == 1) {
        std::cout << "Enter number: ";
        std::cin >> number;

        if (number < 0) {
            std::cout << "Factorial is not defined for negative numbers.\n";
        } else {
            int result = calculate.factorial(number);
            std::cout << "Factorial of number " << number << " equel " << result << std::endl;
        }
    }
    
    if (chose == 2) {
        startClalculator();
    }

    return 0;
}
