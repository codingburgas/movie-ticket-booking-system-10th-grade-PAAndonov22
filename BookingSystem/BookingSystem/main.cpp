#include "Main.h"
#include "UserReg.h"

int main()
{
    cout << "------------------------\n";
    cout << "Welcome to CinemaBooking\n";
    cout << "------------------------\n";

    int choice;
    do {
        cout << "1. Register a new user\n2. Login\n3. Exit CinemaBooking\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1:
            registerUser();
            break;
        case 2:
            break;
        case 3:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 3);
}
