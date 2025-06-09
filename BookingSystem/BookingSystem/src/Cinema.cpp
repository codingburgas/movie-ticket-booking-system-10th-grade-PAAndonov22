#include "../include/Cinema.h"
#include <iostream>
#include <windows.h>
#include <iomanip>

using namespace std;

extern void setColor(int color);

void printCentered(const string& text) {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int consoleWidth = 80;

    if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi)) {
        consoleWidth = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    }

    int len = text.length();
    int pos = max((consoleWidth - len) / 2, 0);

    for (int i = 0; i < pos; ++i) cout << ' ';
    cout << text << endl;
}

void Cinema::chooseCity() {
    int choice;
    system("cls");
    setColor(11);
    printCentered("========================================");
    printCentered("           CINEMA BOOKING SYSTEM         ");
    printCentered("========================================\n");
    setColor(15);

    setColor(14);
    printCentered("Available Cities:\n");
    setColor(15);

    printCentered("1. Sofia");
    printCentered("2. Plovdiv");
    printCentered("3. Burgas");
    cout << endl;
    printCentered("Enter your choice (1-3): ");
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
        setColor(12); printCentered("Invalid choice. Please try again.\n"); setColor(15);
        break;
    }
}

void Cinema::listCinemas(const string& city) {
    system("cls");
    setColor(10);
    printCentered("========================================");
    printCentered("         Cinemas in " + city + "           ");
    printCentered("========================================\n");
    setColor(15);

    if (city == "Sofia") {
        printCentered("1. Cinema City Mall of Sofia");
        printCentered("2. Arena Mladost");
        printCentered("3. Odeon Cinema");
    }
    else if (city == "Plovdiv") {
        printCentered("1. Cinema City Plovdiv");
        printCentered("2. Lucky Cinema House");
    }
    else if (city == "Burgas") {
        printCentered("1. Cinema City Burgas Plaza");
        printCentered("2. Bulgaria Mall Cinema");
    }
    else {
        printCentered("No information available for this city.");
    }
}
