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

    Address *UserAddress1 = new Address("Polska", "Zgierz", "Losowa", "123");
    //User *Client1 = new User("Piotr", "Kowalski");
    //cout << Client1->toString();

    User *Client1 = new User("Piotr", "Kowalski", "", UserAddress1);
    /*
    User *Client2 = new User("Rafal", "Wszedobylski");
    User *Client3 = new User("Marcin", "JakisTam");
    */

    Address ClientBankAddress("Polska", "Warszawa", "Aleje Jerozolimskie", "253");
    Company *ClientBank = new Company("ZYX BigBank", ClientBankAddress);
    Account * acc1 = ClientBank->createNewAccount(1100.5);
    Card *card1 = acc1->generateCardForAccount(Client1, ClientBank->getCompanyId(), "1", acc1->getAccountNumber(), cardType::credit);
    ClientBank->printAccountsList();

    /*
    Account * acc2 = ClientBank->createNewAccount(560);
    Account * acc3 = ClientBank->createNewAccount(110);
    Company *ClientBank2 = new Company("ZYX BigBank", ClientBankAddress);
    Account * acc4 = ClientBank2->createNewAccount(350);


    Card *card2 = acc2->generateCardForAccount(Client2, ClientBank->getCompanyId(), "2", acc2->getAccountNumber(), cardType::debit);
    Card *card3 = acc3->generateCardForAccount(Client3, ClientBank->getCompanyId(), "3", acc3->getAccountNumber(), cardType::payment);

    Card *card4 = acc4->generateCardForAccount(Client2, ClientBank2->getCompanyId(), "10", acc4->getAccountNumber(), cardType::debit);

    ClientBank2->printAccountsList();
    */

    cout << endl << "Witamy w bankomacie." << endl << endl;
    CashMachine->loadCard(card1);
    //cout << CashMachine->getCard()->toString();

    if(CashMachine->isCardLoaded()) {
        char c;
        while(c != ESCAPE) {
            Language chosenLang;
            unsigned int x = 0;
            string plainPIN;
            do{
                cout << endl << "Wybierz jezyk:" << endl;
                for(unsigned int i = 0; i < possibleLangs.size(); i++){
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

                cout << "Wprowadz PIN: ";
                cin >> plainPIN;
                CashMachine->loadPlainPIN(plainPIN);


            }while(x < 1 || x > possibleLangs.size());

            cout << endl << endl << "Nacisnij ESC, by przerwac lub inny przycisk, by kontynuowac." << endl;
            c = getch();
        }
    }
    else {
        cout << "Wloz karte do bankomatu." << endl;
    }



    return 0;
}
