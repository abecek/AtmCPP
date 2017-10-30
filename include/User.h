#include <iostream>
#include "Address.h"

#ifndef USER_H
#define USER_H

class User
{
    public:
        User();
        std::string toString();
        virtual ~User();
    protected:
        std::string name1, name2, surname;
        Address address;
    private:
};

#endif // USER_H
