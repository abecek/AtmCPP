#include "User.h"

User::User()
{
    //ctor
}

std::string User::toString()
{
    std::string output = "";

    output += " User - , name1: " + name1 + ", name2: " + name2;
    output += ", surname: " + surname;
    output += ", address: " + address.toString();

    return output;
}

User::~User()
{
    //dtor
}
