//
// Created by Mateusz on 11/06/2024.
//
//
// Created by Mateusz Ciołkowski on 21/05/2024.
//
#include "typedefs.h"
#include "Client.h"
#include "repository/ClientRepository.h"
#include <boost/test/unit_test.hpp>


namespace btt = boost::test_tools;


BOOST_AUTO_TEST_SUITE()

BOOST_AUTO_TEST_CASE(ClientRepositoryTests)
        {
        ClientRepositoryPtr repository = std::make_shared<ClientRepository>();

        ClientPtr client1 = std::make_shared<Client>("Szymon","Wasiel","2421421",nullptr, nullptr);
        ClientPtr client2 = std::make_shared<Client>("Mateusz","Bodka","45612",nullptr, nullptr);
        ClientPtr client3 = std::make_shared<Client>("Lukasz","Kaminski","897743",nullptr, nullptr);
        ClientPtr client4 = std::make_shared<Client>("Jakub","Witowicz","242583",nullptr, nullptr);
        ClientPtr client5 = std::make_shared<Client>("Michal","Kowalski","22144",nullptr, nullptr);
        BOOST_TEST(repository->size()==0);
            repository->addClient(client1);
            repository->addClient(client2);
            repository->addClient(client3);
            repository->addClient(client4);
            repository->addClient(client5);
        //Nie mozna dodac dwa razy tego samego klienta do repozytorium
        //Client Exception: Nie dodano klienta do repozytorium.
        //repository->addClient(client5);
        BOOST_TEST(repository->size()!=6);
        BOOST_TEST(repository->size()==5);
        BOOST_TEST(repository->size()==4);
        BOOST_TEST(repository->getClient(0) == client1);
        ClientPredicate test = [](const ClientPtr& client) { return client->getFirstName() == "Lukasz"; };
        BOOST_TEST(repository->findBy(test).at(0)==client3);
        BOOST_TEST(repository->findByPESEL("22144")==client5);
        }



BOOST_AUTO_TEST_SUITE_END()
