#include <algorithm>
#include <iostream>
#include <limits>
#include <iomanip>

double read_number() {
    double num;
    while (!(std::cin >> num)) { 
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please enter a number: ";
    }
    return num;
}

std::string read_units() {
    std::string u;

    std::cin >> u;
    while (u != "cm" && u != "m" && u != "in" && u != "ft") { 
        std::cout << "You can use only 'cm', 'm', 'in', 'ft': ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> u;
    }

    return u;
}

double units_convert(double num, std::string& u) {
   constexpr double cm = 1;
   constexpr double m_to_cm = 100;
   constexpr double in_to_cm = 2.54;
   constexpr double ft_to_in = 12;

   if(u == "cm") {
        num *= cm;    
   } else if(u == "m") {
        num *= m_to_cm;
   } else if(u == "in") {
        num *= in_to_cm;
   } else if(u == "ft") {
        num *= ft_to_in * in_to_cm;
   }

   return num;
}

double cm_convert(double sum) {
    constexpr double cm_to_meters = 0.01;
    return sum * cm_to_meters;
}

void push_in_vector(std::vector<double> &v, double num, std::string u) {
    if(u != "cm") {
        num = units_convert(num, u);
    }
    num = cm_convert(num);
    v.push_back(num);
}

int main()
{
    double number;
    std::string units;
    std::string unit_total = "cm";
    char terminator;
    double small_num;
    double large_num;
    int sum_count = 0;
    double total_sum = 0;
    std::vector<double> total_meters;
    
    std::cout << "Enter number: ";
    number = read_number();
    units = read_units();
    push_in_vector(total_meters, number, units);
    number = units_convert(number, units);
    small_num = large_num = number;
    total_sum += number;
    sum_count++;
    
    do
    {
        std::cout << "Enter number: ";
        std::cin >> terminator;
        if (terminator == '|') {
            break;
        }
        std::cin.putback(terminator);

        number = read_number();
        units = read_units();
        push_in_vector(total_meters, number, units);
        number = units_convert(number, units);
        total_sum += number;
        
        if(number < small_num) {
            small_num = number;
            std::cout << small_num << unit_total << " the smallest so far" << std::endl;
        } else if(number > large_num) {
            large_num = number;
            std::cout << large_num << unit_total << " the largest so far" << std::endl;
        } else {
            std::cout << number << unit_total << std::endl;
        }

        sum_count++;

    } while (true);
        
    if (small_num == large_num) {
        std::cout << "The numbers: " << small_num << unit_total << " and " << large_num << unit_total << " are equel" << std::endl;
    } else {
        std::cout << "The larger value is: " << large_num << unit_total << std::endl;
        std::cout << "The smaller value is: " << small_num << unit_total << std::endl;
        if ((large_num - small_num) <= (1.0/100)) {
            std::cout << "The numbers: " << large_num << unit_total << " and " << small_num << unit_total << " are almost equal" << std::endl;
        } 
    }
    std::cout << "The number of values entered is: " << sum_count << std::endl;
    std::cout << "The sum of values is: " << std::fixed << std::setprecision(2) << cm_convert(total_sum) << "m" << std::endl;

    std::ranges::sort(total_meters);
    std::cout << "All values converted into meters: ";
    for (size_t i = 0; i < total_meters.size(); ++i) {
        std::cout << total_meters[i] << "m" << " ";
    }
    
    return 0;
}
