#include <iostream>
#include <string>
using namespace std;

void simple_error(string s) {
    cerr << "Error: " << s << '\n';
    exit(1);
}

int main()
{
    string my_name;
    string other_human;
    string friend_name;
    string message;
    int age;

    cout << "What is your name? ";
    cin >> my_name;
    cout << "Your friend name: ";
    cin >> friend_name;
    cout << "Hello, " << my_name << "!" << '\n';

    cout << "Enter the name of the person you want to write to: ";
    cin >> other_human;
    cout << "Enter " << other_human << " age: ";
    cin >> age;
    cout << '\n';
    if (age <= 0 || age > 110) {
        simple_error("You are joke!");
    }
    if (age < 12) {
        message = "Next year you will be " + to_string(age + 1) + " year.";
    }
    else if (age == 17) {
        message = "Next year you will be able to vote.";
    }
    else if (age > 70) {
        message = "Are you already retired?";
    }
    else {
        message = "Cool";
    }

    cout << "Dear " << other_human << "," << '\n';
    cout << "How are you? I'm doing well. I really miss you and the times we had together. \n";
    cout << "By the way, have you seen " << friend_name << " lately?" 
         << " Write to him, he'll be happy to hear from you. Really.\n"
         << "I heard that you just had a birthday, and you turned the " << age << " of years. Congratulations!\n"
         << message << '\n'
         << "Sincerely, " << "" << "" << my_name << '\n';

    return 0;
}
