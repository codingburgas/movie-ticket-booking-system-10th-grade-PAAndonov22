#include <iostream>
#include <fstream>
#include "../include/User.h"

User::User() {}

User::User(string username, string email, string password)
    : username(username), email(email), password(password) {}

string User::getUsername() const {
    return username;
}

bool User::registerUser() {
    ofstream userFile("users.txt", ios::app);
    if (userFile.is_open()) {
        userFile << username << "," << email << "," << password << endl;
        userFile.close();
        cout << "Registration successful!" << endl;
        return true;
    }
    cout << "Unable to open file." << endl;
    return false;
}

User User::loginUser() {
    string usernameInput, passwordInput;
    string line, storedUsername, storedEmail, storedPassword;

    cout << "Enter username: ";
    getline(cin, usernameInput);
    cout << "Enter password: ";
    getline(cin, passwordInput);

    ifstream userFile("users.txt");
    if (userFile.is_open()) {
        while (getline(userFile, line)) {
            size_t pos1 = line.find(',');
            size_t pos2 = line.rfind(',');

            if (pos1 != string::npos && pos2 != string::npos && pos1 != pos2) {
                storedUsername = line.substr(0, pos1);
                storedEmail = line.substr(pos1 + 1, pos2 - pos1 - 1);
                storedPassword = line.substr(pos2 + 1);

                if (storedUsername == usernameInput && storedPassword == passwordInput) {
                    cout << "Login successful!" << endl;
                    return User(storedUsername, storedEmail, storedPassword);
                }
            }
        }
        cout << "Invalid username or password." << endl;
    } else {
        cout << "Unable to open file." << endl;
    }
    return User();
}