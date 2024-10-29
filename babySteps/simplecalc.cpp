#include <iostream>
using namespace std;

double plus_op(double a, double b) {
    return a + b;
}
double minus_op(double a, double b) {
    return a - b;
}
double mul_op(double a, double b) {
    return a * b;
}
double div_op(double a, double b) {
    if (a == 0 || b == 0) {
        cout << "ERROR: Division by 0\n";
        return 0;
    }
    return a / b;
}

int main()
{
    string operation;
    double operand1;
    double operand2;

    cout << "Enter calc operation: ";
    while (cin >> operation >> operand1 >> operand2) {
        double result;

        if(operation == "+" || operation == "plus") {
            result = plus_op(operand1, operand2);
        }
        else if(operation == "-" || operation == "minus") {
            result = minus_op(operand1, operand2);
        }
        else if(operation == "/" || operation == "div") {
            result = div_op(operand1, operand2);
        }
        else if(operation == "*" || operation == "mul") {
            result = mul_op(operand1, operand2);
        } else {
            cout << "ERROR: Invalid operation\n";
            cout << "Enter calc operation: ";
            continue;
        }

        cout << "Result: " << result << '\n';
        cout << "Enter another calc operation: ";
    }

}
