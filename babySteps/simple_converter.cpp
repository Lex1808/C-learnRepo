#include <iostream>
#include <limits>
#include <iomanip>
using namespace std;

double jpy_dollars(double sum) {
    constexpr double dollar_course = 0.01;
    return (double) sum * dollar_course;
}

double kron_dollars(double sum) {
    constexpr double dollar_course = 0.04;
    return (double) sum * dollar_course; 
}

double pound_dollars(double sum) {
    constexpr double dollar_course = 1.29;
    return (double) sum * dollar_course;
}

int main()
{
    double amount;
    char choose;

    do
    {
        cout << "Enter the amount you want to convert in dollars: ";
        cin >> amount;
        if (cin.fail()) {
            cout << "Enter only digit\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        cout << "Select a currency: 'y' - yuan, 'p' - pound, 'k' - kron('q' for exit): ";
        cin >> choose;
        if (choose == 'q') {
            cout << "Thank you!\n";
            break;
        }

        if (choose == 'y') {
            cout << "Total: $" << fixed << setprecision(2) << jpy_dollars(amount) << '\n'; 
        }
        else if (choose == 'k') {
            cout << "Total: $" << fixed << setprecision(2) << kron_dollars(amount) << '\n'; 
        }
        else if (choose == 'p') {
            cout << "Total: $" << fixed << setprecision(2) << pound_dollars(amount) << '\n'; 
        }
        else {
            cout << "Enter 'k', 'p', 'y' or 'q' to exit\n";
        }
    } while (true);
    
}
