#include "Company.h"

std::string Account::getAccountNumber(){
    return this->accountNumber;
}

Account Account::setAccountNumber(std::string number){
    this->accountNumber = number;
    return *this;
}

float Account::getMoneyAmount(){
    return this->moneyAmount;
}

void Account::setMoneyAmount(float amount)
{
    this->moneyAmount = amount;
}


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
