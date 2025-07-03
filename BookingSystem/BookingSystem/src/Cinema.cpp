#define _CRT_SECURE_NO_WARNINGS

#include "../include/Cinema.h"
#include <iostream>
#include <windows.h>
#include <iomanip>
#include <fstream>
#include <vector>
#include <set>
#include <algorithm>
#include <ctime>
#include <random>
#include <string>


using namespace std;

extern void setColor(int color);
void printReceipt(const string& city, const string& cinema, const string& movieWithDate,
    const string& seat, const string& paymentMethod, const string& bookingCode);

string generateBookingCode(int length) {
    const string chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    string code;
    default_random_engine rng(static_cast<unsigned>(time(0)));
    uniform_int_distribution<> dist(0, chars.size() - 1);
    for (int i = 0; i < length; ++i) {
        code += chars[dist(rng)];
    }
    return code;
}

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
    printCentered(" =====================================================");
    printCentered("|              CINEMA BOOKING SYSTEM                  |");
    printCentered(" =====================================================\n");
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
    printCentered(" =======================================================");
    printCentered("|               CINEMAS IN " + city + "                      |");
    printCentered(" =======================================================\n");
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
    vector<string> allMovies = {
        "The Eternal City", "Echoes of Tomorrow", "Starfall", "The Hollow Crown",
        "Neon Skies", "Red Winter", "The Forgotten Path", "Shadows of Orion",
        "Parallel Minds", "Crimson Moon", "Dreamweaver", "Last Horizon",
        "Velocity Run", "The Glass Labyrinth", "Dawn Protocol", "Solstice",
        "Midnight Cargo", "Celestial Drift", "Carbon Unit", "Blackout Code",
        "Descent Point", "ChronoVault", "Fractured Light", "The Archivist",
        "Twilight Order", "Digital Eden", "The Mirage Loop", "Silent Radio",
        "Quantum Abyss", "Project Anomaly", "Hunter Sector", "Neural Divide",
        "Obsidian Signal", "Storm Complex", "Cosmic Static", "Echo Run",
        "Neptune's Wake", "Infinite Bloom", "Orbit Break", "Nova Shard"
    };

    shuffle(allMovies.begin(), allMovies.end(), default_random_engine(time(0)));
    vector<string> selectedMovies(allMovies.begin(), allMovies.begin() + 8);

    setColor(11);
    printCentered(" =====================================================");
    printCentered("|                  SELECT A MOVIE                     |");
    printCentered(" =====================================================\n");
    setColor(15);

    for (size_t i = 0; i < selectedMovies.size(); ++i) {
        printCentered(to_string(i + 1) + ". " + selectedMovies[i]);
    }

    int movieChoice;
    cout << "\nEnter movie number: ";
    cin >> movieChoice;
    cin.ignore();

    if (movieChoice >= 1 && movieChoice <= selectedMovies.size()) {
        string selectedMovie = selectedMovies[movieChoice - 1];

        // Sample showtimes
        vector<string> showtimes = {
            "2025-07-04 14:00",
            "2025-07-04 17:00",
            "2025-07-04 20:00",
            "2025-07-05 14:00",
            "2025-07-05 17:00"
        };

        system("cls");
        setColor(11);
        printCentered(" =====================================================");
        printCentered("|                SELECT DATE & TIME                  |");
        printCentered(" =====================================================\n");
        setColor(15);

        for (size_t i = 0; i < showtimes.size(); ++i) {
            printCentered(to_string(i + 1) + ". " + showtimes[i]);
        }

        int timeChoice;
        cout << "\nEnter choice for showtime: ";
        cin >> timeChoice;
        cin.ignore();

        if (timeChoice >= 1 && timeChoice <= showtimes.size()) {
            string selectedDateTime = showtimes[timeChoice - 1];
            selectSeat(city, cinema, selectedMovie + "_" + selectedDateTime); // pass movie+datetime as identifier
        }
        else {
            setColor(12); printCentered("Invalid showtime choice.\n"); setColor(15);
        }

    }
    else {
        setColor(12); printCentered("Invalid movie choice.\n"); setColor(15);
    }
}

