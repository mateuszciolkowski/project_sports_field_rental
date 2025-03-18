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


    BOOST_AUTO_TEST_CASE(ClientTypeEmployeeConstructorTests) {
        EmployeePtr employee = std::make_shared<Employee>();
        BOOST_TEST(employee->getPercentOfDiscount() == 80);
        BOOST_TEST(employee->getMaxRentalTime() == 5);
    }


    BOOST_AUTO_TEST_CASE(ClientTypeClientNormalConstructorTests) {
        ClientNormalPtr normal = std::make_shared<ClientNormal>();
        BOOST_TEST(normal->getPercentOfDiscount() == 0);
        BOOST_TEST(normal->getMaxRentalTime() == 2);
    }

    BOOST_AUTO_TEST_CASE(ClientTypeClientVIPConstructorTests) {
        ClientVIPPtr clientVip = std::make_shared<ClientVIP>();
        BOOST_TEST(clientVip->getPercentOfDiscount() == 40);
        BOOST_TEST(clientVip->getMaxRentalTime() == 4);
    }


BOOST_AUTO_TEST_SUITE_END()
