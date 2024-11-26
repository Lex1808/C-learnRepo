#include <iostream>
#include <cmath>
#include <limits>

double disc(double a1, double b2, double c3) {
    double discr;
    discr = pow(b2, 2) - (4 * (a1 * c3));

    return discr;
}

void quadratic(double discrim, double a, double b) {
    double root1; 
    double root2;

    if (discrim > 0) {
        root1 = (-b + sqrt(discrim)) / (2 * a);
        root2 = (-b - sqrt(discrim)) / (2 * a);

        std::cout << "x1 = " << root1 << '\n' << "x2 = " << root2 << std::endl;
    } else if (discrim == 0) {
        root1 = -b / (2 * a);
        std::cout << "x = " << root1 << std::endl;
    } else {
        std::cout << "The equation has no real roots." << std::endl;
    } 
}

int main()
{
    double a;
    double b;
    double c;
    double discriminant;

    do
    {
        std::cout << "Enter a, b, c values: ";
        std::cin >> a >> b >> c;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invaid value" << std::endl;
            continue;
        }
        break;
    } while (true);
    
    if (a == 0) {
        std::cout << "It's not a quadratic equation" << std::endl;
        return 1;
    }

    discriminant = disc(a, b, c);    
    quadratic(discriminant, a, b);

    return 0;
}
