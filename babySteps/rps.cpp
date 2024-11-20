#include <iostream>
#include <vector>
#include <random>
#include <limits>

int main()
{
    std::vector<std::string> rps = {"Rock", "Paper", "Scissors"};
    int userChoose;
    int userScore = 0;
    int computerScore = 0;
    int userWin = 0;
    int computerWin = 0;
    char terminate;

    do
    {
        std::cout << "1 - Rock" << std::endl;
        std::cout << "2 - Paper" << std::endl;
        std::cout << "3 - Scissors" << std::endl;
        std::cout << '\n';
        std::cout << "Enter your choose(or 'q' for exit): ";
        std::cin >> terminate;
        if (terminate == 'q') {
            break;
        }
        std::cin.putback(terminate);

        std::cin >> userChoose;
        if (userChoose < 1 || userChoose > 3) {
            std::cout << "Enter valid choose" << std::endl;
            continue;
        }
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input" << std::endl;
            continue;
        }

        std::random_device random_num;
        std::mt19937 gen(random_num());
        std::uniform_int_distribution<> distrib(0, rps.size() - 1);

        int random_index = distrib(gen);

        switch (userChoose)
        {
        case 1: 
                if (random_index == 2) {
                    std::cout << "Rock hits " << rps[random_index] << std::endl;
                    userScore++;
                }
                else if (random_index == 1) {
                    std::cout << rps[random_index] << " hits Rock" << std::endl;
                    computerScore++;
                } else {
                    std::cout << "Rock and " << rps[random_index] << ". Draw" << std::endl;
                    userScore++;
                    computerScore++;
                }
            break;
        case 2: 
                if (random_index == 2) {
                    std::cout << rps[random_index] << " hits Paper" << std::endl;
                    computerScore++;
                }
                else if (random_index == 0) {
                    std::cout << "Paper hits " << rps[random_index] << std::endl;
                    userScore++;
                } else {
                    std::cout << "Paper and " << rps[random_index] << ". Draw" << std::endl;
                    userScore++;
                    computerScore++;
                }
            break;
        case 3: 
                if (random_index == 0) {
                    std::cout << rps[random_index] << " hits Scissors" << std::endl;
                    computerScore++;
                }
                else if (random_index == 1) {
                    std::cout << "Scissors hits " << rps[random_index] << std::endl;
                    userScore++;
                } else {
                    std::cout << "Scissors and " << rps[random_index] << ". Draw" << std::endl;
                    userScore++;
                    computerScore++;
                }
            break;
        }

        if (userScore == 3) {
            std::cout << "You Win!" << std::endl;
            userWin++;
            userScore = 0;
            computerScore = 0;
        }
        if (computerScore == 3) {
            std::cout << "Computer Win!" << std::endl;
            computerWin++;
            userScore = 0;
            computerScore = 0;
        }

    } while (true);
    
    std::cout << "Total wins" << std::endl;
    std::cout << "Computer: " << computerWin << std::endl;
    std::cout << "User: " << userWin << std::endl;

    if (userWin > computerWin) {
        std::cout << "Congratulations! You have won and stopped the machine revolution!" << std::endl;
    } else if (computerWin > userWin) {
        std::cout << "The machines have won! Save John Connor!!!" << std::endl;
    } else {
        std::cout << "Today is a draw" << std::endl;
    }

    return 0;
}
