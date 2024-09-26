#include <iostream>
#include <string>

class BankAccount {
    public:
        int accountNumber;
        std::string ownerName;
        double balance;

        BankAccount(int accountNumber, const std::string& ownerName) : accountNumber(accountNumber), ownerName(ownerName), balance(0) {}
          
    public: 
        void deposit(double amount) {
            if (amount > 0) {
                balance += amount;
                std::cout << "Deposit successuful. Your balance: " << balance << std::endl;
            } else {
                throw std::runtime_error("Balanc does't have negative value");
            }        
        }
        void withdraw(double amount) {
            if (amount <= balance && amount > 0) {
                balance -= amount;
                std::cout << "Thank you! Your balance: " << balance << std::endl;
            } else {
                throw std::runtime_error("No costs");
            }
        }
};

int main(void) {
    BankAccount customer(1, "John Doe");

    try {
        customer.deposit(5000);
        customer.withdraw(1000);
        customer.withdraw(100000);
    } 
    catch (const std::exception& err) {
       std::cerr << "ERROR: " << err.what() << std::endl;
    }

    return 0; 
}
