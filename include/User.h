#include <iostream>
#include "Address.h"

#ifndef USER_H
#define USER_H

class User
{
    public:
        User();
        User(std::string name1, std::string surname, std::string name2 = "", Address *address = nullptr);
        std::string toString();
        virtual ~User();
    protected:
        std::string name1, name2, surname;
        Address *address;
    private:
};

#endif // USER_H
