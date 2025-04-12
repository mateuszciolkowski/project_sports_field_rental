//
// Created by Mateusz Ciołkowski on 21/05/2024.
//

#include "ClientType.h"
#include <sstream>

ClientType::ClientType() {

}

ClientType::~ClientType() {

}

std::string ClientType::getInfo() {
    std::stringstream info;
    info << "ClientType --> ";
    return info.str();
}

Employee::Employee() : ClientType() {
    percentOfDiscount = 80;
    maxRentalTime = 5;
}

Employee::~Employee() {

}

std::string Employee::getInfo() {
    std::stringstream info;
    info << ClientType::getInfo() << " Employee [ percentOfDiscount :  " << getPercentOfDiscount()
         << " ] [ maxRentalTime: " << getMaxRentalTime() << " ] ";
    return info.str();
}

unsigned int Employee::getMaxRentalTime() {
    return maxRentalTime;
}

unsigned int Employee::getPercentOfDiscount() {
    return percentOfDiscount;
}

ClientNormal::ClientNormal() : ClientType() {
    percentOfDiscount = 0;
    maxRentalTime = 2;
}

ClientNormal::~ClientNormal() {

}

std::string ClientNormal::getInfo() {
    std::stringstream info;
    info << ClientType::getInfo() << " ClientNormal [ percentOfDiscount :  " << getPercentOfDiscount()
         << " ] [ maxRentalTime: " << getMaxRentalTime() << " ] ";
    return info.str();
}

unsigned int ClientNormal::getMaxRentalTime() {
    return maxRentalTime;
}

unsigned int ClientNormal::getPercentOfDiscount() {
    return percentOfDiscount;
}

ClientVIP::ClientVIP() : ClientType() {
    percentOfDiscount = 40;
    maxRentalTime = 4;
}

ClientVIP::~ClientVIP() {

}

std::string ClientVIP::getInfo() {
    std::stringstream info;
    info << ClientType::getInfo() << " ClientVIP [ percentOfDiscount :  " << getPercentOfDiscount()
         << " ] [ maxRentalTime: " << getMaxRentalTime() << " ] ";
    return info.str();
}

unsigned int ClientVIP::getMaxRentalTime() {
    return maxRentalTime;
}

unsigned int ClientVIP::getPercentOfDiscount() {
    return percentOfDiscount;
}
