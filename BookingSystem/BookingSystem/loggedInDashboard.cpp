#include <iostream>
#include "account.h"
#include "cinema.h"

void showLoggedInMenu(const string& username) {
    int choice;

    cout << "------------------------\n";
    cout << "Welcome to CinemaBooking\n";
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
        break;
    case 3:
        cout << "You have been logged out." << endl;
        break;
    default:
        cout << "Invalid choice." << endl;
        break;
    }
}