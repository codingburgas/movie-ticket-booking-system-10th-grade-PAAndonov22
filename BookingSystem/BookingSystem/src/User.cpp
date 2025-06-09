#include "../include/User.h"
#include <iostream>
#include <fstream>
#include <windows.h>

using namespace std;

void setColor(int color);

void User::registerUser() {
    string username, email, password;
    setColor(10); cout << "--- Register ---\n"; setColor(15);

    cout << "Enter username: ";
    getline(cin, username);
    cout << "Enter email: ";
    getline(cin, email);
    cout << "Enter password: ";
    getline(cin, password);

    ofstream userFile("users.txt", ios::app);
    if (userFile.is_open()) {
        userFile << username << "," << email << "," << password << endl;
        userFile.close();
        setColor(10); cout << "Registration successful!\n"; setColor(15);
    }
    else {
        setColor(12); cout << "Unable to open file.\n"; setColor(15);
    }
}

bool User::loginUser(string& username) {
    string password, line, storedUsername, storedEmail, storedPassword;
    bool loginSuccess = false;

    setColor(10); cout << "--- Login ---\n"; setColor(15);

    cout << "Enter username: ";
    getline(cin, username);
    cout << "Enter password: ";
    getline(cin, password);

    ifstream userFile("users.txt");
    if (userFile.is_open()) {
        while (getline(userFile, line)) {
            size_t pos1 = line.find(',');
            size_t pos2 = line.rfind(',');

            if (pos1 != string::npos && pos2 != string::npos && pos1 != pos2) {
                storedUsername = line.substr(0, pos1);
                storedEmail = line.substr(pos1 + 1, pos2 - pos1 - 1);
                storedPassword = line.substr(pos2 + 1);

                if (storedUsername == username && storedPassword == password) {
                    loginSuccess = true;
                    break;
                }
            }
        }
        userFile.close();

        if (loginSuccess) {
            setColor(10); cout << "Login successful!\n"; setColor(15);
            return true;
        }
        else {
            setColor(12); cout << "Invalid username or password.\n"; setColor(15);
            return false;
        }
    }
    else {
        setColor(12); cout << "Unable to open file.\n"; setColor(15);
        return false;
    }
}
