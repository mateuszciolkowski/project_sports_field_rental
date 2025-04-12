//
// Created by Mateusz on 11/06/2024.
//

#include "../include/Menu.h"
#include "typedefs.h"
#include "managers/ClientManager.h"
#include "managers/FieldManager.h"
#include "managers/RentManager.h"
#include "ContactDetails.h"
#include "Client.h"
#include "Rent.h"
#include "tools/Utilities.h"
#include "Field.h"
#include "VolleyballField.h"
#include "BasketballField.h"
#include "RunningTrack.h"
#include "FootballField.h"
#include <stdexcept>
#include "tools/Exception.h"


Menu::Menu() : clientManager(new ClientManager()), fieldManager(new FieldManager()), rentManager(new RentManager()) {

}

Menu::~Menu() {

}

void Menu::cliInterface() {
    std::cout << "Aplikcja obslugi wypozyczen obiektow sportowych.\n";

    unsigned int exit = 1;

    while (exit != 0) {
        std::cout << "\n"
                  << "1-->Zarzadzaj obiektami sportowymi" << std::endl
                  << "2-->Zarzadzaj klientami" << std::endl
                  << "3-->Zarzadzaj wypozyczeniami" << std::endl
                  << "0-->Wyjdz z programu " << std::endl
                  << "\n";
        int action;
        try {
            while (!tools::safeInput(action)) {
                throw InvalidInputException("Podano zla wartosc!");
            }
            switch (action) {
                case 1:
                    field();
                    break;
                case 2:
                    client();
                    break;
                case 3:
                    rent();
                    break;
                case 0:
                    exit = 0;
                    break;
                default:
                    throw InvalidInputException("Podano zla wartosc!");
//                    std::cout << "Podano zla wartosc\n";
//                    break;
            }
        } catch (const Exceptions &e) {
            std::cout << "Error: " << e.what() << std::endl;
        }
    }
}


void Menu::client() {
    std::cout << "Zarzadzanie klientem \n";

    unsigned int exit = 1;

    while (exit != 0) {
        std::cout << "\n"
                  << "1-->Zarejestruj klienta" << std::endl
                  << "2-->Wyrejestruj" << std::endl
                  << "3-->Wyswietl informacje podstawowe o kliencie" << std::endl
                  << "4-->Wyswietl informacje rozszerzone o kliencie" << std::endl
                  << "5-->Wyswietl informacje podstawowe o wszystkich klientach" << std::endl
                  << "6-->Wyswietl informacje rozszerzone o wszystkich klientach" << std::endl
                  << "0-->Wyjdz z do menu" << std::endl
                  << "\n";

        std::string firstName, lastName, PESEL;

        std::string phoneNumber, email, city, street, houseNumber;
        int action;
        try {
            while (!tools::safeInput(action)) {
                throw InvalidInputException("Podano zla wartosc!");
            }
            switch (action) {
                case 1:
                    std::cout << "Podaj imie: ";
                    std::cin.ignore();
                    getline(std::cin, firstName);
                    std::cout << "Podaj nazwisko: ";
                    getline(std::cin, lastName);
                    std::cout << "Podaj PESEL: ";
                    getline(std::cin, PESEL);
                    std::cout << "Podaj numer telefonu: ";
                    getline(std::cin, phoneNumber);
                    std::cout << "Podaj email: ";
                    getline(std::cin, email);
                    std::cout << "Podaj miasto: ";
                    getline(std::cin, city);
                    std::cout << "Podaj ulice: ";
                    getline(std::cin, street);
                    std::cout << "Podaj numer domu: ";
                    getline(std::cin, houseNumber);

                    if(!clientManager->registerClient(firstName, lastName, PESEL,
                                                  std::make_shared<ContactDetails>(phoneNumber, email, street, city,
                                                                                   houseNumber), nullptr)){
                        throw ClientException("Nie zarejestrowano klienta");
                    }

                    break;
                case 2:
                    std::cout << "Podaj numer PESEL klienta: ";
                    std::cin.ignore();
                    getline(std::cin, PESEL);

                    if (clientManager->getClient(PESEL) == nullptr) {
                        throw ClientException("Nie znaleziono klienta.");
                    }

                    std::cout << clientManager->unregisterClient(PESEL);
                    break;
                case 3:
                    std::cout << "Podaj numer PESEL klienta: ";
                    std::cin.ignore();
                    getline(std::cin, PESEL);

                    if (clientManager->getClient(PESEL) == nullptr) {
                        throw ClientException("Nie znaleziono klienta.");
                    }

                    std::cout << clientManager->getClient(PESEL)->getInfo();
                    break;
                case 4:
                    std::cout << "Podaj numer PESEL klienta: ";
                    std::cin.ignore();
                    getline(std::cin, PESEL);

                    if (clientManager->getClient(PESEL) == nullptr) {
                        throw ClientException("Nie znaleziono klienta.");
                    }

                    std::cout << "\n" << clientManager->getClient(PESEL)->getInfo(true) << "\n";
                    break;
                case 5:
                    std::cout << clientManager->report();
                    break;
                case 6:
                    std::cout << clientManager->report(true);
                    break;
                case 0:
                    exit = 0;
                    break;
                default:
                    throw InvalidInputException("Podano zla wartosc client!");
//                std::cout << "Podano zla wartosc ";
//                break;
            }
        } catch (const Exceptions &e) {
            std::cout << "Error: " << e.what() << std::endl;
        }
    }
}

