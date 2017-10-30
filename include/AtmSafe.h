#include <iostream>
#include <map>

#ifndef ATMSAFE_H
#define ATMSAFE_H


class AtmSafe
{
    public:
        AtmSafe();
        AtmSafe(std::map<int, int> content, std::string currency = "PLN");

        unsigned int getMoneyAmount();
        std::string getCurrency();
        void addContent(std::map<int, int> content);
        int countContent();
        bool getMoneyFromSafe(std::map<int, int> money);
        bool getMoneyFromSafe(unsigned int amount);

        virtual ~AtmSafe();
    protected:

    private:
        std::string currency = "PLN";
        unsigned int moneyAmount = 0;
        std::map<int, int> content = {
            {20, 0},
            {50, 0},
            {100, 0},
            {200, 0},
            {500, 0},
        };
};

#endif // ATMSAFE_H
