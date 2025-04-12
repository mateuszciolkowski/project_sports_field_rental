//
// Created by Mateusz on 12/06/2024.
//

#include "tools/Exception.h"



Exceptions::Exceptions(const std::string &message) : std::runtime_error(message) {}


InvalidInputException::InvalidInputException(const std::string &message) : Exceptions("Invalid Input: " + message) {}


ClientException::ClientException(const std::string &message) : Exceptions("Client Exception: " + message) {}

FieldException::FieldException(const std::string &message) : Exceptions("Field Exception: " + message) {}

RentException::RentException(const std::string &message) : Exceptions("Rent Exception: " + message) {}


