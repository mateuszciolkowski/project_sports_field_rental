//
// Created by Mateusz Ciołkowski on 21/05/2024.
//

#include "../../include/model/Field.h"
#include "sstream"

Field::Field(const std::string &fieldName, double price) : fieldName(fieldName), price(price) {}

Field::~Field() {

}

const std::string &Field::getFieldName() const {
    return fieldName;
}

double Field::getPrice() const {
    return price;
}

void Field::setPrice(double price) {
    Field::price = price;
}

std::string Field::getInfo() const {
    std::stringstream info;
    info << "[ fieldName: " << getFieldName() << " ] [ price: " << getPrice() << " ]";
    return info.str();
}
