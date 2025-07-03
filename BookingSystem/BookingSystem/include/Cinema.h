#ifndef CINEMA_H
#define CINEMA_H

#include <string>
#include <vector>
#include <fstream>
using namespace std;

class Cinema {
public:
    static void chooseCity();
    static void listCinemas(const string& city);
    static void selectMovie(const std::string& city, const std::string& cinema);
    static void selectSeat(const std::string& city, const std::string& cinema, const std::string& movie);
};

#endif
