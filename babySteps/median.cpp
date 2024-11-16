#include <algorithm>
#include <iostream>
#include <vector>
#include <iomanip>


int main()
{
    std::vector<double> temperature;
    
    for (double temps; std::cin >> temps; ) {
        temperature.push_back(temps);
    }
    if (temperature.empty()) {
        std::cout << "Average : null" << std::endl;
        std::cout << "Median temperature: null" << std::endl;

        return 0;
    }

    double sum = 0;
    for (double tmp_sum : temperature) {
        sum += tmp_sum;
    }
    std::cout << "Average : " << std::fixed << std::setprecision(1) << sum / temperature.size() << std::endl;

    std::ranges::sort(temperature);
    if (temperature.size() % 2 == 0) {
        int index1 = temperature.size() / 2 - 1; // find index for median calculate
        int index2 = temperature.size() / 2; // find index for median calculate

        std::cout << "Median temperature: " << std::fixed << std::setprecision(1) << (temperature[index1] + temperature[index2]) / 2 << std::endl;
    } else {
        std::cout << "Median temperature: " << std::fixed << std::setprecision(1) << temperature[temperature.size() / 2] << std::endl;
    }

    return 0;    
}
