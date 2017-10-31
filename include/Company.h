#include <iostream>
#include <sstream>
#include <map>

#include "Address.h"
#include "Card.h"

#ifndef COMPANY_H
#define COMPANY_H

#define SSTR( x ) static_cast< std::ostringstream & >( \
        ( std::ostringstream() << std::dec << x ) ).str()

class Account{
            public:
                Account();
                Account(unsigned int id, std::string pin = "");

                static unsigned int pinLength;

                std::string getAccountNumber();
                Account setAccountNumber(std::string number);
                float getMoneyAmount();
                void setMoneyAmount(float amount);
                unsigned int getAccountId();
                std::string getCardPIN();

                Card *generateCardForAccount(User *cardOwner, unsigned int cardDistId, std::string cardNr, std::string accountNr, cardType type);
                Card *getCard();
            private:
                unsigned int accountId;
                std::string accountNumber;
                std::string cardPIN;
                float moneyAmount = 0;
                Card *card;
        };

class Company
{
    private:
        unsigned int accountsCount = 0;
        unsigned int companyId;

        static unsigned int banksCount;

        std::string IBAN = "PL";
        std::string name;
        Address address;
        bool isBank = true;
        std::map<std::string, Account> accountsList;

    public:
        static std::string generateRandomPIN(unsigned int length);
        Company();
        Company(std::string name, Address address);
        std::string toString();

        unsigned int getCompanyId();

        Account* createNewAccount(float moneyAmount = 0);
        void addAccount(Account *account);
        Account getAccount(std::string accountNumber);
        std::map<std::string, Account> getAccountsList();

        std::string getAccountsAsString();
        void printAccountsList();
        unsigned int getAccountsCount();

        virtual ~Company();

};

#endif // COMPANY_H
