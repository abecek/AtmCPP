#include <iostream>
#include <string>

#include "User.h"
#include "Company.h"
#include "Hashed.h"

#ifndef CARD_H
#define CARD_H

enum cardType{
    credit,
    debit,
    payment,
};

class Card
{
    public:
        Card();
        Card(User *cardOwner, Company *cardDist, std::string cardNr, std::string plainPIN, float currentMoneyAmount, cardType type);

        User *getCardOwner();
        Company *getCardDistributor();
        std::string getCardNumber();

        Hashed *getHashedPIN();
        //void setIsAuthenticated(bool flag);
        bool getIsAuthenticated();
        void setIsBlocked(bool flag);
        bool getIsBlocked();
        void setCardType(cardType type);
        cardType getCardType();

        std::string toString();
        virtual ~Card();
    protected:
    private:
        User *cardOwner;
        Company *cardDistributor;
        std::string cardNumber;
        Hashed *PIN = nullptr;
        float currentMoneyAmount = 0;
        bool isAuthenticated = false;
        bool isBlocked = false;;
        cardType type;


};

#endif // CARD_H
