#include <iostream>
using namespace std;

void money_counting(int pen, int nick, int dim, int quart, int h_dol, int dol) {
    int result;
    result = (pen * 1) + (nick * 5) + (dim * 10) + (quart * 25) + (h_dol * 50) + (dol * 100);

    cout << "You have total: $" << (result / 100) << "." << (result % 100) << " dollars\n";
}
int main()
{
    int pennies; // 1
    int nickles; // 5
    int dimes; // 10
    int quarters; // 25
    int half_dollars; // 50
    int dollars; // 100

    cout << "Pennies: ";
    cin >> pennies;
    cout << "Nickles: ";
    cin >> nickles;
    cout << "Dimes: ";
    cin >> dimes;
    cout << "Quarters: ";
    cin >> quarters;
    cout << "Half Dollars: ";
    cin >> half_dollars;
    cout << "Dollars: ";
    cin >> dollars;
    
    if (pennies == 1) {
        cout << "You have " << pennies << " pennie.\n";
    } else {
        cout << "You have " << pennies << " pennies.\n";
    }  
    if (nickles == 1) {
        cout << "You have " << nickles << " nickle.\n";
    } else {
        cout << "You have " << nickles << " nickles.\n";
    }
    if (dimes == 1) {
        cout << "You have " << dimes << " dime.\n";
    } else {
        cout << "You have " << dimes << " dimes.\n";
    }
    if (quarters == 1) {
        cout << "You have " << quarters << " quarter.\n";
    } else {
        cout << "You have " << quarters << " quarters.\n";
    }
    if (half_dollars == 1) {
        cout << "You have " << half_dollars << " half_dollar.\n";
    } else {
        cout << "You have " << half_dollars << " half_dollars.\n";
    }
    if (dollars == 1) {
        cout << "You have " << dollars << " dollar.\n";
    } else {
        cout << "You have " << dollars << " dollars.\n";
    }
    
    money_counting(pennies, nickles, dimes, quarters, half_dollars, dollars);

    return 0;
}
