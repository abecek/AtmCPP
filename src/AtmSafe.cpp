#include "AtmSafe.h"

AtmSafe::AtmSafe()
{
    //ctor
}

AtmSafe::AtmSafe(std::map<int, int> content, std::string currency)
{
    this->content = content;
    this->currency = currency;
}

unsigned int AtmSafe::getMoneyAmount()
{
    return this->moneyAmount;
}

std::string AtmSafe::getCurrency()
{
    return this->currency;
}

void AtmSafe::addContent(std::map<int, int> contentToAdd)
{
    int x = 0;
    for (auto it = content.begin(); it != content.end(); ++it) {
        it->second += contentToAdd.at(x);
        x++;
    }
    this->countContent();
}

int AtmSafe::countContent()
{
    unsigned int temp = 0;
    for (std::map<int, int>::iterator i = this->content.begin(); i != this->content.end(); i++) {
        temp += i->second;
    }
    this->moneyAmount = temp;
    return this->moneyAmount;
}

bool AtmSafe::getMoneyFromSafe(std::map<int, int> money)
{
    return true;
}

bool AtmSafe::getMoneyFromSafe(unsigned int amount)
{
    return true;
}


AtmSafe::~AtmSafe()
{
    //dtor
}
