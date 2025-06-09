#ifndef USER_H
#define USER_H
#include <string>
using namespace std;

class User {
private:
    string username;
    string email;
    string password;

public:
    User();
    User(string username, string email, string password);
    string getUsername() const;
    bool registerUser();
    static User loginUser();
};

#endif