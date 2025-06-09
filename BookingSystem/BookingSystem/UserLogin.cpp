#include <iostream>
#include <fstream>
#include <string>
#include "UserLogin.h"
#include "account.h"
using namespace std;

void loginUser() {
    string username, password;
    string line, storedUsername, storedEmail, storedPassword;
    bool loginSuccess = false;

    cout << "Enter username: " << endl;
    getline(cin, username);
    cout << "Enter password: " << endl;
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
            cout << "Login successful!" << endl;
        }
        else {
            cout << "Invalid username or password." << endl;
        }
    }
    else {
        cout << "Unable to open file." << endl;
    }
    showLoggedInMenu(username);
}