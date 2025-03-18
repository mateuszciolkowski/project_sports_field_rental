//
// Created by Mateusz Ciołkowski on 21/05/2024.
//

#include "typedefs.h"
#include <boost/test/unit_test.hpp>
#include "Client.h"
#include "ClientType.h"
#include "ContactDetails.h"
#include "repository/ClientRepository.h"
#include "managers/ClientManager.h"

namespace btt = boost::test_tools;

BOOST_AUTO_TEST_SUITE()

    BOOST_AUTO_TEST_CASE(ClientManagerTests)
    {
        ContactDetailsPtr contactDetails = std::make_shared<ContactDetails>("numer_telefonu", "email", "ulica",
                                                                            "miasto", "numer_domu");
        ClientVIPPtr clientTypeVip = std::make_shared<ClientVIP>();

        ClientManagerPtr manager = std::make_shared<ClientManager>();
        manager->registerClient("Imie1", "Nazwisko", "PESEL", contactDetails, nullptr);
        manager->registerClient("Imie1", "Nazwisko1", "PESEL1", contactDetails, clientTypeVip);
        manager->registerClient("Imie1", "Nazwisko2", "PESEL2", contactDetails, nullptr);
        manager->registerClient("Imie2", "Nazwisko2", "PESEL3", contactDetails, nullptr);
        manager->registerClient("Imie3", "Nazwisko2", "PESEL4", contactDetails, nullptr);
        BOOST_TEST(manager->getSize() == 5);
        //test nie przechodzi oraz dostajemy wyjatek
        //Client Exception: Nie zarejestrowano klienta.
        //BOOST_TEST(!manager->registerClient("Imie2", "Nazwisko2", "PESEL2", contactDetails, nullptr));
        BOOST_TEST(manager->getSize() == 5);
        BOOST_TEST(manager->unregisterClient("PESEL1"));
        BOOST_TEST(manager->getSize() == 4);
        //test nie przechodzi nie mozemy wyrejestrowac klienta ktory nie jest zarejestrowany
        //Client Exception: Nie wyrejestrowano klienta.
        //BOOST_TEST(!manager->unregisterClient("PESEL1"));

        ClientPredicate testClient = [](ClientPtr client) { return client->getFirstName() == "Imie1"; };
        BOOST_TEST(manager->findClients(testClient).at(0)->getPesel() == "PESEL");
        BOOST_TEST(manager->findClients(testClient).at(1)->getPesel() == "PESEL2");

        auto test = manager->findAllClients();
        for (int i = 0; i < manager->getSize(); i++) {
            std::string PESELtmp = test.at(i)->getPesel();
            BOOST_TEST(manager->getClient(PESELtmp) == test.at(i));
        }
    }


BOOST_AUTO_TEST_SUITE_END()