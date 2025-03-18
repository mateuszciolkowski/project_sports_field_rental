//
// Created by Mateusz Ciołkowski on 21/05/2024.
//
#include "typedefs.h"
#include <boost/test/unit_test.hpp>
#include "Client.h"
#include "ClientType.h"
#include "ContactDetails.h"

namespace btt = boost::test_tools;

BOOST_AUTO_TEST_SUITE()

    /**
     * @brief Testy jednostkowe dla klasy Client.
     */
    BOOST_AUTO_TEST_CASE(ClientClassTests) {
        ContactDetailsPtr contactDetails = std::make_shared<ContactDetails>("numer_telefonu", "email", "ulica",
                                                                            "miasto", "numer_domu");
        ClientVIPPtr clientType = std::make_shared<ClientVIP>();
        ClientPtr client = std::make_shared<Client>("Imie", "Nazwisko", "PESEL", contactDetails, clientType);

        // Sprawdzanie, czy dane klienta są poprawnie ustawione
        BOOST_TEST(client->getFirstName() == "Imie");
        BOOST_TEST(client->getLastName() == "Nazwisko");
        BOOST_TEST(client->getPesel() == "PESEL");
        BOOST_TEST(client->getContactDetails() == contactDetails);
        BOOST_TEST(client->getClientType() == clientType);


    }

    BOOST_AUTO_TEST_CASE(ClientGetterAndSetterTests) {
        ClientPtr client = std::make_shared<Client>("Imie", "Nazwisko", "PESEL", nullptr, nullptr);
        ClientVIPPtr clientType = std::make_shared<ClientVIP>();
        ContactDetailsPtr contactDetails = std::make_shared<ContactDetails>("numer_telefonu", "email", "ulica",
                                                                            "miasto", "numer_domu");

        client->setFirstName("Imie1");
        BOOST_TEST(client->getFirstName() == "Imie1");

        client->setLastName("Nazwisko2");
        BOOST_TEST(client->getLastName() == "Nazwisko2");

        BOOST_TEST(client->getContactDetails() == nullptr);
        client->setContactDetails(contactDetails);
        BOOST_TEST(client->getContactDetails() == contactDetails);

        //sprawdzenie czy aktualnie ustawiony clientType to normalClient
        BOOST_TEST(client->getClientType()->getPercentOfDiscount() == 0);
        client->setClientType(clientType);
        BOOST_TEST(client->getClientType()->getPercentOfDiscount() == 40);

    }


BOOST_AUTO_TEST_SUITE_END()
