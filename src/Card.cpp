#include "Card.h"


Card::Card()
{
    //ctor
}
Card::Card(User *cardOwner, Company *cardDist, std::string cardNr, std::string plainPIN, float currentMoneyAmount, cardType type):
    cardOwner(cardOwner),
    cardDistributor(cardDist),
    cardNumber(cardNr),
    currentMoneyAmount(currentMoneyAmount),
    type(type)
{

}

User *Card::getCardOwner()
{
    return cardOwner;
}

Company *Card::getCardDistributor()
{
    return cardDistributor;
}

std::string Card::getCardNumber()
{
    return cardNumber;
}

Hashed *Card::getHashedPIN()
{
    return this->PIN;
}

bool Card::getIsAuthenticated()
{
    return isAuthenticated;
}

void Card::setIsBlocked(bool flag)
{

}

bool Card::getIsBlocked()
{
    return isBlocked;
}

void Card::setCardType(cardType type)
{

}

cardType Card::getCardType()
{
    return type;
}

Card::~Card()
{
    //dtor
}

std::string Card::toString()
{
    std::string output = "";
    output += " Card - CardNumber: " + cardNumber + "\n, currentState: " + "\n, isAuthenticated: ";
    output += (isAuthenticated == true) ? "true" : "false";
    output += "\n, isBlocked: ";
    output += (isBlocked == true) ? "true" : "false";

    // todo: have to change switch to if because for example "cardType::credit:" wont be working
    switch(this->type){
        credit:
            output += ", cardType: credit";
            break;
        debit:
            output += ", cardType: debit";
            break;
        payment:
            output += ", cardType: payment";
            break;
    }
    if(cardOwner != nullptr) {
        output += "\n User - ( " + cardOwner->toString() + " )";
    }
    if(cardDistributor != nullptr) {
        output += "\n Bank - ( " + cardDistributor->toString() + " )";
    }


    return output;
}
