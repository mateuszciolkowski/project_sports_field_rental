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
#include "repository/ClientRepository.h"
#include "managers/ClientManager.h"
#include "managers/FieldManager.h"
#include "repository/FieldRepository.h"
#include "BasketballField.h"
#include "FootballField.h"
#include "VolleyballField.h"
#include "RunningTrack.h"
#include "managers/RentManager.h"
#include "repository/RentRepository.h"
#include "Rent.h"

namespace btt = boost::test_tools;

BOOST_AUTO_TEST_SUITE()


    BOOST_AUTO_TEST_CASE(RentManagerTests) {
        RentManagerPtr manager = std::make_shared<RentManager>();
        EmployeePtr employee = std::make_shared<Employee>();
        ClientPtr client1 = std::make_shared<Client>("Imie", "Nazwisko", "PESEL1", nullptr, nullptr);
        ClientPtr client2 = std::make_shared<Client>("Kuba", "Nazwisko", "PESEL2", nullptr, nullptr);
        ClientPtr client3 = std::make_shared<Client>("Kuba", "Nazwisko", "PESEL3", nullptr, employee);
        BasketballFieldPtr field1 = std::make_shared<BasketballField>("Basketball1", 100, 75, L28xW15, true);
        BasketballFieldPtr field2 = std::make_shared<BasketballField>("Basketball2", 100, 75, L28xW15, true);
        BasketballFieldPtr field3 = std::make_shared<BasketballField>("Basketball3", 100, 75, L28xW15, true);
        BOOST_TEST(manager->rentField(client1, field2, pt::second_clock::local_time() - pt::hours(2), 2));
        // Nie powinno przejść bo client2 ma clientType = normal
        BOOST_TEST(!manager->rentField(client2, field2, pt::not_a_date_time, 4));
        // Nie powinno przejść bo field2 jest wypożyczony aktualnie
        BOOST_TEST(!manager->rentField(client2, field2, pt::not_a_date_time, 2));

        BOOST_TEST(manager->rentField(client2, field1, pt::not_a_date_time, 2));
        BOOST_TEST(manager->rentField(client3, field3, pt::not_a_date_time, 2));
        BOOST_TEST(manager->findAllRents().size() == 3);
        BOOST_TEST(manager->findById(2)->getRentHours() == 2);
        BOOST_TEST(manager->returnField(field2, pt::not_a_date_time));
        BOOST_TEST(manager->findAllCurrentRents().size() == 2);
        BOOST_TEST(manager->findAllArchiveRents().size() == 1);
        BOOST_TEST(manager->getClientRents(client2).at(0)->getRentHours() == 2);
        BOOST_TEST(manager->findById(1, true)->getRentHours() == 2);

        BOOST_TEST(manager->getClientRents(client2).at(0)->getField() == field1);

        BOOST_TEST(manager->getClientRents(client2).size() == 1);
        BOOST_TEST(manager->getFieldRent(field1)->getClient() == client2);

    }

    BOOST_AUTO_TEST_CASE(getClientRentsTest) {
        RentManagerPtr manager = std::make_shared<RentManager>();
        ClientPtr client = std::make_shared<Client>("Kuba", "Nazwisko", "PESEL", nullptr, nullptr);
        BasketballFieldPtr field1 = std::make_shared<BasketballField>("Basketball1", 100, 75, L28xW15, true);
        BasketballFieldPtr field2 = std::make_shared<BasketballField>("Basketball2", 100, 75, L28xW15, true);
        BasketballFieldPtr field3 = std::make_shared<BasketballField>("Basketball3", 100, 75, L28xW15, true);
        BOOST_TEST(manager->rentField(client, field1, pt::not_a_date_time, 2));
        BOOST_TEST(manager->rentField(client, field2, pt::not_a_date_time, 2));
        BOOST_TEST(manager->rentField(client, field3, pt::not_a_date_time, 2));
        BOOST_TEST(manager->getClientRents(client).size() == 3);
        BOOST_TEST(manager->returnField(field1, pt::not_a_date_time));
        BOOST_TEST(manager->getClientRents(client).size() == 2);
        BOOST_TEST(manager->getClientRents(client, true).size() == 3);
    }

    BOOST_AUTO_TEST_CASE(findRentsTests) {
        RentManagerPtr manager = std::make_shared<RentManager>();
        ClientPtr client1 = std::make_shared<Client>("Kuba", "Nazwisko", "PESEL", nullptr, nullptr);
        ClientPtr client2 = std::make_shared<Client>("Jacek", "Kowalski", "PESEL2", nullptr, nullptr);
        ClientPtr client3 = std::make_shared<Client>("Kuba", "Kowalski", "PESEL3", nullptr, nullptr);
        BasketballFieldPtr field1 = std::make_shared<BasketballField>("Basketball1", 100, 75, L28xW15, true);
        BasketballFieldPtr field2 = std::make_shared<BasketballField>("Basketball2", 100, 75, L28xW15, true);
        BasketballFieldPtr field3 = std::make_shared<BasketballField>("Basketball3", 100, 75, L28xW15, true);
        BOOST_TEST(manager->rentField(client1, field1, pt::not_a_date_time, 2));
        BOOST_TEST(manager->rentField(client2, field2, pt::not_a_date_time, 1));
        BOOST_TEST(manager->rentField(client3, field3, pt::not_a_date_time, 2));

        RentPredicate test = [](const RentPtr &rent) { return rent->getClient()->getLastName() == "Kowalski"; };

        BOOST_TEST(manager->findRents(test).size() == 2);
        BOOST_TEST(manager->returnField(field2, pt::not_a_date_time));
        BOOST_TEST(manager->findRents(test).size() == 2);
        BOOST_TEST(manager->findArchiveRents(test).size() == 1);
        BOOST_TEST(manager->findCurrentRents(test).size() == 1);
    }


    BOOST_AUTO_TEST_CASE(checkClientRents) {
        RentManagerPtr manager = std::make_shared<RentManager>();
        ClientPtr client = std::make_shared<Client>("Kuba", "Nazwisko", "PESEL", nullptr, nullptr);
        BasketballFieldPtr field = std::make_shared<BasketballField>("Basketball1", 100, 75, L28xW15, true);
        BOOST_TEST(manager->checkClientRents(client) == 0);

        for (int i = 0; i < 21; i++) {
            BOOST_TEST(manager->rentField(client, field, pt::second_clock::local_time() - pt::hours(2), 2));
            BOOST_TEST(manager->returnField(field, pt::not_a_date_time));
        }
        BOOST_TEST(manager->checkClientRents(client) == 42);
        BOOST_TEST(manager->findAllArchiveRents().at(0)->getClient()->getClientType()->getPercentOfDiscount() == 40);
        BOOST_TEST(manager->getCount() == 21);
    }


BOOST_AUTO_TEST_SUITE_END()