#include <iostream>
#include <string>
#include <cctype>
#include <vector>

int main()
{
    std::vector<std::string> dislike = {"Agro", "Apple", "Mac", "cpu", "gpu", "RAM", "testing"};

    for (std::string word; std::cin >> word; ) {
        bool found = false;
        for(std::string& bad_word : dislike) {
            if(word.size() != bad_word.size()) {
                continue;
            }
        
            bool match = true;
            for(size_t i = 0; i < word.size(); ++i) {
                if (tolower(word[i]) != tolower(bad_word[i])) {
                    match = false;
                    break;
                }
            } 
            if(match) {
                std::cout << "BLEEP! ";
                found = true;
                break;
            }
        }

        if(!found) {
            std::cout << word << " ";
        }
    }

    std::cout << std::endl;
    return 0;
}
