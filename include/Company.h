#include <iostream>
#include "Address.h"

#ifndef COMPANY_H
#define COMPANY_H


class Company
{
    public:
        Company();
        Company(std::string name, Address address);
        std::string toString();
        virtual ~Company();
    protected:
    private:
        std::string name;
        Address address;
        bool isBank = true;
};

#endif // COMPANY_H