void Cinema::selectSeat(const string& city, const string& cinema, const string& movieWithDate) {
    system("cls");
    const int rows = 5;
    const int cols = 10;
    char rowLabels[] = { 'A', 'B', 'C', 'D', 'E' };

    string filename = "bookings_" + city + "_" + cinema + "_" + movieWithDate + ".txt";
    replace(filename.begin(), filename.end(), ' ', '_');
    replace(filename.begin(), filename.end(), ':', '-');

    set<string> takenSeats;
    ifstream infile(filename);
    string seat;
    while (infile >> seat) {
        takenSeats.insert(seat);
    }
    infile.close();

    setColor(11);
    printCentered("=======================================================");
    printCentered("|                SELECT A SEAT                        |");
    printCentered("=======================================================\n");
    setColor(14);
    printCentered("Movie: " + movieWithDate);
    setColor(15);

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
            Cinema::selectPaymentMethod(city, cinema, movieWithDate, selectedSeat);
        }
        else {
            setColor(12); printCentered("\nFailed to book seat.\n"); setColor(15);
        }
    }
}
void Cinema::selectPaymentMethod(const string& city, const string& cinema, const string& movieWithDate, const string& seat) {
    setColor(11);
    printCentered("\nSelect Payment Method:");
    setColor(15);
    printCentered("1. Pay Online");
    printCentered("2. Pay at Cinema");
    cout << "\nEnter choice: ";

    int choice;
    cin >> choice;
    cin.ignore();

    string paymentMethod;
    string bookingCode = generateBookingCode(); // ✅ Define bookingCode here

    string filename = "payments_" + city + "_" + cinema + "_" + movieWithDate + ".txt";
    replace(filename.begin(), filename.end(), ' ', '_');
    replace(filename.begin(), filename.end(), ':', '-');

    ofstream paymentFile(filename, ios::app);

    switch (choice) {
    case 1:
        setColor(10);
        printCentered("\nRedirecting to online payment...");
        printCentered("Payment successful!");
        paymentMethod = "Online";
        break;

    case 2:
        setColor(14);
        printCentered("\nYou chose to pay at the cinema.");
        paymentMethod = "Pay at Cinema";
        break;

    default:
        setColor(12);
        printCentered("Invalid choice. Defaulting to 'Pay at cinema'.");
        paymentMethod = "Pay at Cinema";
        break;
    }

    if (paymentFile.is_open()) {
        paymentFile << seat << " - " << paymentMethod << " - Code: " << bookingCode << "\n";
        paymentFile.close();
    }

    setColor(15);

    printReceipt(city, cinema, movieWithDate, seat, paymentMethod, bookingCode);
}

void printReceipt(const string& city, const string& cinema, const string& movieWithDate,
    const string& seat, const string& paymentMethod, const string& bookingCode) {
    system("cls");
    time_t now = time(0);
    char* dt = ctime(&now);
    string bookingDate = string(dt);
    bookingDate.pop_back();

    setColor(11);
    printCentered(" ===================================================== ");
    printCentered("|                  BOOKING RECEIPT                    |");
    printCentered(" ===================================================== ");
    setColor(15);
    cout << endl;

    printCentered("Cinema: " + cinema + " (" + city + ")");
    printCentered("Movie: " + movieWithDate.substr(0, movieWithDate.find('_')));
    printCentered("Showtime: " + movieWithDate.substr(movieWithDate.find('_') + 1));
    printCentered("Seat: " + seat);
    printCentered("Payment Method: " + paymentMethod);
    printCentered("Booking Date: " + bookingDate);
    printCentered("Booking Code: " + bookingCode);

    cout << endl;
    setColor(10);
    printCentered("Thank you for your booking! Enjoy your movie!");
    setColor(15);
    cout << endl;
    system("pause");
}