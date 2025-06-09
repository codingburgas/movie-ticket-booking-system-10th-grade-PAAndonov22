#include <iostream>
#include "account.h"
#include "cinema.h"

using namespace std;

void showLoggedInMenu(const string& username) {
    int choice;

    do {
        cout << "------------------------\n";
        cout << "Welcome, " << username << "!\n";
        cout << "------------------------\n";

        cout << "1. Choose Cinema\n";
        cout << "2. View Profile\n";
        cout << "3. Logout\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1:
            chooseCity();
            break;
        case 2:
            cout << "Profile functionality coming soon!" << endl;
            break;
        case 3:
            cout << "You have been logged out." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }

        cout << endl;

    } while (choice != 3);
}