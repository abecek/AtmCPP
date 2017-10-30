#include "Company.h"

Company::Company(){
    //ctor
}

Company::Company(std::string name, Address address): name(name), address(address)
{
    /*
    this->name = name;
    this->address = address;
    */
}

std::string Company::toString()
{
    std::string output = "";
    output += " Company - Name: " + name + ", isBank: ";
    output += (isBank == true) ? "true" : "false";
    output += ", address: ( " + address.toString() + " )";

    return output;
}

Company::~Company()
{
    //dtor
}
