#include <iostream>
#include <vector>
#include <string>
#include <limits>

void compare(const std::vector<std::string>& v) {
    if (v.empty()) {
        std::cout << "Is empty" << std::endl;
        return;
    }

    std::string minimum = v[0];
    std::string maximum = v[0];
    for (size_t i = 0; i < v.size(); ++i) {
        if (minimum > v[i]) {
            minimum = v[i];
        }
        if (maximum < v[i]) {
            maximum = v[i];
        }
    }

    std::cout << "Maximum: " << maximum << '\n' << "Minimum: " << minimum << std::endl; 
}
void findModa(std::vector<std::string>& v) {
    std::vector<std::string> uniqueString;
    std::vector<int> frequencies;

    // Find uniqu elements
    for (const std::string& str : v) {
        bool found = false;
        for (const std::string& uniqueStr : uniqueString) {
            if (str == uniqueStr) {
                found = true;
                break;
            }
        }

        if (!found) {
            uniqueString.push_back(str);
            frequencies.push_back(0);
        }
    }

    // Counting frequencies
    for (size_t i = 0; i < uniqueString.size(); ++i) {
        for (const std::string& str : v) {
            if (uniqueString[i] == str) {
                frequencies[i]++;
            }
        }
    }

    // Find max frequencies
    int maxFrequencies = 0;
    for (int freq : frequencies) {
        if (freq > maxFrequencies) {
            maxFrequencies = freq;
        }
    }

    // Print moda
    std::cout << "Moda: " << std::endl;
    for (size_t i = 0; i < uniqueString.size(); ++i) {
        if (frequencies[i] == maxFrequencies) {
            std::cout << frequencies[i] << " for word: " << uniqueString[i] << std::endl;
        }
    }
}


int main()
{
    std::vector<std::string> strings;
    for (std::string word; std::cin >> word; ) {
        if (word == "exit") {
            break;
        }
        strings.push_back(word);
    }

    compare(strings);
    findModa(strings);

    return 0;
}
