//
// Created by Mateusz Ciołkowski on 21/05/2024.
//

#include "../../include/model/SportsGround.h"
#include "sstream"

SportsGround::SportsGround(const std::string &fieldName, double price,
                           unsigned int maxNumberOfPlayers) : Field(fieldName, price),
                                                              maxNumberOfPlayers(
                                                                      maxNumberOfPlayers) {}

SportsGround::~SportsGround() {

}


unsigned int SportsGround::getMaxNumberOfPlayers() const {
    return maxNumberOfPlayers;
}

std::string SportsGround::getInfo() const {
    std::stringstream info;
    info << "[ maxNumberOfPlayers: " << getMaxNumberOfPlayers() << " ]";
    return Field::getInfo() + info.str();
}


