#ifndef CINEMA_H
#define CINEMA_H

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

class Cinema {
public:
    static void chooseCity();
    static void listCinemas(const string& city);
    static void selectMovie(const std::string& city, const std::string& cinema);
    static void selectSeat(const std::string& city, const std::string& cinema, const std::string& movie);
    static void selectPaymentMethod(const string& city, const string& cinema, const string& movieWithDate, const string& seat);
};

string generateBookingCode(int length = 8);

#endif
