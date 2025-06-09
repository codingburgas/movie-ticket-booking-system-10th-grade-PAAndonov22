#include "../include/Dashboard.h"
#include "../include/Cinema.h"
#include <iostream>
#include <windows.h>

using namespace std;

extern void setColor(int color);

void Dashboard::show(const string& username) {
    int choice;
    setColor(11);
    cout << "\n--- Logged In Dashboard ---\n";
    setColor(15);
    cout << "Welcome, "; setColor(14); cout << username << "!\n"; setColor(15);

    do {
        cout << "\n1. "; setColor(9); cout << "Choose Cinema\n"; setColor(15);
        cout << "2. "; setColor(9); cout << "View Profile\n"; setColor(15);
        cout << "3. "; setColor(12); cout << "Logout\n\n"; setColor(15);
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1:
            Cinema::chooseCity();
            break;
        case 2:
            cout << "Username: "; setColor(14); cout << username << "\n"; setColor(15);
            break;
        case 3:
            cout << "You have been logged out.\n";
            break;
        default:
            setColor(12); cout << "Invalid choice.\n"; setColor(15);
        }
    } while (choice != 3);
}
