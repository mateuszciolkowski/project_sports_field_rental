//
// Created by Mateusz Ciołkowski on 21/05/2024.
//

#include "../../include/model/VolleyballField.h"
#include "sstream"
#include "tools/Utilities.h"

VolleyballField::VolleyballField(const std::string &fieldName, double price, unsigned int maxNumberOfPlayers,
                                 volleyballDimensions dimensions, bool sandy) : SportsGround(fieldName, price,
                                                                                             maxNumberOfPlayers),
                                                                                dimensions(dimensions), sandy(sandy) {}

VolleyballField::~VolleyballField() {

}

bool VolleyballField::isSandy() const {
    return sandy;
}

std::string VolleyballField::getInfo() const {
    std::stringstream info;
    std::stringstream info2;
    info2 << "VolleyballField -->  ";
    info << " [ dimensions: " << tools::dimensionsToString(dimensions) << " ] [ sandy: ";
    if (isSandy()) {
        info << " yes ";
    } else {
        info << " no ";
    }
    info << " ] ";
    return info2.str() + SportsGround::getInfo() + info.str();
}

volleyballDimensions VolleyballField::getDimensions() const {
    return dimensions;
}

double VolleyballField::getActualPrice() const {
    double percentage = 0;
    if (!isSandy()) {
        percentage = 0.10;
    }
    return Field::getPrice() * dimensions / 10 + Field::getPrice() * dimensions / 10 * percentage;

}

void VolleyballField::setSandy(bool change) {
    VolleyballField::sandy = change;
}

