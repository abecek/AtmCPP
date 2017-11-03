#include "AtmSafe.h"

AtmSafe::AtmSafe()
{
    //ctor
}

AtmSafe::AtmSafe(std::map<unsigned int, unsigned int> safeContent, std::string currency)
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

void AtmSafe::addContent(std::map<unsigned int,unsigned int> *contentToAdd)
{
    auto it = this->content.begin();
    auto it2 = contentToAdd->begin();
    for(;it != this->content.end();) {
        it->second += it2->second;
        it++;
        it2++;
    }

    this->countContent();
}

int AtmSafe::countContent()
{
    unsigned int temp = 0;
    for (std::map<int, int>::iterator i = this->content.begin(); i != this->content.end(); i++) {
        temp += (i->second * i->first);
    }
    this->moneyAmount = temp;
    this->getMedian();
    return this->moneyAmount;
}

float AtmSafe::getMedian()
{
    std::vector<unsigned int> temp;

    auto it = this->content.begin();
    for(;it != this->content.end();) {
        temp.push_back(it->second);
        it++;
    }

    size_t size = temp.size();
    std::sort(temp.begin(), temp.end());

    if (size  % 2 == 0) {
        this->median = (temp[size / 2 - 1] + temp[size / 2]) / 2;
    }
    else {
        this->median = temp[size / 2];
    }

    return this->median;
}

bool AtmSafe::checkAmountIsPossibleToWithdraw(unsigned int amount)
{
    if(amount % this->content[0] != 0) return false;

    return true;
}

bool AtmSafe::getMoneyFromSafe(std::map<unsigned int, unsigned int> money)
{
    return true;
}

bool AtmSafe::getMoneyFromSafe(unsigned int amount)
{
   std::map<unsigned int, unsigned int> tempArray = {
                                    {20, 0},
                                    {50, 0},
                                    {100, 0},
                                    {200, 0},
                                    {500, 0},
                                };
    auto it = tempArray.end();
    do{
        it--;
        unsigned int tempAmount = amount;
        std::map<unsigned int, unsigned int> temp;

        auto it2 = it;
        do{

            int tempDiv = floor(tempAmount / it2->first);
            std::cout << tempDiv << " = " << tempAmount << " / " << it2->first << std::endl;
            if(tempDiv >= 1) {
                temp[it2->first] = tempDiv;
                tempAmount -= tempDiv*it2->first;
            }
            if(it2 == tempArray.begin()) break;
            it2--;
        }while(true);

        this->printAnyContent(temp);

        if(it == tempArray.begin()) break;
    }while(true);

    return true;
}

void AtmSafe::printSafe()
{
    std::cout << "Atmsafe - moneyAmount: " << this->getMoneyAmount() << std::endl;
    auto it = this->content.begin();
    for(int i = 0; it != this->content.end(); i++) {
        std::cout << it->first << " - " << it->second << std::endl;
        it++;
    }
}

void AtmSafe::printAnyContent(std::map<unsigned int, unsigned int> &temp)
{
    std::cout << std::endl;
    auto it = temp.begin();
    for(; it != temp.end();) {
        std::cout << it->first << " - " << it->second << std::endl;
        it++;
    }
}

AtmSafe::~AtmSafe()
{
    //dtor
}
