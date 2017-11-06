#include <iostream>
#include <conio.h>
#include <vector>
#include <algorithm>

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
    CashMachine->addSupportedCompanyToList(AtmOwner);

    //CashMachine->printAtm();
    //cout << AtmAddress->toString() << endl << endl;
    //cout << AtmOwner->toString() << endl << endl;

    vector<Language> possibleLangs = CashMachine->getLanguageList();

    Address *UserAddress1 = new Address("Polska", "Zgierz", "Losowa", "123");


    User *Client1 = new User("Piotr", "Kowalski", "", UserAddress1);
    User *Client2 = new User("Rafal", "Wszedobylski");
    User *Client3 = new User("Marcin", "JakisTam");
    User *Client4 = new User("Jan", "Zdobywca");

    Address ClientBankAddress("Polska", "Warszawa", "Aleje Jerozolimskie", "253");
    Company *ClientBank = new Company("ZYX BigBank", ClientBankAddress);

    string accNumber1 = ClientBank->createNewAccount(1100.5);

    string accNumber2 = ClientBank->createNewAccount(190);
    string accNumber3 = ClientBank->createNewAccount(11.99);

    CashMachine->addSupportedCompanyToList(ClientBank);
    ClientBank->printAccountsList();

    Company *ClientBank2 = new Company("ZYX BigBank", ClientBankAddress);
    string accNumber4  = ClientBank2->createNewAccount(350);

    // todo: Add autogenerating cardNumber when creating card for the account and move CardOwner into Account class
    Card *card1 = ClientBank->generateCardForAccount(Client1, "1", accNumber1, cardType::credit);

    Card *card2 = ClientBank->generateCardForAccount(Client2, "2", accNumber2, cardType::credit);
    Card *card3 = ClientBank->generateCardForAccount(Client3, "3", accNumber3, cardType::payment);
    Card *card4 = ClientBank2->generateCardForAccount(Client4, "11", accNumber4, cardType::debit);

    CashMachine->addSupportedCompanyToList(ClientBank2);

    ClientBank2->printAccountsList();


    std::map<unsigned int,unsigned int> safeContent = {
                                    {20, 5},
                                    {50, 12},
                                    {100, 11},
                                    {200, 7},
                                    {500, 4},
                            };

    CashMachine->addToSafe(&safeContent);
    CashMachine->getSafe()->printSafe();
    //cout << endl << CashMachine->getSafe()->getMedian() << endl;


    cout << endl << "Witamy w bankomacie." << endl << endl;
    CashMachine->loadCard(card2);
    //cout << CashMachine->getCard()->toString();

    if(CashMachine->isCardLoaded()) {
        char c1;
        while(c1 != ESCAPE) {
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

                int i = 0;
                do{
                    if(i > 0) cout << "Bledny PIN." << endl;
                    cout << "Wprowadz PIN: ";
                    cin >> plainPIN;
                    c1 = *"c";
                    CashMachine->loadPlainPIN(plainPIN);
                    i++;
                }while(!CashMachine->checkPIN());

                if(CashMachine->getIsAuthorized()) {
                    char c2;
                    cout << endl << "Otrzymano dostep do konta!" << endl;
                    cout << "Wybierz czynnosc:" << endl;
                    cout << "1 - Wyplata srodkow" << endl;
                    cout << "2 - Wyplac konkretna kwote" << endl;
                    cout << "3 - Wyjscie" << endl;
                    cin >> c2;

                    vector<unsigned int> amountsTab = {20, 50, 80, 100, 150, 200, 300, 400};
                    unsigned int moneyToWithdraw = 0;
                    unsigned int moneyToWithdrawOption = 9;
                    if(c2 == '1') {

                        bool flag = false;
                        do{
                            cout << "Dostepne kwoty:" << endl;
                            for(unsigned int i = 0; i < ((amountsTab.size())/2); i++) {
                                cout << endl << (i+1) << " - " << amountsTab[i] << "     " << (i+5) << " - " << amountsTab[i+4];
                            }
                            cout << endl;
                            cin >> moneyToWithdrawOption;
                            flag = (moneyToWithdrawOption >= 1 && moneyToWithdrawOption <= 8) ? true : false;
                        }while(!flag);

                        moneyToWithdraw = amountsTab[moneyToWithdrawOption-1];

                    }
                    else if(c2 == '2') {
                        cout << "Wprowadz kwote: " ;
                        cin >> moneyToWithdraw;
                    }
                    else if(c2 == '3') {
                        break;
                    }


                        if((float)moneyToWithdraw <= CashMachine->getAvailableMoney()) {
                            cout << "Wyplata : " << moneyToWithdraw << " z mozliwych: " << CashMachine->getAvailableMoney();
                            char c3;
                            do{
                                cout << endl << "Czy chcesz wydrukowac potwierdzenie wyplaty?" << endl;
                                cout << "1 - Tak" << endl << "2 - Nie" << endl;
                                cin >> c3;
                            } while(!(c3 == '1' || c3 == '2'));


                            if(c3 == '1') {
                                CashMachine->makeWithdraw((float)moneyToWithdraw, true);
                            }
                            else {
                                CashMachine->makeWithdraw((float)moneyToWithdraw, false);
                            }

                        }
                        else {
                            cout << "Brak wystarczajacych srodkow na koncie." << endl;
                            continue;
                        }

                }
            }while(x < 1 || x > possibleLangs.size());


            cout << endl << endl << "Nacisnij ESC, by przerwac lub inny przycisk, by kontynuowac." << endl;
            c1 = getch();
        }
    }
    else {
        cout << "Wloz karte do bankomatu." << endl;
    }



    return 0;
}
