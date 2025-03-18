//
// Created by Mateusz on 11/06/2024.
//
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
     * @brief Testy jednostkowe dla klasy ContactDetails.
     */


    BOOST_AUTO_TEST_CASE(ContactDetailsConstructorTests)
    {
//        // Tworzenie obiektu ContactDetails
//        ContactDetailsPtr contactDetails = std::make_shared<ContactDetails>("numer_telefonu","email","ulica","miasto","numer_domu");
//        // Tworzenie obiektu Client
//        ClientPtr client = std::make_shared<Client>("Imie","Nazwisko","PESEL",contactDetails, nullptr);
//
//        // Sprawdzanie, czy dane kontaktowe klienta są poprawnie ustawione
//        BOOST_TEST(client->getContactDetails()->getPhoneNumber()=="numer_telefonu");
//        // Modyfikacja numeru telefonu i sprawdzanie, czy zmiana została dokonana poprawnie
//        client->getContactDetails()->setPhoneNumber("numer_telefonu2");
//        BOOST_TEST(client->getContactDetails()->getPhoneNumber()=="numer_telefonu2");
//
//        // Analogiczne testy dla pozostałych pól danych kontaktowych
//        BOOST_TEST(client->getContactDetails()->getEmail()=="email");
//        client->getContactDetails()->setEmail("email2");
//        BOOST_TEST(client->getContactDetails()->getEmail()=="email2");
//        BOOST_TEST(client->getContactDetails()->getStreet()=="ulica");
//        client->getContactDetails()->setStreet("ulica2");
//        BOOST_TEST(client->getContactDetails()->getStreet()=="ulica2");
//        BOOST_TEST(client->getContactDetails()->getCity()=="miasto");
//        client->getContactDetails()->setCity("miasto2");
//        BOOST_TEST(client->getContactDetails()->getCity()=="miasto2");
//        BOOST_TEST(client->getContactDetails()->getHouseNumber()=="numer_domu");
//        client->getContactDetails()->setHouseNumber("numer_domu2");
//        BOOST_TEST(client->getContactDetails()->getHouseNumber()=="numer_domu2");

        // Tworzenie obiektu ContactDetails
        ContactDetailsPtr contactDetails = std::make_shared<ContactDetails>("numer_telefonu", "email", "ulica",
                                                                            "miasto", "numer_domu");

        BOOST_TEST(contactDetails->getPhoneNumber() == "numer_telefonu");
        BOOST_TEST(contactDetails->getEmail() == "email");
        BOOST_TEST(contactDetails->getStreet() == "ulica");
        BOOST_TEST(contactDetails->getHouseNumber() == "numer_domu");

    }

    BOOST_AUTO_TEST_CASE(ContactDetailsSetterAndGetterTests)
    {
        ContactDetailsPtr contactDetails = std::make_shared<ContactDetails>("numer_telefonu", "email", "ulica",
                                                                            "miasto", "numer_domu");

        contactDetails->setPhoneNumber("numer_telefonu2");
        BOOST_TEST(contactDetails->getPhoneNumber() == "numer_telefonu2");

        contactDetails->setEmail("email2");
        BOOST_TEST(contactDetails->getEmail() == "email2");

        contactDetails->setStreet("ulica2");
        BOOST_TEST(contactDetails->getStreet() == "ulica2");

        contactDetails->setCity("miasto2");
        BOOST_TEST(contactDetails->getCity() == "miasto2");

        contactDetails->setHouseNumber("numer_domu2");
        BOOST_TEST(contactDetails->getHouseNumber() == "numer_domu2");

    }

BOOST_AUTO_TEST_SUITE_END()
