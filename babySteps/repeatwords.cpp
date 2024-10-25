#include <iostream>
using namespace std;

int main()
{
    string current;
    string previous;
    int word_number = 0;
    int repeat = 0;

    while(cin >> current && current != "q") {
        ++word_number;
        if (current == previous) {
            cout << "Word number " << word_number << " repeat: " << current << "\n";
            repeat++;
        }
        previous = current;
        
    }
    cout << "Repeat counting equel: " << repeat;

    return 0;
}
