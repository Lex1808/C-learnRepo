#include <iostream>
using namespace std;

void baby_sort(int *x, int *y, int *z) {
    int tmp;
    if (*x > *y) {
        tmp = *x;
        *x = *y;
        *y = tmp;
    }
    if (*y > *z) {
        tmp = *y;
        *y = *z;
        *z = tmp;
    }
    if (*x > *y) {
        tmp = *x;
        *x = *y;
        *y = tmp;
    }
 
}
int main() 
{
    int a, b, c;

    cout << "Enter numbers: ";
    cin >> a >> b >> c;

    baby_sort(&a, &b, &c);

    cout << a << " " << b << " " << c;

    return 0;
}
