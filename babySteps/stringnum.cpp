#include <iostream>
using namespace std;

int main() 
{
    string word;
    cout << "Enter string numbers(0, 1, 2, 3, 4): ";

    while (cin >> word) {
        if(word == "quit") {
            break;
        }

        if (word == "zero") {
            cout << 0 << '\n';
        } else if (word == "one") {
            cout << 1 << '\n';
        } else if (word == "two") {
            cout << 2 << '\n';
        } else if (word == "three") {
            cout << 3 << '\n';
        } else if (word == "four") {
            cout << 4 << '\n';
        }
        else {
            cout << "STUPID PC!\n";
        }
        cout << "Enter another word(or \"quit\"): ";
    }

    return 0;
}
