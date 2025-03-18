//
// Created by 48791 on 11.06.2024.
//

#include <boost/test/unit_test.hpp>
#include "typedefs.h"
#include "Field.h"
#include "VolleyballField.h"

struct TestSuiteFieldFixture{
    const std::string testFieldName = "TestField";
    double testPrice = 150.5;
    double setterTestPrice = 13.5;
    unsigned int testMaxNumberOfPlayers = 10;

};

BOOST_FIXTURE_TEST_SUITE(TestSuiteField,TestSuiteFieldFixture)
    /**
     * @brief Test konstruktora dla klasy VolleyballField.
     */
    BOOST_AUTO_TEST_CASE(BasicVolleyballFieldConstructorAndGetterTest){
        // Tworzenie obiektu VolleyballField
        auto volleyballFieldTest = std::make_shared<VolleyballField>(testFieldName,testPrice,testMaxNumberOfPlayers,L18xW9,true);

        // Sprawdzanie poprawności ustawionych wartości
        BOOST_TEST(volleyballFieldTest->getPrice() == testPrice);
        BOOST_TEST(volleyballFieldTest->getFieldName() == testFieldName);
        BOOST_TEST(volleyballFieldTest->isSandy() == true);
        BOOST_TEST(volleyballFieldTest->getDimensions() == 15);
        BOOST_TEST(volleyballFieldTest->getMaxNumberOfPlayers() == testMaxNumberOfPlayers);
    }
    BOOST_AUTO_TEST_CASE(VolleyballFieldSetterTest) {
        // Tworzenie obiektu VolleyballField
        auto volleyballFieldTest = std::make_shared<VolleyballField>(testFieldName, testPrice, testMaxNumberOfPlayers,
                                                                     L18xW9, true);

        BOOST_TEST(volleyballFieldTest->getPrice() == testPrice);
        volleyballFieldTest->setPrice(setterTestPrice);
        // Sprawdzanie poprawności ustawionej  wartości
        BOOST_TEST(volleyballFieldTest->getPrice() == setterTestPrice);

        BOOST_TEST(volleyballFieldTest->isSandy() == true);
        volleyballFieldTest->setSandy(false);
        BOOST_TEST(volleyballFieldTest->isSandy() == false);
    }

    BOOST_AUTO_TEST_CASE(VolleyballGetActualPriceTest){
        // Tworzenie obiektu BasketballField
        auto volleyballFieldTest = std::make_shared<VolleyballField>(testFieldName,testPrice,testMaxNumberOfPlayers,L18xW9,false);

        BOOST_TEST(volleyballFieldTest->getPrice() == testPrice);
        BOOST_TEST(volleyballFieldTest->getActualPrice() == testPrice*volleyballFieldTest->getDimensions()/10+testPrice*volleyballFieldTest->getDimensions()/10*0.1);
        volleyballFieldTest->setPrice(setterTestPrice);
        BOOST_TEST(volleyballFieldTest->getPrice() == setterTestPrice);
        BOOST_TEST(volleyballFieldTest->getActualPrice() == setterTestPrice*volleyballFieldTest->getDimensions()/10+setterTestPrice*volleyballFieldTest->getDimensions()/10*0.1);

        volleyballFieldTest->setSandy(true);
        volleyballFieldTest->setPrice(testPrice);

        BOOST_TEST(volleyballFieldTest->getPrice() == testPrice);
        BOOST_TEST(volleyballFieldTest->getActualPrice() == testPrice*volleyballFieldTest->getDimensions()/10);
        volleyballFieldTest->setPrice(setterTestPrice);
        BOOST_TEST(volleyballFieldTest->getPrice() == setterTestPrice);
        BOOST_TEST(volleyballFieldTest->getActualPrice() == setterTestPrice*volleyballFieldTest->getDimensions()/10);
    }


BOOST_AUTO_TEST_SUITE_END()