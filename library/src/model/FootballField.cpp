//
// Created by Mateusz Ciołkowski on 21/05/2024.
//

#include "../../include/model/FootballField.h"
#include "sstream"
#include "tools/Utilities.h"

FootballField::FootballField(const std::string &fieldName, double price, unsigned int maxNumberOfPlayers,
                             footballDimensions dimensions, bool grassy) : SportsGround(fieldName, price,
                                                                                        maxNumberOfPlayers),
                                                                           dimensions(dimensions), grassy(grassy) {}

FootballField::~FootballField() {

}

bool FootballField::isGrassy() const {
    return grassy;
}

std::string FootballField::getInfo() const {
    std::stringstream info;
    std::stringstream info2;
    info2 << "FootballField -->  ";
    info << "[ dimensions: " << tools::dimensionsToString(dimensions) << " ] [ grassy: ";
    if (isGrassy()) {
        info << " yes ";
    } else {
        info << " no ";
    }
    info << " ]";
    return info2.str() + SportsGround::getInfo() + info.str();
}

footballDimensions FootballField::getDimensions() const {
    return dimensions;
}

double FootballField::getActualPrice() const {
    double percentage = 0;
    if (isGrassy()) {
        percentage = 0.15;
    }
    return Field::getPrice() * dimensions / 10 + Field::getPrice() * dimensions / 10 * percentage;
}

void FootballField::setGrassy(bool change) {
    FootballField::grassy = change;
}


