#include <iostream>
#include <limits>
#include <iomanip>
using namespace std;

double yen_dollars(double sum) {
    constexpr double dollar_course = 0.01;
    return sum * dollar_course;
}

double kron_dollars(double sum) {
    constexpr double dollar_course = 0.04;
    return sum * dollar_course; 
}

double pound_dollars(double sum) {
    constexpr double dollar_course = 1.29;
    return sum * dollar_course;
}
double frank_dollars(double sum) {
    constexpr double dollar_course = 1.16;
    return sum * dollar_course;
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
        if(amount <= 0) {
            cout << "Enter sum to convert, please\n";
            continue;
        } 
        cout << "Select a currency: 'y' - yuan, 'p' - pound, 'k' - kron, 'f' - frank('q' for exit): ";
        cin >> choose;
        switch (choose)
        {
            case 'y': cout << "Total: $" << fixed << setprecision(2) << yen_dollars(amount) << '\n'; break;
            case 'k': cout << "Total: $" << fixed << setprecision(2) << kron_dollars(amount) << '\n'; break;
            case 'p': cout << "Total: $" << fixed << setprecision(2) << pound_dollars(amount) << '\n'; break;
            case 'f': cout << "Total: $" << fixed << setprecision(2) << frank_dollars(amount) << '\n'; break;
            case 'q': cout << "Thank you!\n"; return 0; break;
        
            default: cout << "Enter 'k', 'p', 'y', 'f' or 'q' to exit\n"; break;
        }

    } while (true);
    
}
