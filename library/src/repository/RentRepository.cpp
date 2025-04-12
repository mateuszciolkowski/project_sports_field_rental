//
// Created by Mateusz Ciołkowski on 21/05/2024.
//

#include "repository/RentRepository.h"
#include "Rent.h"
#include <string>
#include "Client.h"
#include "ClientType.h"
#include "tools/Exception.h"

RentRepository::RentRepository() {

}

RentRepository::~RentRepository() {

}

bool RentRepository::addRent(const RentPtr &rent) {
    bool find = false;
    for (const auto &it: rents) {
        if (it == rent) {
            find = true;
        }
    }
    if (!find && rent != nullptr) {
        rents.push_back(rent);
        return true;
    } else {
        throw RentException("Nie dodano wypozyczenia do repozytorium.");
    }
}

bool RentRepository::removeRent(const RentPtr &rent) {
    bool find = false;
    for (const auto &it: rents) {
        if (it == rent) {
            find = true;
        }
    }
    if (find && rent != nullptr) {
        auto newEnd = std::remove(rents.begin(), rents.end(), rent);
        rents.erase(newEnd, rents.end());
        return true;
    } else {
        throw RentException("Nie usunieto wypozyczenia z repozytorium.");
    }
}

const RentPtr &RentRepository::getRent(unsigned int index) const {
    return rents.at(index);
}

std::string RentRepository::report() {
    std::stringstream report;
    for (const auto &rent: rents) {
        report << rent->getRentInfo() << std::endl << std::endl;
    }
    return report.str();
}

unsigned int RentRepository::getSize() {
    return rents.size();
}

std::vector<RentPtr> RentRepository::findBy(RentPredicate &predicate) const {
    std::vector<RentPtr> found;
    for (unsigned int i = 0; i < rents.size(); i++) {
        RentPtr rent = getRent(i);
        if (rent != nullptr && predicate(rent)) {
            found.push_back(rent);
        }
    }
    return found;
}

std::vector<RentPtr> RentRepository::findAll() const {
    RentPredicate test = [](const RentPtr &) { return true; };
    return findBy(test);
}

RentPtr RentRepository::findByRentID(unsigned int rentID) const {
    for (const auto &it: rents) {
        if (it->getRentId() == rentID) {
            return it;
        }
    }
    return nullptr;
}

void RentRepository::changeToVIP(ClientPtr client) {
    EmployeePtr employee = std::make_shared<Employee>();
    ClientVIPPtr vip = std::make_shared<ClientVIP>();
    double percentOfDiscount = client->getClientType()->getPercentOfDiscount();
    if (percentOfDiscount != vip->getPercentOfDiscount() && percentOfDiscount != employee->getPercentOfDiscount()) {
        client->setClientType(vip);
    }
}
