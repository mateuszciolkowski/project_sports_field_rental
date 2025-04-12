//
// Created by 48791 on 11.06.2024.
//

#include <boost/test/unit_test.hpp>
#include "typedefs.h"
#include "Field.h"

#include "BasketballField.h"

struct TestSuiteFieldFixture{
    const std::string testFieldName = "TestField";
    double testPrice = 150.5;
    double setterTestPrice = 13.5;
    unsigned int testMaxNumberOfPlayers = 10;
};

BOOST_FIXTURE_TEST_SUITE(TestSuiteField,TestSuiteFieldFixture)

    /**
     * @brief Test konstruktora dla klasy BasketballField.
     */
    BOOST_AUTO_TEST_CASE(BasicBasketballFieldConstructorTest){
        // Tworzenie obiektu BasketballField
        auto basketballFieldTest = std::make_shared<BasketballField>(testFieldName,testPrice,testMaxNumberOfPlayers,L28xW15,true);

        // Sprawdzanie poprawności ustawionych wartości
        BOOST_TEST(basketballFieldTest->getPrice() == testPrice);
        BOOST_TEST(basketballFieldTest->getFieldName() == testFieldName);
        BOOST_TEST(basketballFieldTest->isCovered() == true);
        BOOST_TEST(basketballFieldTest->getDimensions() == 15);
        BOOST_TEST(basketballFieldTest->getMaxNumberOfPlayers() == testMaxNumberOfPlayers);
    }

    BOOST_AUTO_TEST_CASE(BasketballSetterTest){
        // Tworzenie obiektu BasketballField
        auto basketballFieldTest = std::make_shared<BasketballField>(testFieldName,testPrice,testMaxNumberOfPlayers,L28xW15,true);

        BOOST_TEST(basketballFieldTest->getPrice() == testPrice);
        basketballFieldTest->setPrice(setterTestPrice);
        // Sprawdzanie poprawności ustawionych wartości
        BOOST_TEST(basketballFieldTest->getPrice() == setterTestPrice);

        BOOST_TEST(basketballFieldTest->isCovered() == true);
        basketballFieldTest->setCovered(false);
        BOOST_TEST(basketballFieldTest->isCovered() == false);

    }


    BOOST_AUTO_TEST_CASE(BasketballGetActualPriceTest){
        // Tworzenie obiektu BasketballField
        auto basketballCoveredFieldTest = std::make_shared<BasketballField>(testFieldName,testPrice,testMaxNumberOfPlayers,L28xW15,true);

        BOOST_TEST(basketballCoveredFieldTest->getPrice() == testPrice);
        BOOST_TEST(basketballCoveredFieldTest->getActualPrice() == testPrice*basketballCoveredFieldTest->getDimensions()/10+testPrice*basketballCoveredFieldTest->getDimensions()/10*0.25);
        basketballCoveredFieldTest->setPrice(setterTestPrice);
        BOOST_TEST(basketballCoveredFieldTest->getPrice() == setterTestPrice);
        BOOST_TEST(basketballCoveredFieldTest->getActualPrice() == setterTestPrice*basketballCoveredFieldTest->getDimensions()/10+setterTestPrice*basketballCoveredFieldTest->getDimensions()/10*0.25);

        basketballCoveredFieldTest->setCovered(false);
        basketballCoveredFieldTest->setPrice(testPrice);

        BOOST_TEST(basketballCoveredFieldTest->getPrice() == testPrice);
        BOOST_TEST(basketballCoveredFieldTest->getActualPrice() == testPrice*basketballCoveredFieldTest->getDimensions()/10);
        basketballCoveredFieldTest->setPrice(setterTestPrice);
        BOOST_TEST(basketballCoveredFieldTest->getPrice() == setterTestPrice);
        BOOST_TEST(basketballCoveredFieldTest->getActualPrice() == setterTestPrice*basketballCoveredFieldTest->getDimensions()/10);

    }

BOOST_AUTO_TEST_SUITE_END()