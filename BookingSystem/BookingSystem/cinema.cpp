#include <iostream>
#include "cinema.h"

void chooseCity() {
    int choice;
    cout << "Choose a city:\n";
    cout << "1. Sofia\n";
    cout << "2. Plovdiv\n";
    cout << "3. Burgas\n";
    cout << "Enter your choice (1-3): ";
    cin >> choice;
    cin.ignore();

    switch (choice) {
    case 1:
        listCinemas("Sofia");
        break;
    case 2:
        listCinemas("Plovdiv");
        break;
    case 3:
        listCinemas("Burgas");
        break;
    default:
        cout << "Invalid choice. Please try again." << endl;
        break;
    }
}

void listCinemas(const string& city) {
    cout << "\nCinemas in " << city << ":\n";

    if (city == "Sofia") {
        cout << "- Cinema City Mall of Sofia\n";
        cout << "- Arena Mladost\n";
        cout << "- Odeon Cinema\n";
    }
    else if (city == "Plovdiv") {
        cout << "- Cinema City Plovdiv\n";
        cout << "- Lucky Cinema House\n";
    }
    else if (city == "Burgas") {
        cout << "- Cinema City Burgas Plaza\n";
        cout << "- Bulgaria Mall Cinema\n";
    }
    else {
        cout << "No information available for this city.\n";
    }
}