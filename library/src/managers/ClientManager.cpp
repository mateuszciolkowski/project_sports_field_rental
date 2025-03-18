//
// Created by Mateusz Ciołkowski on 21/05/2024.
//

#include "managers/ClientManager.h"
#include "repository/ClientRepository.h"
#include "Client.h"
#include "tools/Exception.h"

ClientManager::ClientManager() : clientRepository(new ClientRepository()) {

}

ClientManager::~ClientManager() {

}

ClientPtr ClientManager::getClient(std::string PESEL) {
    return clientRepository->findByPESEL(PESEL);
}

bool ClientManager::registerClient(std::string firstName, std::string lastName, std::string PESEL,
                                   ContactDetailsPtr contactDetails, ClientTypePtr clientType) {

    ClientPtr clientTmp = std::make_shared<Client>(firstName, lastName, PESEL, contactDetails, clientType);

    if (clientRepository->findByPESEL(PESEL) == nullptr) {
        clientRepository->addClient(clientTmp);
        return true;
    } else {
        throw ClientException("Nie zarejestrowano klienta.");
//        return false;
    }
}

bool ClientManager::unregisterClient(std::string PESEL) {
    if (clientRepository->removeClient(clientRepository->findByPESEL(PESEL))) {
        return true;
    } else {
        throw ClientException("Nie wyrejestrowano klienta.");
        return false;
    };
}

std::vector<ClientPtr> ClientManager::findClients(ClientPredicate clientPredicate) {
    return clientRepository->findBy(clientPredicate);
}

std::vector<ClientPtr> ClientManager::findAllClients() {
    return clientRepository->findAll();
}

unsigned int ClientManager::getSize() {
    return clientRepository->size();
}

std::string ClientManager::report(bool fullClientInfo) {
    return clientRepository->report(fullClientInfo);
}
