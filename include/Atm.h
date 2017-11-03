#include <iostream>
#include <vector>
#include <string>
#include <map>

#include "AtmSafe.h"
#include "Address.h"
#include "Company.h"
#include "Card.h"

#include "User.h"

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

        void addToSafe(std::map<unsigned int, unsigned int> *safeContent);
        AtmSafe* getSafe();

        void setLocalization(Address *address);
        Address getLocalization();
        void setOwner(Company *company);
        Company* getOwner();

        void loadCard(Card *card);
        Card *getCard();
        void discardCard();
        void rejectCard();
        bool isCardLoaded();

        bool chooseLanguage(Language lg);
        void loadPlainPIN(std::string PIN);
        bool checkPIN();
        bool getIsAuthorized();

        float getAvailableMoney();
        bool makeWithdraw(unsigned int amount, bool printContribution = false);

        std::vector<Language> getLanguageList();
        Language getLanguage();
        void setLanguage(Language lg);

        void addSupportedCompanyToList(Company *comp);
        //std::map<unsigned int id, *Company> getSupportedCompaniesList();

        void printAtm();

    protected:
        int id;
        std::string plainPin = "";
        bool isOn = true;
        bool isAuthorized = false;
        float availableMoneyAmount = 0;

        std::vector<Language> langList;
        Language lang;

        AtmSafe *safe = nullptr;
        Address *localization = nullptr;
        Company *owner = nullptr;
        Card *card = nullptr;

        std::map<unsigned int, Company*> supportedCompaniesList;

};

#endif // ATM_H
