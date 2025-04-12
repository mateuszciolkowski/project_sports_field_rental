//
// Created by Mateusz on 11/06/2024.
//
//
// Created by Mateusz Ciołkowski on 21/05/2024.
//

#include "typedefs.h"
#include <boost/test/unit_test.hpp>
#include "managers/FieldManager.h"
#include "repository/FieldRepository.h"
#include "BasketballField.h"
#include "FootballField.h"
#include "VolleyballField.h"
#include "RunningTrack.h"

namespace btt = boost::test_tools;

BOOST_AUTO_TEST_SUITE()


    BOOST_AUTO_TEST_CASE(FieldManagerTests) {
        FieldManagerPtr manager = std::make_shared<FieldManager>();
        BOOST_TEST(manager->registerBasketballField("BasketballField", 110, 12, L28xW15, true));
        //Rejestracja nie przechodzi - identyczny identyfikator dostajemy
        //Field Exception: Nie zarejestrowano boiska do koszykowki.
        //BOOST_TEST(!manager->registerBasketballField("BasketballField", 100, 12, L28xW15, true));
        BOOST_TEST(manager->registerVolleyballField("VolleyballField", 100, 12, L18xW9, true));
        //Rejestracja nie przechodzi - identyczny identyfikator dostajemy
        //Field Exception: Nie zarejestrowano boiska do siatkowki
        //BOOST_TEST(!manager->registerVolleyballField("VolleyballField", 100, 12, L18xW9, true));
        BOOST_TEST(manager->registerFootballField("FootballField", 100, 12, L105xW68, true));
        //Rejestracja nie przechodzi - identyfikator jest juz zarezerwowany
        //Field Exception: Nie zarejestrowano boiska do pilki noznej
        //BOOST_TEST(!manager->registerFootballField("FootballField", 100, 12, L105xW68, true));
        BOOST_TEST(manager->registerRunningTrack("RunningTrack", 100, 12, 1500));
        //Rejestracja nie przechodzi - identyfikator jest juz zarezerwowany
        //Field Exception: Nie zarejestrowano biezni
        //BOOST_TEST(!manager->registerRunningTrack("RunningTrack", 100, 12, 1500));
        BOOST_TEST(manager->getSize() == 4);
        BOOST_TEST(manager->unregisterField("RunningTrack"));
        //Nie przechodzi nie mozna wyrejestrowac boiska ktore nie jest wyrejestrowane
        //Field Exception: Nie udalo sie wyrejestrowac boiska.
        //BOOST_TEST(!manager->unregisterField("RunningTrack"));
        BOOST_TEST(manager->getSize() == 3);
        BOOST_TEST(manager->getField("BasketballField")->getPrice() == 110);

    }


BOOST_AUTO_TEST_SUITE_END()