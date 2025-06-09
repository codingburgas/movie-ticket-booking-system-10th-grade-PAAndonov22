#include <iostream>
#include <windows.h>
#include "../include/User.h"
#include "../include/Dashboard.h"

using namespace std;

void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

int main() {
    
    setColor(11);
    cout << R"(
 __  __            _        _____ _      _        _      ____              _
|  \/  | _____   _(_) ___  |_   _(_) ___| | _____| |_   | __ )  ___   ___ | | _(_)_ __   __ _     
| |\/| |/ _ \ \ / / |/ _ \   | | | |/ __| |/ / _ \ __|  |  _ \ / _ \ / _ \| |/ / | '_ \ / _` |                
| |  | | (_) \ V /| |  __/   | | | | (__|   <  __/ |_   | |_) | (_) | (_) |   <| | | | | (_| |                
|_|__|_|\___/ \_/ |_|\___|   |_| |_|\___|_|\_\___|\__|  |____/ \___/ \___/|_|\_\_|_| |_|\__, |                
                                                                                        |___/                 
)" << endl;
    setColor(15);

    int choice;
    do {
        cout << endl;
        setColor(10); cout << "Main Menu\n"; setColor(15);
        cout << "1. "; setColor(9); cout << "Register a new user\n";
        setColor(15); cout << "2. "; setColor(9); cout << "Login\n";
        setColor(15); cout << "3. "; setColor(12); cout << "Exit CinemaBooking\n\n";
        setColor(15);

        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1:
            User::registerUser();
            break;
        case 2: {
            string username;
            if (User::loginUser(username)) {
                Dashboard::show(username);
            }
            break;
        }
        case 3:
            setColor(12);
            cout << "Exiting program.\n";
            setColor(15);
            break;
        default:
            setColor(4);
            cout << "Invalid choice. Please try again.\n";
            setColor(15);
        }
    } while (choice != 3);

    return 0;
}
