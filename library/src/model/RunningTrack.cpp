//
// Created by Mateusz Ciołkowski on 21/05/2024.
//

#include "../../include/model/RunningTrack.h"
#include "sstream"

RunningTrack::RunningTrack(const std::string &fieldName, double price, unsigned int maxNumberOfPeople,
                           double trackLength) : Field(fieldName, price), maxNumberOfPeople(maxNumberOfPeople),
                                                 trackLength(trackLength) {}

RunningTrack::~RunningTrack() {

}

unsigned int RunningTrack::getMaxNumberOfPeople() const {
    return maxNumberOfPeople;
}

double RunningTrack::getTrackLength() const {
    return trackLength;
}

std::string RunningTrack::getInfo() const {
    std::stringstream info;
    std::stringstream info2;
    info2 << "Runningtrack -->  ";
    info << " [ maxNumberOfPeople: " << getMaxNumberOfPeople() << " ] [ trackLength: " << getTrackLength() << " ]";
    return info2.str() + Field::getInfo() + info.str();
}

double RunningTrack::getActualPrice() const {
    return Field::getPrice();
}
