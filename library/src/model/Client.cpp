//
// Created by Mateusz Ciołkowski on 21/05/2024.
//

#include "Client.h"
#include <sstream>
#include <utility>
#include "ContactDetails.h"
#include "ClientType.h"


const std::string &Client::getFirstName() const {
    return firstName;
}

const std::string &Client::getLastName() const {
    return lastName;
}


const std::string &Client::getPesel() const {
    return PESEL;
}


const ContactDetailsPtr &Client::getContactDetails() const {
    return contactDetails;
}

void Client::setContactDetails(const ContactDetailsPtr &contactDetails) {
    Client::contactDetails = contactDetails;
}

const ClientTypePtr &Client::getClientType() const {
    return clientType;
}

void Client::setClientType(const ClientTypePtr &clientType) {
    Client::clientType = clientType;
}

void Client::setFirstName(const std::string &firstName) {
    Client::firstName = firstName;
}

void Client::setLastName(const std::string &lastName) {
    Client::lastName = lastName;
}

Client::Client(std::string firstName, std::string lastName, std::string PESEL, ContactDetailsPtr contactDetails,
               ClientTypePtr clientType) :
        firstName(std::move(firstName)),
        lastName(std::move(lastName)),
        PESEL(std::move(PESEL)),
        contactDetails(std::move(contactDetails)),
        clientType(clientType ? clientType : std::make_shared<ClientNormal>()) {
}

Client::~Client() {

}

std::string Client::getInfo(bool fullInfo) {
    std::stringstream info;
    info << "Client --> [ firstName: " << getFirstName() << " ] [ lastName: " << getLastName() << " ] [ PESEL: "
         << getPesel() << " ] ";
    if (fullInfo) {
        if (contactDetails != nullptr) {
            info << std::endl << "\t" << contactDetails->getContactDetailsInfo();
        }
        if (clientType != nullptr) {
            info << std::endl << "\t" << clientType->getInfo();
        }
    }
    return info.str();
}
