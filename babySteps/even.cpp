#include <iostream>
#include <limits>
using namespace std;

int main()
{
    int number;

    do
    {
        cout << "Enter number: ";
        cin >> number;
       
        if (cin.fail()) {
            cout << "Enter only digit\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            number = 1;
        }
        else {
            if (number == 0) {
                break;
            }

            if (number % 2 == 0) {
                cout << "The number " << number << " is even\n";
            } else {
                cout << "The number " << number << " is not even\n";
            }
        }

    } while (true);
    
    return 0;
}
