#include "../include/Dashboard.h"
#include "../include/Cinema.h"
#include <iostream>
#include <windows.h>

using namespace std;

extern void setColor(int color);

void Dashboard::show(const string& username) {
    int choice;
    setColor(11);
    system("cls");
    cout << R"(
 ____            _     _                         _ 
|  _ \  __ _ ___| |__ | |__   ___   __ _ _ __ __| |
| | | |/ _` / __| '_ \| '_ \ / _ \ / _` | '__/ _` |
| |_| | (_| \__ \ | | | |_) | (_) | (_| | | | (_| |
|____/ \__,_|___/_| |_|_.__/ \___/ \__,_|_|  \__,_|
)" << endl;
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
