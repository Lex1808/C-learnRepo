#include <iostream>
#include <stdlib.h>
#include <fstream>

#define DTTMFMT "%Y-%m-%d %H:%M:%S "
#define DTTMSZ 21

class Employee {
    private:
        int id = 1, password[100];
    public:
        int log_count = 0;
        char username[100];
        void signup(void);
        void login(void);
        void display(void);
        void choise(void);
        void alert(void);
};

static char *getDtTm (char *buff);

void Employee::signup(void) {
    
    std::cout << "Enter your username: ";
    std::cin >> username[id];
    std::cout << "Enter your password: ";
    std::cin >> password[id];

    std::cout << "\nNew user was added" << std::endl;
    std::cout << "Your id is: " << id << std::endl;
    
    id++;

    login();
}
void Employee::login(void) {
    char log_username;
    int log_password;
    int log_id;
    

    std::cout << "\nLogin";
    std::cout << "Enter your personal id: ";
    std::cin >> log_id;
    std::cout << "Enter your username: ";
    std::cin >> log_username;
    std::cout << "Enter your password: ";
    std::cin >> log_password;

    if (log_id >= 1 && log_id < id && username[log_id] == log_username && password[log_id] == log_password) {
        std::cout << "Login successfull\n";
        log_count = 0;
        choise();
    } else {
        log_count++;
        if(log_count == 3) {
            alert();
            throw std::runtime_error("Login fault!!!");
        }
        std::cout << "Error username or password";
        login();
    }
}

void Employee::choise(void) {
    int your_choise;

    std::cout << "Select an option below:\n1. Display all employees\n2. New employee\n3. Exit\n";
    std::cout << "Enter your choise: ";
    std::cin >> your_choise;
    
    switch (your_choise) {
        case 1: display(); break;
        case 2: signup(); break;
        case 3: std::cout << "Exiting program. Goodbye!\n"; exit(0); break;
        default: std::cout << "Invalid option\n"; choise(); break;       
    }

}

void Employee::display(void) {
    for (int i = 1; i < id; i++) {
        std::cout << "\nFor id " << i << " the first letter is " << username[i] << " and password is " << password[i];
    }
    std::cout << std::endl;
    choise();
}

void Employee::alert(void) {  
    std::ofstream alert_file("alert.txt");
    char buffer[DTTMSZ];
    alert_file << getDtTm(buffer) << "3 failed login attempts" << std::endl;

    alert_file.close();
}

static char *getDtTm (char *buff) {
    time_t t = time (0);
    strftime (buff, DTTMSZ, DTTMFMT, localtime (&t));
    return buff;
}

int main() {
    Employee employee;
    int choice;
    
    do
    {
        std::cout << "Select an option:\n";
        std::cout << "1. Signup\n";
        std::cout << "2. Login\n";
        std::cout << "3. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: employee.signup(); break;
            case 2: 
                    try {
                        employee.login();
                    } catch (const std::exception& e) {
                        std::cerr << "ERROR: " << e.what() << '\n';
                    }
                    break;
            case 3: 
                    std::cout << "Exiting program. Goodbye!\n";
                    break;
            default:
                    std::cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 3);
    
    
    return 0;
}
