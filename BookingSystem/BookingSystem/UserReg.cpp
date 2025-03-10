#include <iostream>
#include <fstream>
#include <string>
#include "UserReg.h"

using namespace std;

void registerUser() {
    string username, email, password;

    cout << "Enter username: " << endl; ;
    getline(cin, username);
    cout << "Enter email: " << endl;
    getline(cin, email);
    cout << "Enter password: " << endl ;
    getline(cin, password);

    ofstream userFile("users.txt", ios::app);
    if (userFile.is_open()) {
        userFile << username << "," << email << "," << password << endl;
        userFile.close();
        cout << "Registration successful!" << endl;
    }
    else {
        cout << "Unable to open file." << endl;
    }
}