void Menu::field() {
    std::cout << "Zarzadzanie obiektami sportowymi \n";

    unsigned int exit = 1;

    while (exit != 0) {
        std::cout << "\n"
                  << "1-->Zarejestruj bieznie" << std::endl
                  << "2-->Zarejestruj boisko do pilki noznej" << std::endl
                  << "3-->Zarejestruj boisko do pilki siatkowej" << std::endl
                  << "4-->Zarejestruj boisko do koszykowki" << std::endl
                  << "5-->Wyrejestruj boisko" << std::endl
                  << "6-->Wyswietl informacje o boisku" << std::endl
                  << "7-->Wyswietl informacje o wszystkich boiskach" << std::endl
                  << "0-->Wyjdz z do menu" << std::endl
                  << "\n";

        std::string fieldName;
        double price, lenght;
        unsigned int maxNumberOfPlayers, dimensionsInt, optionOfFieldInt;
        footballDimensions footballDim;
        volleyballDimensions volleyballDim;
        basketballDimensions basketballDim;
        int action;
        bool optionOfField;
        try {
            while (!tools::safeInput(action)) {
                throw InvalidInputException("Podano zla wartosc!");
            }
            switch (action) {
                case 1:
                    std::cout << "Podaj nazwe boiska: ";
                    std::cin.ignore();
                    getline(std::cin, fieldName);
                    std::cout << "Podaj cene za godzine wypozyczenia: ";
//                    std::cin >> price;
                    while (!tools::safeInput(price)) {
                        throw InvalidInputException("Podano zla cene dla godziny wypozyczenia!");
                    }
                    std::cout << "Podaj maksymalna ilosc osob trenujacych: ";
//                    std::cin >> maxNumberOfPlayers;
                    while (!tools::safeInput(maxNumberOfPlayers)) {
                        throw InvalidInputException("Podano zla wartosc dla maksymalnej liczby osob trenujacych!");
                    }
                    std::cout << "Podaj dlugos biezni: ";
                    while (!tools::safeInput(lenght)) {
                        throw InvalidInputException("Podano zla wartosc dla dlugosci biezni!");
                    }
//                    std::cin >> lenght;

                    if (!fieldManager->registerRunningTrack(fieldName, price, maxNumberOfPlayers, lenght)) {
                        throw FieldException("Nie udalo sie zarejestrowac biezni.");
                    };

                    break;
                case 2:
                    std::cout << "Podaj nazwe boiska: ";
                    std::cin.ignore();
                    getline(std::cin, fieldName);
                    std::cout << "Podaj cene za godzine wypozyczenia: ";
//                    std::cin >> price;
                    while (!tools::safeInput(price)) {
                        throw InvalidInputException("Podano zla wartosc dla godziny wypozyczenia!");
                    }
                    std::cout << "Podaj maksymalna ilosc osob trenujacych: ";
//                    std::cin >> maxNumberOfPlayers;
                    while (!tools::safeInput(maxNumberOfPlayers)) {
                        throw InvalidInputException("Podano zla wartosc dla maksymalnej liczby zawodnikow!");
                    }
                    std::cout << "Podaj wymiary: ";
                    std::cout << tools::allDimensionsFootball();
//                    std::cin >> dimensionsInt;
                    while (!tools::safeInput(dimensionsInt)) {
                        throw InvalidInputException("Podano zla wartosc dla wymiarow boiska!");
                    }
                    if (dimensionsInt == 1) {
                        footballDim = L105xW68;
                    } else if (dimensionsInt == 2) {
                        footballDim = L62xW30;
                    } else if(dimensionsInt == 3){
                        footballDim = L31xW15;
                    }
                    else{
                        throw InvalidInputException("Podano zla wartosc dla wymiarow boiska!");
                    }
                    std::cout << "Czy trawiaste: \n\t 1 - tak \n\t 2 - nie \n";
//                    std::cin >> optionOfFieldInt;
                    while (!tools::safeInput(optionOfFieldInt)) {
                        throw InvalidInputException("Podano zla wartosc dla opcji boiska!");
                    }
                    if (optionOfFieldInt) {
                        optionOfField = true;
                    } else if (!optionOfFieldInt){
                        optionOfField = false;
                    }
                    else{
                        throw InvalidInputException("Podano zla wartosc dla rodzaju boiska!");
                    }

                    if (!fieldManager->registerFootballField(fieldName, price, maxNumberOfPlayers, footballDim,
                                                             optionOfField)) {
                        throw FieldException("Nie udalo sie zarejestrowac biezni.");
                    };
                    break;
                case 3:
                    std::cout << "Podaj nazwe boiska: ";
                    std::cin.ignore();
                    getline(std::cin, fieldName);
                    std::cout << "Podaj cene za godzine wypozyczenia: ";
//                    std::cin >> price;
                    while (!tools::safeInput(price)) {
                        throw InvalidInputException("Podano zla wartosc dla ceny!");
                    }
                    std::cout << "Podaj maksymalna ilosc osob trenujacych: ";
//                    std::cin >> maxNumberOfPlayers;
                    while (!tools::safeInput(maxNumberOfPlayers)) {
                        throw InvalidInputException("Podano zla wartosc dla maksymalnej liczby graczy!");
                    }
                    std::cout << "Podaj wymiary: ";
                    std::cout << tools::allDimensionsVolleyball();
//                    std::cin >> dimensionsInt;
                    while (!tools::safeInput(dimensionsInt)) {
                        throw InvalidInputException("Podano zla wartosc dla wymiarow boiska!");
                    }
                    if (dimensionsInt == 1) {
                        volleyballDim = L18xW9;
                    } else if(dimensionsInt == 2){
                        volleyballDim = L16xW8;
                    }
                    else{
                        throw InvalidInputException("Podano zla wartosc dla wymiarow boiska!");
                    }
                    std::cout << "Czy piaszczyste: \n\t 1 - tak \n\t 2 - nie \n";
//                    std::cin >> optionOfFieldInt;
                    while (!tools::safeInput(optionOfFieldInt)) {
                        throw InvalidInputException("Podano zla wartosc dla rodzaju boiska!");
                    }
                    if (optionOfFieldInt) {
                        optionOfField = true;
                    } else if(!optionOfFieldInt) {
                        optionOfField = false;
                    }
                    else{
                        throw InvalidInputException("Podano zla wartosc dla rodzaju boiska!");
                    }
                    if (!fieldManager->registerVolleyballField(fieldName, price, maxNumberOfPlayers, volleyballDim,
                                                               optionOfField)) {
                        throw FieldException("Nie udalo sie zarejestrowac biezni.");
                    };

                    break;
                case 4:
                    std::cout << "Podaj nazwe boiska: ";
                    std::cin.ignore();
                    getline(std::cin, fieldName);
                    std::cout << "Podaj cene za godzine wypozyczenia: ";
//                    std::cin >> price;
                    while (!tools::safeInput(price)) {
                        throw InvalidInputException("Podano zla wartosc dla ceny boiska!");
                    }
                    std::cout << "Podaj maksymalna ilosc osob trenujacych: ";
//                    std::cin >> maxNumberOfPlayers;
                    while (!tools::safeInput(maxNumberOfPlayers)) {
                        throw InvalidInputException("Podano zla wartosc dla maksymalnej liczby graczy!");
                    }
                    std::cout << "Podaj wymiary: ";
                    std::cout << tools::allDimensionsBasktball();
//                    std::cin >> dimensionsInt;
                    while (!tools::safeInput(dimensionsInt)) {
                        throw InvalidInputException("Podano zla wartosc dla wymiarow boiska!");
                    }
                    if (dimensionsInt == 1) {
                        basketballDim = L28xW15;
                    } else if(dimensionsInt == 2) {
                        basketballDim = L14xW8;
                    }
                    else{
                        throw InvalidInputException("Podano zla wartosc dla wymiarow boiska!");
                    }
                    std::cout << "Czy zakryte: \n\t 1 - tak \n\t 2 - nie \n";
//                    std::cin >> optionOfFieldInt;
                    while (!tools::safeInput(optionOfFieldInt)) {
                        throw InvalidInputException("Podano zla wartosc dla rodzaju boiska!");
                    }
                    if (optionOfFieldInt) {
                        optionOfField = true;
                    } else if(!optionOfFieldInt) {
                        optionOfField = false;
                    }
                    else{
                        throw InvalidInputException("Podano zla wartosc dla rodzaju boiska!");
                    }
                    if (!fieldManager->registerBasketballField(fieldName, price, maxNumberOfPlayers, basketballDim,
                                                               optionOfField)) {
                        throw FieldException("Nie udalo sie zarejestrowac biezni.");
                    };
                    break;
                case 5:
                    std::cout << "Podaj nazwe boiska: ";
                    std::cin.ignore();
                    getline(std::cin, fieldName);

                    if (fieldManager->getField(fieldName) == nullptr) {
                        throw FieldException("Nie znaleziono boiska.");
                    }
                    if(!fieldManager->unregisterField(fieldName)){
                        throw FieldException("Nie udalo sie wyrejestrowac boiska.");
                    }
                    break;
                case 6:
                    std::cout << "Podaj nazwe boiska: ";
                    std::cin.ignore();
                    getline(std::cin, fieldName);

                    if (fieldManager->getField(fieldName) == nullptr) {
                        throw FieldException("Nie znaleziono boiska.");
                    }

                    std::cout << fieldManager->getField(fieldName)->getInfo();
                    break;
                case 7:
                    if (fieldManager->getSize() == 0) {
                        std::cout << "\n Brak zarejestrowanych boisk \n";
                    }
                    std::cout << fieldManager->report();
                    break;
                case 0:
                    exit = 0;
                    break;
                default:
                    throw InvalidInputException("Podano zla wartosc field!");
//                std::cout << "Podano zla wartosc";
//                break;
            }
        } catch (const Exceptions &e) {
            std::cout << "Error: " << e.what() << std::endl;
        }
    }
}

