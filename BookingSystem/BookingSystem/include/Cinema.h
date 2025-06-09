#ifndef CINEMA_H
#define CINEMA_H

#include <string>
using namespace std;

class Cinema {
public:
    static void chooseCity();
    static void listCinemas(const string& city);
};

#endif
