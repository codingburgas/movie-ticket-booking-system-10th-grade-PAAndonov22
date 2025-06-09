#ifndef USER_H
#define USER_H

#include <string>
using namespace std;

class User {
public:
    static void registerUser();
    static bool loginUser(string& username);
};

#endif
