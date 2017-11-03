#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

#ifndef ATMSAFE_H
#define ATMSAFE_H

#define SSTR( x ) static_cast< std::ostringstream & >( \
        ( std::ostringstream() << std::dec << x ) ).str()

class AtmSafe
{
    public:
        AtmSafe();
        AtmSafe(std::map<unsigned int, unsigned int> safeContent, std::string currency = "PLN");

        unsigned int getMoneyAmount();
        std::string getCurrency();
        void addContent(std::map<unsigned int,unsigned int> *content);
        int countContent();
        float getMedian();

        bool checkAmountIsPossibleToWithdraw(unsigned int amount);
        bool getMoneyFromSafe(std::map<unsigned int,unsigned int> money);
        bool getMoneyFromSafe(unsigned int amount);

        void printSafe();
        void printAnyContent(std::map<unsigned int, unsigned int> &temp);

        virtual ~AtmSafe();
    protected:

    private:
        std::string currency = "PLN";
        unsigned int moneyAmount = 0;

        float median = 0;
        std::map<int, int> content = {
            {20, 0},
            {50, 0},
            {100, 0},
            {200, 0},
            {500, 0},
        };

};

#endif // ATMSAFE_H
