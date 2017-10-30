#include <iostream>
#include <conio.h>
#include <vector>

#include "Atm.h"
#include "Company.h"
#include "Card.h"
#include "User.h"

using namespace std;

const int ESCAPE=27;

int main()
{
    Address BankAddress("Polska", "Lodz", "Pilsudskiego", "6");
    BankAddress.setPostCode("90-200");

    Company *AtmOwner = new Company("XYZ Bank", BankAddress);

    Address *AtmAddress = new Address("Polska", "Lodz", "Piotrkowska", "43");
    AtmAddress->setPostCode("90-265");

    //Creating Atm for tests
    Atm *CashMachine = new Atm();
    CashMachine->setId(1);
    CashMachine->setLocalization(AtmAddress);
    CashMachine->setOwner(AtmOwner);
    //CashMachine->printAtm();
    //cout << AtmAddress->toString() << endl << endl;
    //cout << AtmOwner->toString() << endl << endl;

    vector<Language> possibleLangs = CashMachine->getLanguageList();

    char c;
    while(c != ESCAPE){
        cout << "Witamy w bankomacie." << endl << endl;

        Language chosenLang;
        unsigned int x = 0;
        do{
            cout << "Wybierz jezyk:" << endl;
            for(int i = 0; i < possibleLangs.size(); i++){
                cout << i+1 << ". - " << possibleLangs.at(i).name << endl;
            }
            cout << endl << "Numer: ";
            cin >> x;
            if(x < 1 || x > possibleLangs.size()){
                cout << endl << "Zle dane" << endl;
                continue;
            }

            chosenLang = possibleLangs.at(x-1);
            CashMachine->setLanguage(chosenLang);
            cout << endl << "Wybrano jezyk: " << CashMachine->getLanguage().name << endl;

        }while(x < 1 || x > possibleLangs.size());

        cout << endl << endl << "Nacisnij ESC, by przerwac lub inny przycisk, by kontynuowac." << endl;
        c = getch();
    }

    return 0;
}
