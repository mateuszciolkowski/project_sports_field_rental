#include <boost/test/unit_test.hpp>
#include "typedefs.h"
#include "Field.h"
#include "RunningTrack.h"


struct TestSuiteFieldFixture{
    const std::string testFieldName = "TestField";
    double testPrice = 150.5;
    double setterTestPrice = 13.5;
    unsigned int testMaxNumberOfPeople = 10;
    double testTrackLength = 60.6;
};

BOOST_FIXTURE_TEST_SUITE(TestSuiteField,TestSuiteFieldFixture)

    /**
     * @brief Test konstruktora dla klasy RunningTrack.
     */
    BOOST_AUTO_TEST_CASE(RunningTrackConstructorAndGetterTest) {
        // Tworzenie obiektu RunningTrack
        RunningTrackPtr runningTrackTest = std::make_shared<RunningTrack>(testFieldName, testPrice,
                                                                          testMaxNumberOfPeople, testTrackLength);

        // Sprawdzanie poprawności ustawionych wartości
        BOOST_TEST(runningTrackTest->getActualPrice() == testPrice);
        BOOST_TEST(runningTrackTest->getFieldName() == testFieldName);
        BOOST_TEST(runningTrackTest->getTrackLength() == testTrackLength);
        BOOST_TEST(runningTrackTest->getMaxNumberOfPeople() == testMaxNumberOfPeople);
    }

    BOOST_AUTO_TEST_CASE(RunningTrackSetterTest) {
        // Tworzenie obiektu RunningTrack
        RunningTrackPtr runningTrackTest = std::make_shared<RunningTrack>(testFieldName, testPrice,
                                                                          testMaxNumberOfPeople, testTrackLength);
        BOOST_TEST(runningTrackTest->getActualPrice() == testPrice);
        runningTrackTest->setPrice(setterTestPrice);
        // Sprawdzanie poprawności ustawionej wartości pola price
        BOOST_TEST(runningTrackTest->getActualPrice() == setterTestPrice);
    }

BOOST_AUTO_TEST_SUITE_END()