#include <iostream>
#include <vector>
#include <iomanip>

int main()
{
    std::vector<double> distance;
    double greatest_dist; 
    double smallest_dist;

    for (double dist; std::cin >> dist; ) {
        distance.push_back(dist);
    }

    double sum = 0;
    for (double value : distance) {
        sum += value;
    }
    std::cout << "Total distance: " << std::fixed << std::setprecision(1) << sum << std::endl;

    greatest_dist = smallest_dist = distance[0];
    
    for (size_t i = 0; i < distance.size(); ++i) {
        if (smallest_dist > distance[i]) {
            smallest_dist = distance[i];
        }
        if (greatest_dist < distance[i]) {
            greatest_dist = distance[i];
        }
    }

    std::cout << "Greatest distance: " << greatest_dist << std::endl;
    std::cout << "Smaller distance: " << smallest_dist << std::endl;

    return 0;
}
