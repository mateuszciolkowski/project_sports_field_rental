//
// Created by Mateusz Ciołkowski on 21/05/2024.
//

#include "repository/ClientRepository.h"
#include <algorithm>
#include "Client.h"
#include <sstream>
#include "tools/Exception.h"

ClientRepository::ClientRepository() {
}

ClientRepository::~ClientRepository() {
}

const ClientPtr &ClientRepository::getClient(unsigned int index) const {
    return clients.at(index);
}

bool ClientRepository::addClient(const ClientPtr &client) {
    bool find = false;
    for (const auto &it: clients) {
        if (it == client) {
            find = true;
        }
    }
    if (!find && client != nullptr) {
        clients.push_back(client);
        return true;
    } else {
        throw ClientException("Nie dodano klienta do repozytorium.");
//        return false;
    }
}

bool ClientRepository::removeClient(const ClientPtr &client) {
    bool find = false;
    for (const auto &it: clients) {
        if (it == client) {
            find = true;
        }
    }
    if (find && client != nullptr) {
        auto newEnd = std::remove(clients.begin(), clients.end(), client);
        clients.erase(newEnd, clients.end());
        return true;
    } else {
        throw ClientException("Nie usunieto klienta z repozytorium.");
//        return false;
    }
}

std::string ClientRepository::report(bool fullClientInfo) {
    std::stringstream report;
    for (unsigned int i = 0; i < clients.size(); i++) {
        report << clients[i]->getInfo(fullClientInfo) << std::endl;
    }
    return report.str();
}

unsigned int ClientRepository::size() {
    return clients.size();
}

std::vector<ClientPtr> ClientRepository::findBy(ClientPredicate &predicate) const {
    std::vector<ClientPtr> found;
    for (unsigned int i = 0; i < clients.size(); i++) {
        ClientPtr client = getClient(i);
        if (client != nullptr && predicate(client)) {
            found.push_back(client);
        }
    }
    return found;
}

std::vector<ClientPtr> ClientRepository::findAll() const {
    ClientPredicate test = [](const ClientPtr &) { return true; };
    return findBy(test);
}

ClientPtr ClientRepository::findByPESEL(std::string personalID) const {
    for (const auto &it: clients) {
        if (it->getPesel() == personalID) {
            return it;
        }
    }
    return nullptr;
}
