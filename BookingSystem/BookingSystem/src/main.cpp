#include <iostream>
#include "../include/User.h"
#include "../include/Dashboard.h"

using namespace std;

int main() {
    cout << "------------------------\n";
    cout << "Welcome to CinemaBooking\n";
    cout << "------------------------\n";

    int choice;
    do {
        cout << "1. Register a new user\n";
        cout << "2. Login\n";
        cout << "3. Exit CinemaBooking\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1: {
            string username, email, password;
            cout << "Enter username: ";
            getline(cin, username);
            cout << "Enter email: ";
            getline(cin, email);
            cout << "Enter password: ";
            getline(cin, password);
            User user(username, email, password);
            user.registerUser();
            break;
        }
        case 2: {
            User user = User::loginUser();
            if (!user.getUsername().empty()) {
                Dashboard::show(user);
            }
            break;
        }
        case 3:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 3);

    return 0;
}
