#include "../include/Cinema.h"
#include <iostream>
#include <windows.h>
#include <iomanip>
#include <vector>
#include <set>
#include <algorithm>

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
    printCentered("╔════════════════════════════════════════════════════╗");
    printCentered("║              CINEMA BOOKING SYSTEM                ║");
    printCentered("╚════════════════════════════════════════════════════╝\n");
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
    printCentered("╔════════════════════════════════════════════════════╗");
    printCentered("║               CINEMAS IN " + city + "                    ║");
    printCentered("╚════════════════════════════════════════════════════╝\n");
    setColor(15);

    vector<string> cinemas;
    if (city == "Sofia") {
        cinemas = { "Cinema City Mall of Sofia", "Arena Mladost", "Odeon Cinema" };
    }
    else if (city == "Plovdiv") {
        cinemas = { "Cinema City Plovdiv", "Lucky Cinema House" };
    }
    else if (city == "Burgas") {
        cinemas = { "Cinema City Burgas Plaza", "Bulgaria Mall Cinema" };
    }
    else {
        printCentered("No information available for this city.");
        return;
    }

    for (size_t i = 0; i < cinemas.size(); ++i) {
        printCentered(to_string(i + 1) + ". " + cinemas[i]);
    }

    int choice;
    cout << "\nEnter your choice: ";
    cin >> choice;
    cin.ignore();

    if (choice >= 1 && choice <= cinemas.size()) {
        string selectedCinema = cinemas[choice - 1];
        Cinema::selectMovie(city, selectedCinema);
    }
    else {
        setColor(12); printCentered("Invalid choice. Please try again.\n"); setColor(15);
    }
}

void Cinema::selectMovie(const string& city, const string& cinema) {
    system("cls");
    vector<string> movies = {
        "The Matrix", "Inception", "Avatar", "Titanic", "Interstellar",
        "John Wick", "The Dark Knight", "Avengers: Endgame", "Shrek", "The Lion King"
    };

    setColor(11);
    printCentered("╔════════════════════════════════════════════════════╗");
    printCentered("║                SELECT A MOVIE                     ║");
    printCentered("╚════════════════════════════════════════════════════╝\n");
    setColor(15);

    for (size_t i = 0; i < movies.size(); ++i) {
        printCentered(to_string(i + 1) + ". " + movies[i]);
    }

    int choice;
    cout << "\nEnter movie number: ";
    cin >> choice;
    cin.ignore();

    if (choice >= 1 && choice <= movies.size()) {
        string selectedMovie = movies[choice - 1];
        selectSeat(city, cinema, selectedMovie);
    }
    else {
        setColor(12); printCentered("Invalid movie choice.\n"); setColor(15);
    }
}

void Cinema::selectSeat(const string& city, const string& cinema, const string& movie) {
    system("cls");
    const int rows = 5;
    const int cols = 10;
    char rowLabels[] = { 'A', 'B', 'C', 'D', 'E' };

    string filename = "bookings_" + city + "_" + cinema + "_" + movie + ".txt";
    replace(filename.begin(), filename.end(), ' ', '_');

    set<string> takenSeats;
    ifstream infile(filename);
    string seat;
    while (infile >> seat) {
        takenSeats.insert(seat);
    }
    infile.close();

    printCentered("\nAvailable Seats (Green = Available, Red = Taken):\n");
    
    for (int i = 0; i < rows; ++i) {
        string line;
        for (int j = 1; j <= cols; ++j) {
            seat = rowLabels[i] + to_string(j);
            if (takenSeats.count(seat)) {
                setColor(12); // red
            }
            else {
                setColor(10); // green
            }
            cout << setw(4) << seat;
            setColor(15);
        }
        cout << endl;
    }

    cout << "\nEnter seat (e.g. B4): ";
    string selectedSeat;
    getline(cin, selectedSeat);

    if (takenSeats.count(selectedSeat)) {
        setColor(12);
        printCentered("\nSeat is already taken!\n");
        setColor(15);
    }
    else {
        ofstream outfile(filename, ios::app);
        if (outfile.is_open()) {
            outfile << selectedSeat << endl;
            outfile.close();
            setColor(10); printCentered("\nSeat successfully booked!\n"); setColor(15);
        }
        else {
            setColor(12); printCentered("\nFailed to book seat.\n"); setColor(15);
        }
    }
}
