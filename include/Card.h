#include <iostream>
#include <string>
#include <sstream>

#include "User.h"

#ifndef CARD_H
#define CARD_H

#define SSTR( x ) static_cast< std::ostringstream & >( \
        ( std::ostringstream() << std::dec << x ) ).str()

enum cardType{
    credit,
    debit,
    payment,
};

class Card
{
    public:
        Card();
        Card(User *cardOwner, unsigned int cardDistId, std::string cardNr, std::string accountNr, cardType type);

        User *getCardOwner();
        unsigned int getCardDistributorId();
        std::string getCardNumber();
        std::string getAccountNumber();

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
        unsigned int cardDistributorId;
        std::string cardNumber;
        std::string accountNumber;

        bool isAuthenticated = false;
        bool isBlocked = false;;
        cardType type;


};

#endif // CARD_H
