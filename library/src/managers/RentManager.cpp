//
// Created by Mateusz Ciołkowski on 21/05/2024.
//

#include "managers/RentManager.h"
#include "repository/RentRepository.h"
#include "Rent.h"
#include "typedefs.h"
#include "sstream"
#include "Client.h"
#include "ClientType.h"
#include "tools/Exception.h"

RentManager::RentManager() : archiveRents(new RentRepository()), currentRents(new RentRepository()) {

}

RentManager::~RentManager() {

}

RentPtr RentManager::getFieldRent(const FieldPtr &field) {
    for (const auto &it: currentRents->findAll()) {
        if (it->getField() == field) {
            return it;
        }
    }
    for (const auto &it: archiveRents->findAll()) {
        if (it->getField() == field) {
            return it;
        }
    }
    return nullptr;
}

std::vector<RentPtr> RentManager::getClientRents(const ClientPtr &client, bool archive) {
    std::vector<RentPtr> tmp;
    for (const auto &it: currentRents->findAll()) {
        if (it->getClient() == client) {
            tmp.push_back(it);
        }
    }
    if (archive) {
        for (const auto &it: archiveRents->findAll()) {
            if (it->getClient() == client) {
                tmp.push_back(it);
            }
        }
    }

    return tmp;
}

std::vector<RentPtr> RentManager::findRents(const RentPredicate &rentPredicate) {
//    std::vector<RentPtr> rentsTmp = findCurrentRents(rentPredicate);
//    rentsTmp.insert(rentsTmp.end(), findArchiveRents(rentPredicate).begin(), findArchiveRents(rentPredicate).end());
    std::vector<RentPtr> rentsTmp;
    for (const auto &it: findCurrentRents(rentPredicate)) {
        rentsTmp.push_back(it);
    }
    for (const auto &it: findArchiveRents(rentPredicate)) {
        rentsTmp.push_back(it);
    }
    return rentsTmp;
}

std::vector<RentPtr> RentManager::findArchiveRents(RentPredicate rentPredicate) {
    return archiveRents->findBy(rentPredicate);
}

std::vector<RentPtr> RentManager::findCurrentRents(RentPredicate rentPredicate) {
    return currentRents->findBy(rentPredicate);
}

std::vector<RentPtr> RentManager::findAllRents() {
//    std::vector<RentPtr> rentsTmp = findAllCurrentRents();
//    rentsTmp.insert(rentsTmp.end(), findAllArchiveRents().begin(), findAllArchiveRents().end());
    std::vector<RentPtr> rentsTmp;
    for (const auto &it: findAllCurrentRents()) {
        rentsTmp.push_back(it);
    }
    for (const auto &it: findAllArchiveRents()) {
        rentsTmp.push_back(it);
    }
    return rentsTmp;
}

std::vector<RentPtr> RentManager::findAllCurrentRents() {
    return currentRents->findAll();
}

std::vector<RentPtr> RentManager::findAllArchiveRents() {
    return archiveRents->findAll();
}

RentPtr RentManager::findById(unsigned int id, bool archive) {
    if (archive) {
        return archiveRents->findByRentID(id);
    } else {
        return currentRents->findByRentID(id);
    }
    return nullptr;
}

unsigned int RentManager::checkClientRents(const ClientPtr &client) {
    unsigned int balanceTmp = 0;
    RentPredicate test = [client](const RentPtr &rent) { return rent->getClient() == client; };
    for (const auto &it: findArchiveRents(test)) {
        balanceTmp += it->getRentHours();
    }
    return balanceTmp;
}

bool
RentManager::rentField(const ClientPtr &client, const FieldPtr &field, pt::ptime beginTime, unsigned int rentHours) {
    if (client != nullptr && field != nullptr) {
        for (const auto &it: findAllCurrentRents()) {
            if (it->getField() == field) {
                throw FieldException("Obiekt sportowy jest juz wynajete.");
//                return false;
            }
        }
        incrementCount();
        RentPtr tmp = std::make_shared<Rent>(getCount(), beginTime, rentHours, client, field);
        currentRents->addRent(tmp);
        return true;
    }
    throw FieldException("Obiekt sportowy lub klient to nullptr.");
//    return false;
}

bool RentManager::returnField(FieldPtr field, pt::ptime endTime) {
    RentPredicate test = [field](const RentPtr &rent) { return rent->getField() == field; };
    bool find = false;
    RentPtr tmp;
    for (const auto &it: findCurrentRents(test)) {
        find = true;
        tmp = it;
    }
    if (find) {
        getFieldRent(field)->endRent(endTime);
        archiveRents->addRent(tmp);
        currentRents->removeRent(tmp);
        if (checkClientRents(tmp->getClient()) > 40) {
            archiveRents->changeToVIP(tmp->getClient());
        }
        return true;
    }
    throw RentException("Nie udalo sie wynajac boiska.");
//    return false;
}

std::string RentManager::report() {
    std::stringstream info;
    info << currentReport() << archiveReport();
    return info.str();
}

std::string RentManager::archiveReport() {
    std::stringstream info;
    info << "\nARCHIVE RENTS \n\n";
    if (archiveRents->getSize() == 0) {
        info << "\tBrak archiwalnych wypozyczen\n";
    } else {
        info << archiveRents->report();
    }
    return info.str();
}

std::string RentManager::currentReport() {
    std::stringstream info;
    info << "\nCURRENT RENTS \n\n";
    if (currentRents->getSize() == 0) {
        info << "\tBrak aktualnych wypozyczen\n";
    } else {
        info << currentRents->report();
    }
    return info.str();
}

void RentManager::incrementCount() {
    RentManager::count++;
}

unsigned int RentManager::getCount() const {
    return count;
}
