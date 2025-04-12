//
// Created by Mateusz Ciołkowski on 21/05/2024.
//

#include "Rent.h"
#include <sstream>
#include "Client.h"
#include "Field.h"
#include "ClientType.h"

const ClientPtr &Rent::getClient() const {
    return client;
}

const FieldPtr &Rent::getField() const {
    return field;
}

unsigned int Rent::getRentId() const {
    return rentId;
}

const pt::ptime &Rent::getBeginTime() const {
    return beginTime;
}

const pt::ptime &Rent::getEndTime() const {
    return endTime;
}

double Rent::getRentCost() const {
    return rentCost;
}

unsigned int Rent::getRentHours() const {
    return rentHours;
}

Rent::Rent(unsigned int rentId, pt::ptime beginTime, unsigned int rentHours, ClientPtr client, FieldPtr field)
        : rentId(rentId),
          beginTime(beginTime),
          rentHours(rentHours),
          field(field),
          client(client) {
//    if (rentHours < client->getClientType()->getMaxRentalTime()) {
//        Rent::endTime = beginTime;
//        Rent::beginTime = beginTime;
//    }
    Rent::endTime = pt::not_a_date_time;
    if (beginTime == pt::not_a_date_time) {
        Rent::beginTime = pt::second_clock::local_time();
    } else {
        Rent::beginTime = beginTime;
    }
    rentCost = 0;
    if (rentHours > client->getClientType()->getMaxRentalTime()) {
        Rent::endTime = beginTime;
        Rent::beginTime = beginTime;
    }
}

Rent::~Rent() {

}

std::string Rent::getRentInfo() {
    std::stringstream info;
    info << "Rent --> [ rentId: " << getRentId() << " ] [ rentHours : " << getRentHours() << " ] [ beginTime: "
         << getBeginTime() << " ]";
    if (Rent::endTime != pt::not_a_date_time) {
        info << " [ endTime : " << getEndTime() << " ] ";
    }
    if (Rent::endTime != pt::not_a_date_time) {
        info << " [ rentCost : " << getRentCost() << " ] ";
    }
    if (Rent::client != nullptr) {
        info << "\n \t" << getClient()->getInfo();
    }
    if (Rent::field != nullptr) {
        info << "\n \t" << getField()->getInfo();
    }
    return info.str();
}

void Rent::endRent(pt::ptime endTime) {
    if (Rent::endTime == pt::not_a_date_time) {
        if (endTime != pt::not_a_date_time && beginTime < endTime) {
            Rent::endTime = endTime;
        } else if (beginTime > endTime) {
            Rent::endTime = Rent::beginTime;
        }
        if (endTime == pt::not_a_date_time) {
            if (beginTime < endTime) {
                pt::ptime now = pt::second_clock::local_time();
                Rent::endTime = now;
            } else {
                Rent::endTime = Rent::beginTime;
            }
        }
    }
    //tutaj bedzie wyliczanie kosztow

    pt::time_period period(Rent::beginTime, Rent::endTime);
    if (period.length().hours() * 60 + period.length().minutes() < 5) {
        setRentHours(0);
        setRentCost(0);
        return;
    }
    unsigned int extraTime = 0;
    unsigned int extraHours = 0;
//    if(rentHours*60 <= (period.length().minutes() + period.length().hours()*60)){
//    }
//    else
    if (rentHours * 60 < (period.length().minutes() + period.length().hours() * 60)) {
        extraTime = (period.length().minutes() + period.length().hours() * 60) - rentHours * 60;
        if (extraTime % 60 != 0) {
            extraHours = 1;
        }
        extraHours += static_cast<int>(ceil(extraTime / 60)); ///?
    }

    double tmpPrice = field->getActualPrice() * rentHours + field->getActualPrice() * 2 * extraHours;
    tmpPrice -= client->getClientType()->getPercentOfDiscount() * tmpPrice / 100;
    setRentCost(tmpPrice);
    setRentHours(getRentHours() + extraHours);


}

void Rent::setRentCost(double rentCost) {
    Rent::rentCost = rentCost;
}

void Rent::setRentHours(unsigned int rentHours) {
    Rent::rentHours = rentHours;
}



