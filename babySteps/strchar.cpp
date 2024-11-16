#include <iostream>
#include <limits>
#include <cstring>

int main()
{
    std::string word;

    std::cout << "Read word: ";
    std::cin >> word;
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Enter only words";
    }

    int amount_chars = word.length();
    for (int i = 0; i < amount_chars; ++i) {
        std::cout << word[i] << " equel " << word[i] + 0 << std::endl;
    }

    return 0;
}
