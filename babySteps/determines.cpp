#include <iostream>
#include <optional>
#include <string>
using namespace std;

optional<bool> compare(int a, int b) {
    if (a > b) {
        cout << to_string(a) + " greter then " + to_string(b) << endl;
        return true;
    }
    else if (a < b) {
        cout << to_string(a) + " less then " + to_string(b) << endl;
        return false; 
    }
    else {
        cout << a << " and " << b << " are equel" << endl;
        return nullopt;
    }    
}
int sum(int a, int b) {
    return a + b;
}
int difference(int a, int b) {
    return a - b;
}
long long product(int a, int b) {
    return a * b;
}
double ratio(int a, int b) {
    if (a == 0 || b == 0) {
        return -1;
    }
    return (double) a / b;
}

int main()
{
    int val1 = 4096;
    int val2 = 56;
    auto compare_result = compare(val1, val2);

    cout << "Compare: ";
    if (compare_result.has_value()) { 
        cout << (compare_result.value() ? "true" : "false") << '\n';
    } else {
        cout << "nullopt" << '\n'; 
    }
    cout << "Sum: " << sum(val1, val2) << '\n'
         << "Difference: " << difference(val1, val2) << '\n'
         << "Product: " << product(val1, val2) << '\n'
         << "Ratio: " << ratio(val1, val2) << '\n';

    return 0; 
}
