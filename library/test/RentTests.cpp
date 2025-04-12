//
// Created by Mateusz Ciołkowski on 21/05/2024.
//
#include <boost/test/unit_test.hpp>
#include <boost/date_time.hpp>
#include "typedefs.h"
#include "Client.h"
#include "ContactDetails.h"
#include "ClientType.h"
#include "Field.h"
#include "FootballField.h"
#include "Rent.h"


BOOST_AUTO_TEST_SUITE()

    BOOST_AUTO_TEST_CASE(RentTest) {
        ContactDetailsPtr contactDetails = std::make_shared<ContactDetails>("numer_telefonu", "email", "ulica",
                                                                            "miasto", "numer_domu");
        ClientVIPPtr clientTypeVip = std::make_shared<ClientVIP>();
        EmployeePtr employee = std::make_shared<Employee>();

        ClientPtr client1 = std::make_shared<Client>("Imie", "Nazwisko", "PESEL", contactDetails, nullptr);
        ClientPtr client2 = std::make_shared<Client>("Imie", "Nazwisko", "PESEL", contactDetails, employee);
        ClientPtr client3 = std::make_shared<Client>("Imie", "Nazwisko", "PESEL", contactDetails, clientTypeVip);


        FootballFieldPtr footballFieldTest = std::make_shared<FootballField>("FootballField", 100, 12, L105xW68, true);


        RentPtr rent1 = std::make_shared<Rent>(1, pt::second_clock::local_time() - pt::hours(2), 2, client1,
                                               footballFieldTest);
        BOOST_TEST(rent1->getClient() == client1);
        BOOST_TEST(rent1->getField() == footballFieldTest);
        BOOST_TEST(rent1->getRentId() == 1);
        BOOST_TEST(rent1->getBeginTime() == pt::second_clock::local_time() - pt::hours(2));
        BOOST_TEST(rent1->getEndTime() == pt::not_a_date_time);
        BOOST_TEST(rent1->getRentHours() == 2);
        rent1->endRent(pt::not_a_date_time);
        BOOST_TEST(rent1->getEndTime() == pt::second_clock::local_time());
        BOOST_TEST(rent1->getRentCost() == 100 * 2 * L105xW68 / 10 + 100 * 2 * L105xW68 / 10 * 0.15);

        RentPtr rent2 = std::make_shared<Rent>(2, pt::second_clock::local_time() - pt::hours(2), 2, client2,
                                               footballFieldTest);
        rent2->endRent(pt::not_a_date_time);
        BOOST_TEST(rent2->getEndTime() == pt::second_clock::local_time());
        BOOST_TEST(rent2->getRentCost() ==
                   100 * 2 * L105xW68 / 10 - 100 * 2 * L105xW68 / 10 * 0.8 - 100 * 2 * L105xW68 / 10 * 0.8 * 0.15 +
                   100 * 2 * L105xW68 / 10 * 0.15);

        RentPtr rent3 = std::make_shared<Rent>(2, pt::second_clock::local_time() - pt::hours(2), 2, client3,
                                               footballFieldTest);
        rent3->endRent(pt::not_a_date_time);
        BOOST_TEST(rent3->getEndTime() == pt::second_clock::local_time());
        BOOST_TEST(rent3->getRentCost() ==
                   100 * 2 * L105xW68 / 10 - 100 * 2 * L105xW68 / 10 * 0.4 - 100 * 2 * L105xW68 / 10 * 0.4 * 0.15 +
                   100 * 2 * L105xW68 / 10 * 0.15);
    }


    BOOST_AUTO_TEST_CASE(OverHoursTest) {
        ContactDetailsPtr contactDetails = std::make_shared<ContactDetails>("numer_telefonu", "email", "ulica",
                                                                            "miasto", "numer_domu");
        ClientVIPPtr clientTypeVip = std::make_shared<ClientVIP>();
        EmployeePtr employee = std::make_shared<Employee>();

        ClientPtr client1 = std::make_shared<Client>("Imie", "Nazwisko", "PESEL", contactDetails, nullptr);
        ClientPtr client2 = std::make_shared<Client>("Imie", "Nazwisko", "PESEL", contactDetails, employee);
        ClientPtr client3 = std::make_shared<Client>("Imie", "Nazwisko", "PESEL", contactDetails, clientTypeVip);


        FootballFieldPtr footballFieldTest = std::make_shared<FootballField>("FootballField", 100, 12, L105xW68, true);


        RentPtr rent1 = std::make_shared<Rent>(1, pt::second_clock::local_time() - pt::hours(4), 6, client1,
                                               footballFieldTest);
        BOOST_TEST(rent1->getRentHours() == 6);
        BOOST_TEST(rent1->getBeginTime() == rent1->getEndTime());


        RentPtr rent11 = std::make_shared<Rent>(2, pt::second_clock::local_time() - pt::hours(2), 2, client1,
                                                footballFieldTest);
        rent11->endRent(pt::second_clock::local_time() + pt::hours(3));
        pt::time_period period(pt::second_clock::local_time() - pt::hours(2),
                               pt::second_clock::local_time() + pt::hours(3));
        BOOST_TEST(period.length().hours() == 5);
        BOOST_TEST(rent11->getBeginTime() == pt::second_clock::local_time() - pt::hours(2));
        BOOST_TEST(rent11->getEndTime() == pt::second_clock::local_time() + pt::hours(3));
        BOOST_TEST(rent11->getRentCost() ==
                   100 * 2 * L105xW68 / 10 + 100 * 6 * L105xW68 / 10 + 100 * 8 * L105xW68 / 10 * 0.15);

        RentPtr rent12 = std::make_shared<Rent>(2, pt::second_clock::local_time() - pt::hours(5), 5, client2,
                                                footballFieldTest);
        rent12->endRent(pt::second_clock::local_time() + pt::hours(3));
//        pt::time_period period(pt::second_clock::local_time()-pt::hours(2), pt::second_clock::local_time()+pt::hours(3));
//        BOOST_TEST(period.length().hours() == 8);
        BOOST_TEST(rent12->getBeginTime() == pt::second_clock::local_time() - pt::hours(5));
        BOOST_TEST(rent12->getEndTime() == pt::second_clock::local_time() + pt::hours(3));
        BOOST_TEST(rent12->getRentCost() ==
                   (100 * 5 * L105xW68 / 10 + 100 * 6 * L105xW68 / 10) * 0.2 + 100 * 11 * L105xW68 / 10 * 0.15 * 0.2);

        RentPtr rent13 = std::make_shared<Rent>(2, pt::second_clock::local_time() - pt::hours(4), 4, client3,
                                                footballFieldTest);
        rent13->endRent(pt::second_clock::local_time() + pt::hours(1) - pt::minutes(2));
//        pt::time_period period(pt::second_clock::local_time()-pt::hours(2), pt::second_clock::local_time()+pt::hours(3));
//        BOOST_TEST(period.length().hours() == 8);
        BOOST_TEST(rent13->getBeginTime() == pt::second_clock::local_time() - pt::hours(4));
        BOOST_TEST(rent13->getEndTime() == pt::second_clock::local_time() + pt::hours(1) - pt::minutes(2));
        BOOST_TEST(rent13->getRentCost() ==
                   (100 * 4 * L105xW68 / 10 + 100 * 2 * L105xW68 / 10) * 0.6 + 100 * 6 * L105xW68 / 10 * 0.15 * 0.6);

        RentPtr rent14 = std::make_shared<Rent>(2, pt::second_clock::local_time() - pt::hours(4), 4, client3,
                                                footballFieldTest);
        rent14->endRent(pt::second_clock::local_time() + pt::hours(1) + pt::minutes(2));
//        pt::time_period period(pt::second_clock::local_time()-pt::hours(2), pt::second_clock::local_time()+pt::hours(3));
//        BOOST_TEST(period.length().hours() == 8);
        BOOST_TEST(rent14->getBeginTime() == pt::second_clock::local_time() - pt::hours(4));
        BOOST_TEST(rent14->getEndTime() == pt::second_clock::local_time() + pt::hours(1) + pt::minutes(2));
        BOOST_TEST(rent14->getRentCost() ==
                   (100 * 4 * L105xW68 / 10 + 100 * 4 * L105xW68 / 10) * 0.6 + 100 * 8 * L105xW68 / 10 * 0.15 * 0.6);
    }


BOOST_AUTO_TEST_SUITE_END()