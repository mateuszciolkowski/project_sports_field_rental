//
// Created by Mateusz Ciołkowski on 21/05/2024.
//
#include "typedefs.h"

#include "Field.h"
#include "repository/FieldRepository.h"
#include <boost/test/unit_test.hpp>
#include "tools/Utilities.h"
#include "RunningTrack.h"
#include "VolleyballField.h"
#include "FootballField.h"
#include "BasketballField.h"

namespace btt = boost::test_tools;


BOOST_AUTO_TEST_SUITE()


    BOOST_AUTO_TEST_CASE(FieldRepositoryTests)
    {
        FieldRepositoryPtr repository = std::make_shared<FieldRepository>();
        FootballFieldPtr field1 = std::make_shared<FootballField>("Football", 14, 14, L105xW68, true);
        BasketballFieldPtr field2 = std::make_shared<BasketballField>("Basketball", 100, 75, L28xW15, true);
        VolleyballFieldPtr field3 = std::make_shared<VolleyballField>("Volleyball", 150, 50, L18xW9, false);
        RunningTrackPtr field4 = std::make_shared<RunningTrack>("RunningTrack1", 100,
                                                                12, 50);
        BOOST_TEST(repository->getSize() == 0);
        repository->addField(field1);
        repository->addField(field2);
        repository->addField(field3);
        repository->addField(field4);
        //Nie mozna dodac tego samego obiektu sportowego do repozytorium
        //Field Exception: Nie dodano obiektu sportowego do repozytorium.
        //repository->addField(field4);
        BOOST_TEST(repository->getSize() != 5);
        BOOST_TEST(repository->getSize() == 4);
        BOOST_TEST(repository->getSize() == 3);
        BOOST_TEST(repository->getField(0) == field1);
        FieldPredicate test = [](const FieldPtr &field) { return field->getFieldName() == "Volleyball"; };
        BOOST_TEST(repository->findBy(test).at(0) == field3);
        BOOST_TEST(repository->findByFieldName("Football") == field1);
        auto test1 = repository->findAll();
        for (int i = 0; i < repository->getSize(); i++) {
            BOOST_TEST(repository->getField(i) == test1.at(i));
        }
    }


BOOST_AUTO_TEST_SUITE_END()
