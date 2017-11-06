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
    vector<Language> possibleLangs = CashMachine->getLanguageList();
    //CashMachine->printAtm();
    //cout << AtmAddress->toString() << endl << endl;
    //cout << AtmOwner->toString() << endl << endl;


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

    Company *ClientBank2 = new Company("ZYX BigBank", ClientBankAddress);
    string accNumber4  = ClientBank2->createNewAccount(350);

    vector<Card*> cardsList;
    // todo: Add autogenerating cardNumber when creating card for the account and move CardOwner into Account class
    Card *card1 = ClientBank->generateCardForAccount(Client1, "1", accNumber1, cardType::credit);
    cardsList.push_back(card1);
    Card *card2 = ClientBank->generateCardForAccount(Client2, "2", accNumber2, cardType::credit);
    cardsList.push_back(card2);
    Card *card3 = ClientBank->generateCardForAccount(Client3, "3", accNumber3, cardType::payment);
    cardsList.push_back(card3);

    Card *card4 = ClientBank2->generateCardForAccount(Client4, "11", accNumber4, cardType::debit);
    cardsList.push_back(card4);

    CashMachine->addSupportedCompanyToList(ClientBank2);


    std::map<unsigned int,unsigned int> safeContent = {
                                    {20, 5},
                                    {50, 12},
                                    {100, 11},
                                    {200, 7},
                                    {500, 4},
                            };

    CashMachine->addToSafe(&safeContent);
    //cout << endl << CashMachine->getSafe()->getMedian() << endl;

    cout << endl << "Witamy w bankomacie." << endl;

    char c1;
    do{
        cout << endl;
        ClientBank->printAccountsList();
        ClientBank2->printAccountsList();
        CashMachine->getSafe()->printSafe();

        unsigned int chosenCardId;
        cout << endl << "Lista mozliwych kart: " << endl;
        for(int i = 0; i < cardsList.size(); i++) {
            cout << "Id: " << i+1 << " - AccNumber: " << cardsList.at(i)->getAccountNumber() << endl;
        }
        cout << "Wloz karte id: ";
        cin >> chosenCardId;
        try{
            CashMachine->loadCard(cardsList.at(chosenCardId-1));
            //cout << CashMachine->getCard()->toString();
        }
        catch(const std::out_of_range &err) {
            cout << "Bledne id karty." << endl;
        }

        if(CashMachine->isCardLoaded()) {
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
                        cout << endl << "Otrzymano dostep do konta!" << endl << endl;

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
                                //cout << "Wyplata : " << moneyToWithdraw << " z mozliwych: " << CashMachine->getAvailableMoney();
                                char c3 = '1';
                                /*
                                do{
                                    cout << endl << "Czy chcesz wydrukowac potwierdzenie wyplaty?" << endl;
                                    cout << "1 - Tak" << endl << "2 - Nie" << endl;
                                    cin >> c3;
                                } while(!(c3 == '1' || c3 == '2'));
                                */

                                bool howItWent;
                                if(c3 == '1') {
                                    howItWent = CashMachine->makeWithdraw((float)moneyToWithdraw, true);
                                }
                                else {
                                    howItWent = CashMachine->makeWithdraw((float)moneyToWithdraw, false);
                                }

                                if(howItWent) {
                                    cout << endl <<  "------------------------------------" << endl;
                                    cout << "Wyplacono: " << moneyToWithdraw << " z konta, przy uzyciu karty." << endl;
                                    cout << "------------------------------------" << endl << endl;
                                }


                                ClientBank->printAccountsList();
                                ClientBank2->printAccountsList();

                            }
                            else {
                                cout << "Brak wystarczajacych srodkow na koncie." << endl;
                                continue;
                            }

                    }
                }while(x < 1 || x > possibleLangs.size());


                cout << endl << endl << "Nacisnij ESC, by wysunac karte lub inny przycisk, by kontynuowac." << endl;
                c1 = getch();
            }

            c1 = 55;
        }
        else {
            cout << "Wloz karte do bankomatu." << endl;
        }

        cout << endl << endl << "Nacisnij ESC, by przerwac prace programu lub inny przycisk, by kontynuowac." << endl;
        c1 = getch();
    }while(c1 != ESCAPE);


    return 0;
}
