#include <iostream>

constexpr int ALPHABET_SIZE = 26;

void print_alphabet(char first_letter) {
    if(first_letter != 'a' && first_letter != 'A') {
        throw std::invalid_argument("Invalid first letter " + std::string(1, first_letter) 
                                    + ".Expected letter 'a' or 'A'.");
    }
    for (int i = 0; i < ALPHABET_SIZE; ++i) {
        std::cout << char(first_letter + i) << '\t' << first_letter + i << '\n';
    }
}

int main()
{
    char leter = 'g';

    try {
        print_alphabet(leter);

        leter = std::toupper(leter);
        print_alphabet(leter);
    } 
    catch(const std::exception& error) {
        std::cerr << error.what() << '\n';
    }
    
    return 0;
}
