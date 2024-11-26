#include <iostream>
#include <vector>
#include <limits>

bool uniqueName(std::vector<std::string>& v) {
    std::vector<std::string> uniqueNames;

    for (const std::string& name : v) {
        bool find = false;
        for (const std::string& uniqName : uniqueNames) {
            if (name == uniqName) {
                find = true;
                break;
            }
        }
        if (!find) {
            uniqueNames.push_back(name);
        }
    }

    for (size_t i = 0; i < uniqueNames.size(); ++i) {
        int repeat = 0;
        for (const std::string& name : v) {
            if (uniqueNames[i] == name) {
                repeat++;
            }
            if (repeat > 1) {
                return false;
            } 
        }
    }

    return true;
}

void findName(std::vector<std::string>& v, std::vector<int>& key) {
    while (true) {
        std::string name;

        std::cout << "Enter name: ";
        std::cin >> name;
        if (name == "exit") {
            return;
        }

        bool find = false;
        for (size_t i = 0; i < v.size(); ++i) {
            if (name != v[i]) {
                continue;
            } else {
                find = true;
                std::cout << "Key: " << key[i] << std::endl;
            }  
        }
        if (!find) {
            std::cout << "Name not found" << std::endl;
        }
    }
    
}

void score(std::vector<std::string>& v, std::vector<int> key) {
    while (true) {
        int score;

        std::cout << "Enter score: ";
        std::cin >> score;
        if (score == -1) {
            break;
        }
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid value. Enter digits" << std::endl;
            continue;
        }

        bool find = false;
        for (size_t i = 0; i < key.size(); ++i) {
            if (score == key[i]) {
                std::cout << v[i] << std::endl;
                find = true;
            }    
        }
        if (!find) {
            std::cout << "Score not found." << std::endl;
        }
    }
}

int main()
{
    std::string name;
    int key;
    std::vector<std::string> forName;
    std::vector<int> forKey;

    while (true) {
        std::cout << "Enter paie name key(or 'NoName 0 for exit'): ";
        std::cin >> name >> key;
        if (name == "NoName" && key == 0) {
            break;
        }

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid value" << std::endl;
        }
        forName.push_back(name);
        forKey.push_back(key);
    }

    if (!uniqueName(forName)) {
        std::cout << "This list have not unique value" << std::endl;
        return 1;
    } else {
        findName(forName, forKey);
    }

    score(forName, forKey);

    /*
    std::cout << '\n';
    for (size_t i = 0; i < forName.size() && i < forKey.size(); i++) {
        std::cout << forName[i] << " " << forKey[i] << std::endl;
    }
    */
   
    return 0;
} 
