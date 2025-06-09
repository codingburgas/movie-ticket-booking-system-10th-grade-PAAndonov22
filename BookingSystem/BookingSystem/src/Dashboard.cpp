#include "../include/Dashboard.h"
#include "../include/Cinema.h"
#include <iostream>

using namespace std;

void Dashboard::show(const User& user) {
    int choice;
    do {
        cout << "------------------------\n";
        cout << "Welcome, " << user.getUsername() << "!\n";
        cout << "------------------------\n";
        cout << "1. Choose Cinema\n";
        cout << "2. View Profile (Coming soon)\n";
        cout << "3. Logout\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1:
            Cinema::chooseCity();
            break;
        case 2:
            cout << "Profile page not implemented yet." << endl;
            break;
        case 3:
            cout << "You have been logged out." << endl;
            break;
        default:
            cout << "Invalid choice." << endl;
            break;
        }
        cout << endl;
    } while (choice != 3);
}
