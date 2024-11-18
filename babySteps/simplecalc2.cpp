#include <iostream>
#include <limits>

double calculate(double a, double b, char op) {
    switch (op)
    {
        case '+': return a + b; break;
        case '-': return a - b; break;
        case '*': return a * b; break;
        case '/': 
                    if (b == 0) {
                        std::cout << "division by 0!" << std::endl;
                    } else {    
                        return a / b;
                    } 
                break;
    }

    return false;
}
int main()
{
    double value1;
    double value2;
    char operators;
    char terminate;

    std::cout << "It's simple calculator" << std::endl;
    do
    {
        std::cout << "Enter your statement in format a b +-*/(or enter 'q' for exit): ";
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
        switch (operators)
        {
            case '+': case '-': case '*': case '/': std::cout << "Result: " << calculate(value1, value2, operators) << std::endl; break;
            default: std::cout << "Operator it's not one of +-*/" << std::endl; continue; break;
        }
    } while (true);
    
    return 0;

} 
