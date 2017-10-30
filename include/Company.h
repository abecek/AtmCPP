#include <iostream>
#include <map>
#include "Address.h"

#ifndef COMPANY_H
#define COMPANY_H

class Account{
    public:
        std::string getAccountNumber();
        Account setAccountNumber(std::string number);
        float getMoneyAmount();
        void setMoneyAmount(float amount);
    private:
        std::string accountNumber;
        float moneyAmount;
};

class Company
{
    public:
        Company();
        Company(std::string name, Address address);
        std::string toString();
        void addAccount(Account *account);
        Account getAccount(std::string accountNumber);
        std::map<std::string, Account> getAccountsList();


        virtual ~Company();
    protected:
    private:
        std::string name;
        Address address;
        bool isBank = true;
        std::map<std::string, Account> accountsList;
};

#endif // COMPANY_H
