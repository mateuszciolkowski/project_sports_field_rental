//
// Created by 48791 on 11.06.2024.
//

#include <boost/test/unit_test.hpp>
#include "typedefs.h"
#include "Field.h"
#include "FootballField.h"


struct TestSuiteFieldFixture{
    const std::string testFieldName = "TestField";
    double testPrice = 150.5;
    double setterTestPrice = 13.5;
    unsigned int testMaxNumberOfPlayers = 10;
};

BOOST_FIXTURE_TEST_SUITE(TestSuiteField,TestSuiteFieldFixture)

    /**
     * @brief Test konstruktora dla klasy FootballField.
     */
    BOOST_AUTO_TEST_CASE(BasicFootballFieldConstructorAndGetterTest){
        // Tworzenie obiektu FootballField
        auto footballFieldTest = std::make_shared<FootballField>(testFieldName,testPrice,testMaxNumberOfPlayers, L105xW68,true);

        // Sprawdzanie poprawności ustawionych wartości
        BOOST_TEST(footballFieldTest->getPrice() == testPrice);
        BOOST_TEST(footballFieldTest->getFieldName() == testFieldName);
        BOOST_TEST(footballFieldTest->isGrassy() == true);
        BOOST_TEST(footballFieldTest->getMaxNumberOfPlayers() == testMaxNumberOfPlayers);
        BOOST_TEST(footballFieldTest->getDimensions() == 25);
    }

    BOOST_AUTO_TEST_CASE(FootballFieldSetterTest){
        // Tworzenie obiektu FootballField
        auto footballFieldTest = std::make_shared<FootballField>(testFieldName,testPrice,testMaxNumberOfPlayers, L105xW68,true);
        BOOST_TEST(footballFieldTest->getPrice() == testPrice);
        footballFieldTest->setPrice(setterTestPrice);
        // Sprawdzanie poprawności ustawionych wartości
        BOOST_TEST(footballFieldTest->getPrice() == setterTestPrice);


        BOOST_TEST(footballFieldTest->isGrassy() == true);
        footballFieldTest->setGrassy(false);
        BOOST_TEST(footballFieldTest->isGrassy() == false);

    }
    BOOST_AUTO_TEST_CASE(FootballGetActualPriceTest){
        // Tworzenie obiektu BasketballField
        auto footballFieldGrassyTest = std::make_shared<FootballField>(testFieldName,testPrice,testMaxNumberOfPlayers, L105xW68,true);

        BOOST_TEST(footballFieldGrassyTest->getPrice() == testPrice);
        BOOST_TEST(footballFieldGrassyTest->getActualPrice() == testPrice*footballFieldGrassyTest->getDimensions()/10+testPrice*footballFieldGrassyTest->getDimensions()/10*0.15);
        footballFieldGrassyTest->setPrice(setterTestPrice);
        BOOST_TEST(footballFieldGrassyTest->getPrice() == setterTestPrice);
        BOOST_TEST(footballFieldGrassyTest->getActualPrice() == setterTestPrice*footballFieldGrassyTest->getDimensions()/10+setterTestPrice*footballFieldGrassyTest->getDimensions()/10*0.15);

        footballFieldGrassyTest->setGrassy(false);
        BOOST_TEST(footballFieldGrassyTest->isGrassy() == false);
        footballFieldGrassyTest->setPrice(testPrice);

        BOOST_TEST(footballFieldGrassyTest->getPrice() == testPrice);
        BOOST_TEST(footballFieldGrassyTest->getActualPrice() == testPrice*footballFieldGrassyTest->getDimensions()/10);
        footballFieldGrassyTest->setPrice(setterTestPrice);
        BOOST_TEST(footballFieldGrassyTest->getPrice() == setterTestPrice);
        BOOST_TEST(footballFieldGrassyTest->getActualPrice() == setterTestPrice*footballFieldGrassyTest->getDimensions()/10);


    }


BOOST_AUTO_TEST_SUITE_END()