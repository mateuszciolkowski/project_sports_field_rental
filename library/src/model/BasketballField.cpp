//
// Created by Mateusz Ciołkowski on 21/05/2024.
//

#include "../../include/model/BasketballField.h"
#include "sstream"
#include "tools/Utilities.h"

BasketballField::BasketballField(const std::string &fieldName, double price, unsigned int maxNumberOfPlayers,
                                 basketballDimensions dimensions, bool covered) : SportsGround(fieldName, price,
                                                                                               maxNumberOfPlayers),
                                                                                  dimensions(dimensions),
                                                                                  covered(covered) {}

BasketballField::~BasketballField() {

}

bool BasketballField::isCovered() const {
    return covered;
}

std::string BasketballField::getInfo() const {
    std::stringstream info;
    std::stringstream info2;
    info2 << "BasketballField -->  ";
    info << "[ dimensions: " << tools::dimensionsToString(dimensions) << " ] [ covered: ";
    if (isCovered()) {
        info << " yes ";
    } else {
        info << " no ";
    }
    info << " ]";
    return info2.str() + SportsGround::getInfo() + info.str();
}

basketballDimensions BasketballField::getDimensions() const {
    return dimensions;
}

double BasketballField::getActualPrice() const {
    double percentage = 0;
    if (isCovered()) {
        percentage = 0.25;
    }
    return Field::getPrice() * dimensions / 10 + Field::getPrice() * dimensions / 10 * percentage;
}

void BasketballField::setCovered(bool change) {
    BasketballField::covered = change;
}


