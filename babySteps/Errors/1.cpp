#include <iostream>

class bad_area {}; // for exception

void error(const std::string& e) {
    std::cerr << "ERROR: " << e << std::endl;
    exit(EXIT_FAILURE);
}

int area(int length, int width)
{
    if (length <= 0 || width <= 0) {
        throw bad_area {};
    }

    return length * width;
}

int framed_area(int x, int y)
{
    constexpr int framed = 2;
    if (x - framed <= 0 || y - framed <= 0) {
        error("Non Positive area() arguments for framed_area()");
    }

    return area(x - framed,y - framed);
}

void test(int x, int y, int z)
{
    int area1 = area(x, y);
    int area2 = framed_area(z, y);
    int area3 = framed_area(y, z);
    double ratio = double (area1) / area3;
    std::cout << area1 << std::endl;
    std::cout << area2 << std::endl;
    std::cout << area3 << std::endl;
    std::cout << ratio << std::endl;
}

int main()
{
    try
    {
        test(0,4,5);
    }
    catch(bad_area)
    {
        std::cerr << "Oops=( Bad argument" << '\n';
    }
}
