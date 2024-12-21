#include <iostream>
#include <limits>
#include <random>
#include <thread>
#include <chrono>

std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<int> dist(1,6);

int main()
{
    int user;
    int cpu;
    int user_score = 0;
    int cpu_score = 0;
    int game_rounds = 1;

    std::cout << "Roll the dice?" << std::endl;
    do 
    {
        std::cout << "Chose number rounds: ";
        std::cin >> game_rounds;
        if (!std::cin.fail() && game_rounds > 0) {
            break;
        } else {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');           
            std::cerr << "Enter only digits and digit must have large then 0" << std::endl;
        }    
    } while (true);
    
    while (game_rounds != 0) {

        std::cout << "CPU queue" << std::endl;
        cpu = dist(gen);
        std::cout << cpu << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));

        std::cout << "Your queue" << std::endl;
        user = dist(gen); 
        std::cout << user << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));

        if (cpu > user) {
            cpu_score++;
        } 
        else if (user > cpu) {
            user_score++;
        } else {
            cpu_score++;
            user_score++;
        }

        game_rounds--;
        if (game_rounds == 0) {
            break;
        }
    } 

    if (cpu_score > user_score) {
        std::cout << "CPU win!" << std::endl;
    }
    else if (user_score > cpu_score)
    {
        std::cout << "Your win machine! Congratulation" << std::endl;
    } else {
        std::cout << "Draw" << std::endl;
    }
    
    return 0;
}
