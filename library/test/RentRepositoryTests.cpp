//
// Created by Mateusz on 11/06/2024.
//
//
// Created by Mateusz Ciołkowski on 21/05/2024.
//
#include "typedefs.h"
#include <boost/test/unit_test.hpp>
#include "Client.h"
#include "Field.h"
#include "Rent.h"
#include "RunningTrack.h"
#include "repository/RentRepository.h"

namespace btt = boost::test_tools;


BOOST_AUTO_TEST_SUITE()

    BOOST_AUTO_TEST_CASE(RentRepositoryTests) {
        RentRepositoryPtr repository = std::make_shared<RentRepository>();
        ClientPtr clientTest = std::make_shared<Client>("Szymon", "Wasiel", "2421421", nullptr, nullptr);
        RunningTrackPtr fieldTest = std::make_shared<RunningTrack>("RunningTrack", 100, 3, 400);
        RentPtr rent1 = std::make_shared<Rent>(1, pt::not_a_date_time, 3, clientTest, fieldTest);
        RentPtr rent2 = std::make_shared<Rent>(2, pt::not_a_date_time, 5, clientTest, fieldTest);
        RentPtr rent3 = std::make_shared<Rent>(3, pt::not_a_date_time, 2, clientTest, fieldTest);
        RentPtr rent4 = std::make_shared<Rent>(4, pt::not_a_date_time, 1, clientTest, fieldTest);
        BOOST_TEST(repository->getSize() == 0);
        repository->addRent(rent1);
        repository->addRent(rent2);
        repository->addRent(rent3);
        repository->addRent(rent4);
        BOOST_TEST(repository->getSize() == 4);
        //Nie mozna dodac dwa razy tego samego wypozyczenia do repozytorium
        //Rent Exception: Nie dodano wypozyczenia do repozytorium.
        //repository->addRent(rent4);
        BOOST_TEST(repository->getSize() == 3);
        BOOST_TEST(repository->getRent(0) == rent1);
        RentPredicate test = [](const RentPtr &rent) { return rent->getRentHours() == 5; };
        BOOST_TEST(repository->findBy(test).at(0) == rent2);
        BOOST_TEST(repository->findByRentID(4) == rent4);
    }


BOOST_AUTO_TEST_SUITE_END()
