#include <iostream>
#include <vector>
#include <string>

#include "Address.h"
#include "Company.h"
#include "Card.h"
#include "User.h"
#include "Hashed.h"

#ifndef ATM_H
#define ATM_H

struct Language{
    std::string shortCut;
    std::string name;
};

class Atm
{
    public:
        Atm();
        void setId(int id);
        int getId();
        void setLocalization(Address *address);
        Address getLocalization();
        void setOwner(Company *company);
        Company* getOwner();

        void loadCard(Card *card);
        void discardCard();
        void rejectCard();
        bool isCardLoaded();

        bool chooseLanguage(Language lg);
        void loadPlainPIN(std::string PIN);
        bool checkPIN(Hashed &hashMachine);

        bool makeWithdraw(unsigned int amount, bool printContribution = false);

        std::vector<Language> getLanguageList();
        Language getLanguage();
        void setLanguage(Language lg);

        void printAtm();

    protected:
        int id;
        std::string plainPin = "";
        bool isOn = true;
        std::vector<Language> langList;
        Language lang;
        Address *localization;
        Company *owner;
        Card *card;
    private:

};

#endif // ATM_H