void Menu::rent() {
    std::cout << "Zarzadzanie wypozyczeniami\n";

    unsigned int exit = 1;

    while (exit != 0) {
        std::cout << "\n"
                  << "1-->Wynajmij boisko" << std::endl
                  << "2-->Zakoncz wynajem" << std::endl
                  << "3-->Wyswietl informajce o wynajmie klienta" << std::endl
                  << "4-->Wyswietl informajce o wynajmie obiektu sportowego" << std::endl
                  << "5-->Wyswietl informacje o wszystkich wynajmach" << std::endl
                  << "6-->Wyswietl informacje o aktualnych wynajmach" << std::endl
                  << "7-->Wyswietl informacje o archiwalnych wynajmach" << std::endl
                  << "0-->Wyjdz z do menu" << std::endl
                  << "\n";

        std::string PESEL, fieldName;
        unsigned int rentHours, rentID;
        int action;
        FieldPtr field;
        ClientPtr client;
        try {
            while (!tools::safeInput(action)) {
                throw InvalidInputException("Podano zla wartosc!");
            }
            switch (action) {
                case 1:
                    if (clientManager->getSize() == 0) {
                        throw RentException("Nie znaleziono klientow.");
                        break;
                    }
                    std::cout << "Wszyscy klienci\n";
                    std::cout << clientManager->report();

                    std::cout << "Podaj numer PESEL klienta: ";
                    std::cin.ignore();
                    getline(std::cin, PESEL);

                    if (clientManager->getClient(PESEL) == nullptr) {
                        throw ClientException("Nie znaleziono klienta.");
                    }

                    if (fieldManager->getSize() == 0) {
                        throw FieldException("Nie znaleziono obiektow sportowych.");
//                        std::cout << "Brak obiektow sportowych do wypozyczenia.\n";
//                        break;
                    }
                    std::cout << "Wszystkie obiekty sportowe\n";
                    std::cout << fieldManager->report();

                    std::cout << "Podaj nazwe boiska: ";
                    getline(std::cin, fieldName);

                    if (fieldManager->getField(fieldName) == nullptr) {
                        throw FieldException("Nie znaleziono boiska.");
                    }

                    std::cout << "Podaj godziny wypozyczenia: ";
//                    std::cin >> rentHours;
                    while (!tools::safeInput(rentHours)) {
                        throw InvalidInputException("Podano zla wartosc dla godzin wypozyczenia!");
                    }
                    if(!rentManager->rentField(clientManager->getClient(PESEL), fieldManager->getField(fieldName),
                                               pt::not_a_date_time, rentHours)){
                        throw RentException("Nie wynajeto obiektu");
                    }
                    break;
                case 2:
                    if (rentManager->findAllCurrentRents().size() == 0) {
                        throw RentException("Brak wypozyczen.");
                    }
                    std::cout << "Wszystkie aktualne wypozyczenia.\n";
                    std::cout << rentManager->currentReport();

                    std::cout << "Podaj ID wypozyczenia ktore chcesz zakonczyc.\n";
//                    std::cin >> rentID;
                    while (!tools::safeInput(rentID)) {
                        throw InvalidInputException("Podano zla wartosc dla ID wypozyczenia!");
                    }
                    if(!rentManager->returnField(rentManager->findById(rentID)->getField(), pt::not_a_date_time)){
                        throw RentException("Nie oddano boiska.");
                    }
                    break;
                case 3:
                    if (clientManager->getSize() == 0) {
                        throw RentException("Brak klientow.");
                    }
                    std::cout << "Wszyscy klienci\n";
                    std::cout << clientManager->report();

                    std::cout << "Podaj numer PESEL klienta: ";
                    std::cin.ignore();
                    getline(std::cin, PESEL);
                    if(rentManager->getClientRents(clientManager->getClient(PESEL)).empty()){
                        throw RentException("Brak aktualnych klientow.");
                    }

                    for (const auto &it: rentManager->getClientRents(clientManager->getClient(PESEL))) {
                        std::cout << it->getRentInfo();
                    }
                    std::cout << std::endl;
                    break;
                case 4:
                    if (fieldManager->getSize() == 0) {
                        throw RentException("Brak boisk.");
                    }
                    std::cout << "Wszystkie obiekty sportowe\n";
                    std::cout << fieldManager->report();

                    std::cout << "Podaj nazwe boiska: ";
                    std::cin.ignore();
                    getline(std::cin, fieldName);
                    if(rentManager->getFieldRent(fieldManager->getField(fieldName))== nullptr){
                        throw RentException("Brak wypozyczen dla obiektu sportowego.");
                    }

                    std::cout << rentManager->getFieldRent(fieldManager->getField(fieldName))->getRentInfo();
                    std::cout << std::endl;
                    break;
                case 5:
                    std::cout << rentManager->report();
                    break;
                case 6:
                    std::cout << rentManager->currentReport();
                    break;
                case 7:
                    std::cout << rentManager->archiveReport();
                    break;
                case 0:
                    exit = 0;
                    break;
                default:
                    throw InvalidInputException("Podano zla wartosc!");
//                std::cout << "Podano zla wartosc";
//                break;
            }
        }
        catch (const Exceptions &e) {
            std::cout << "Error: " << e.what() << std::endl;
        }
    }
}