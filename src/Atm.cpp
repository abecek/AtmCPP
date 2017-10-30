#include "Atm.h"
#include <string>

Atm::Atm()
{
    Language pl;
    pl.name = "polski";
    pl.shortCut = "pl";
    Language eng;
    eng.name = "angielski";
    eng.shortCut = "eng";

    this->langList.push_back(pl);
    this->langList.push_back(eng);
}

std::vector<Language> Atm::getLanguageList()
{
    return this->langList;
}

Language Atm::getLanguage()
{
    return this->lang;
}

void Atm::setLanguage(Language lg)
{
    this->lang = lg;
}

void Atm::setId(int id)
{
    this->id = id;
}

int Atm::getId()
{
    return this->id;
}

void Atm::setLocalization(Address *address)
{

}

Address Atm::getLocalization()
{
    return *this->localization;
}

void Atm::setOwner(Company *company)
{

}

Company* Atm::getOwner()
{
    return this->owner;
}

void Atm::loadCard(Card *card)
{
    this->card = card;
}

Card *Atm::getCard(){
    return this->card;
}

void Atm::discardCard()
{

}

void Atm::rejectCard()
{

}

bool Atm::isCardLoaded()
{
    if(this->card == nullptr){
       return false;
    }
    return true;
}

bool Atm::chooseLanguage(Language lg)
{
    return true;
}

void Atm::loadPlainPIN(std::string PIN)
{
    this->plainPin = PIN;
}

bool Atm::checkPIN(Hashed &hashMachine)
{
    return true;
}

bool Atm::makeWithdraw(unsigned int amount, bool printContribution)
{
    return true;
}

void Atm::printAtm()
{
    std::cout << "ATM - Id: " << id << ", plainPIN in memory: " << plainPin << ", IsOn: ";
    (isOn == true) ? std::cout << " true" << std::endl : std::cout << " false" << std::endl;

    //if(this->localization == nullptr) std::cout << "KLOPS" << std::endl;
    //std::cout << this->localization->toString() << std::endl;
    //std::cout << "Localization: ( " << str << " ) " << std::endl;
    //std::cout << ", Owner: " << owner->toString() << ", " << std::endl;
}

