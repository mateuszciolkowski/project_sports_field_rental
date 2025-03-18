//
// Created by Mateusz Ciołkowski on 21/05/2024.
//

#include "ContactDetails.h"
#include <sstream>

ContactDetails::ContactDetails(const std::string &phoneNumber, const std::string &email, const std::string &street,
                               const std::string &city, const std::string &houseNumber) : phoneNumber(phoneNumber),
                                                                                          email(email), street(street),
                                                                                          city(city),
                                                                                          houseNumber(houseNumber) {}

ContactDetails::~ContactDetails() {

}

std::string ContactDetails::getContactDetailsInfo() const {
    std::stringstream info;
    info << "ContactDetails --> [ phoneNumber: " << getPhoneNumber() << " ] [ email: " << getEmail() << " ] [ street: "
         << getStreet() << " ] [ city: " << getCity() << " ] [ houseNumber: " << getHouseNumber() << " ] ";
    return info.str();
}


const std::string &ContactDetails::getPhoneNumber() const {
    return phoneNumber;
}

void ContactDetails::setPhoneNumber(const std::string &phoneNumber) {
    ContactDetails::phoneNumber = phoneNumber;
}

const std::string &ContactDetails::getEmail() const {
    return email;
}

void ContactDetails::setEmail(const std::string &email) {
    ContactDetails::email = email;
}

const std::string &ContactDetails::getStreet() const {
    return street;
}

void ContactDetails::setStreet(const std::string &street) {
    ContactDetails::street = street;
}

const std::string &ContactDetails::getCity() const {
    return city;
}

void ContactDetails::setCity(const std::string &city) {
    ContactDetails::city = city;
}

const std::string &ContactDetails::getHouseNumber() const {
    return houseNumber;
}

void ContactDetails::setHouseNumber(const std::string &houseNumber) {
    ContactDetails::houseNumber = houseNumber;
}
