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
        cout << "1. Cinema City Mall of Sofia\n";
        cout << "2. Arena Mladost\n";
        cout << "3. Odeon Cinema\n";
    }
    else if (city == "Plovdiv") {
        cout << "1. Cinema City Plovdiv\n";
        cout << "2. Lucky Cinema House\n";
    }
    else if (city == "Burgas") {
        cout << "1. Cinema City Burgas Plaza\n";
        cout << "2. Bulgaria Mall Cinema\n";
    }
    else {
        cout << "No information available for this city.\n";
    }
}